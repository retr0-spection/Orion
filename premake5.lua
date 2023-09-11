workspace "Orion"
    architecture "arm64"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

cppdialect "C++20"


includeDir = {}
includeDir['GLFW'] = "Orion/vendor/GLFW/include"
include "Orion/vendor/GLFW"

project "Orion"
    location "Orion"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "src/oripch.hpp"
    pchsource "Orion/src/oripch.hpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
    }

    externalincludedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{includeDir.GLFW}"
    }

    links {
        "GLFW",
        "OpenGL.framework",
        "Cocoa.framework",
        "IOKit.framework",
        "CoreVideo.framework",

    }

    filter "system:Mac"
        staticruntime "On"
        systemversion "latest"


        defines
        {
            "ORI_BUILD_DLL",
            "DEBUG",
            "ORI_PLATFORM_MAC"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Release"
        defines 
        {
            "ORI_BUILD_DLL",
            "ORI_PLATFORM_MAC",
            "ORI_RELEASE"

        }
        symbols "On"

    filter "configurations:Debug"
        defines 
        {
            "ORI_BUILD_DLL",
            "DEBUG",
            "ORI_PLATFORM_MAC",
            "ORI_DEBUG",

        }
        symbols "On"

    filter "configurations:Dist"
        defines 
        {
            "ORI_BUILD_DLL",
            "DEBUG",
            "ORI_PLATFORM_MAC",
            "ORI_DIST"
        }
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp",
    }

    externalincludedirs
    {
        "Orion/vendor/spdlog/include",
        "Orion/src",
        
    }

    links
    {
        "Orion"
    }

    filter "system:Mac"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DEBUG",
            "ORI_PLATFORM_MAC"
        }


    filter "configurations:Release"
        defines
        {
            "ORI_PLATFORM_MAC",
            "ORI_RELEASE"
        }
        symbols "On"

    filter "configurations:Debug"
        defines 
        {
            "DEBUG",
            "ORI_PLATFORM_MAC",
            "ORI_DEBUG"
        }
        symbols "On"

    filter "configurations:Dist"
        defines 
        {
            "ORI_PLATFORM_MAC",
            "ORI_DIST"
        }
        optimize "On"
        
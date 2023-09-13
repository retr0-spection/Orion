#include "oripch.hpp"
#include "ImGuiLayer.hpp"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.hpp"
#include "GLFW/glfw3.h"
#include "Orion/Application.hpp"

namespace Orion {
    
    ImGuiLayer::ImGuiLayer()
    {
     
    }

    ImGuiLayer::~ImGuiLayer()
    {
        
        
    }

    void ImGuiLayer::OnAttach()
    {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        
        
        ImGuiIO& io = ImGui::GetIO();
//        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
//        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        
        
        //TEMPORARY USE ORION KEY CODES
        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;
        
        
        ImGui_ImplOpenGL3_Init("#version 410");
   
    }

    void ImGuiLayer::OnDetach()
    {
        
    }

    void ImGuiLayer::OnUpdate()
    {
      
        IMGUI_IMPL_API::
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());
        
        
        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f  / 60.0f);
        m_Time = time;
        
        ImGui_ImplOpenGL3_NewFrame();

 
        ImGui::NewFrame();
        
        static bool show = true;
        ImGui::ShowDemoWindow(&show);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<MouseButtonPressedEvent>(ORI_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
        dispatcher.Dispatch<MouseButtonReleasedEvent>(ORI_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
        dispatcher.Dispatch<MouseMovedEvent>(ORI_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
        dispatcher.Dispatch<MouseScrolledEvent>(ORI_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
        dispatcher.Dispatch<KeyPressedEvent>(ORI_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
        dispatcher.Dispatch<KeyReleasedEvent>(ORI_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
        dispatcher.Dispatch<WindowResizeEvent>(ORI_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
        
    }

    
    bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
//        io.MouseDown[e.GetMouseButton()] = true;
        io.AddMouseButtonEvent(e.GetMouseButton(), true);
        
        return false;
    }

    bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
//        io.MouseDown[e.GetMouseButton()] = false;
        io.AddMouseButtonEvent(e.GetMouseButton(), false);
        return false;
    }

    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.AddMousePosEvent(e.GetX(), e.GetY());
       
        
        return false;
    }

    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
       
//        io.MouseWheelH += e.GetXOffset();
//        io.MouseWheel += e.GetYOffset();
        io.AddMouseWheelEvent(e.GetXOffset(), e.GetYOffset());
        
        return false;
    }

    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
    {
        return false;
    }
    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
    {
        return false;
    }
    //   ImGuiLayer::     bool OnKeyTypedEvent(KeyTypedEvent& e);
    bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
    {
        
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
        io.DisplayFramebufferScale = ImVec2(2.0f, 2.0f);
        glViewport(0,0, e.GetWidth(), e.GetHeight());

        return false;
    }

    
}

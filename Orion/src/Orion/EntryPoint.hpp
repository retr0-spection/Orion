#pragma once

#ifdef ORI_PLATFORM_MAC

extern Orion::Application* Orion::CreateApplication();

int main(int argc, char** argv)
{
    Orion::Log::Init();
    ORI_CORE_WARN("Initialized Log");
    ORI_INFO("Hello"); 
    auto app = Orion::CreateApplication();
    app->Run();
    delete app;
    
    return 0;
}


#endif

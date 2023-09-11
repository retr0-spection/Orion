#pragma once
#include "Core.hpp"
#include "Events/Event.hpp"
#include "Window.hpp"



namespace Orion {
    class Application
    {
    public:
        Application();
        virtual ~Application();
        
        void Run();
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    
    };
    
    // to be defined in client
    Application* CreateApplication();
}


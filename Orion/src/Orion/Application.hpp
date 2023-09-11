#pragma once
#include "Core.hpp"
#include "Orion/Events/Event.hpp"
#include "Orion/Events/ApplicationEvent.hpp"
#include "Window.hpp"



namespace Orion {
    class Application
    {
    public:
        Application();
        virtual ~Application();
        
        void Run();
        
        void OnEvent(Event& e);
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    
    };
    
    // to be defined in client
    Application* CreateApplication();
}


#pragma once
#include "Core.hpp"
#include "Orion/Events/Event.hpp"
#include "Orion/LayerStack.hpp"
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
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        
        inline static Application& Get() { return *s_Instance; }
        inline Window&  GetWindow() { return *m_Window; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
        
    private:
        static Application* s_Instance;
    
    };
    
    // to be defined in client
    Application* CreateApplication();
}


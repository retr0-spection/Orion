#include "oripch.hpp"
#include "Application.hpp"
#include "Orion/Events/ApplicationEvent.hpp"
#include "Orion/Log.hpp"


namespace Orion {
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
        
    }

    void Application::Run()
    {
        while (m_Running){
            m_Window->OnUpdate();
        }
    }


}

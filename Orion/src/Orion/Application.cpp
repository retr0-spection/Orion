#include "oripch.hpp"
#include "Application.hpp"
#include "Orion/Log.hpp"


namespace Orion {

#define BIND_EVENT_FN(x) std::bind(&Application:: x, this, std::placeholders::_1)

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {
        
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
        ORI_CORE_INFO("{0}", e);
    }

    void Application::Run()
    {
        while (m_Running){
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }


}

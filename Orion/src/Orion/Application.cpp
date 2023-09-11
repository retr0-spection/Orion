#include "oripch.hpp"
#include "Application.hpp"
#include "Orion/Events/ApplicationEvent.hpp"
#include "Orion/Log.hpp"

namespace Orion {
    Application::Application()
    {
        
    }

    Application::~Application()
    {
        
    }

    void Application::Run()
    {
        WindowResizeEvent e(1200, 700);
        if (e.IsInCategory(EventCategoryApplication)){
            ORI_TRACE(e);
        }
        if (e.IsInCategory(EventCategoryInput)){
            ORI_TRACE(e);
        }

        while (true);
    }


}

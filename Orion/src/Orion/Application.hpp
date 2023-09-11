#pragma once


namespace Orion {
    class Application
    {
    public:
        Application();
        virtual ~Application();
        
        void Run();
    
    };
    
    // to be defined in client
    Application* CreateApplication();
}


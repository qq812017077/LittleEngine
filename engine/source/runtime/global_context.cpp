#include "runtime/global_context.h"
#include "core/log/log_system.h"
#include "runtime/engine.h"

namespace LittleEngine
{
    void RuntimeGlobalContext::startSystems(const std::string& config_file_path)
    {      
        m_logger_system = std::make_shared<LogSystem>();
        m_window_system = std::make_shared<WindowSystem>();
        
        WindowCreateInfo window_create_info;
        m_window_system->initialize(window_create_info);
    }

    void RuntimeGlobalContext::shutdownSystems()
    {
        m_window_system.reset();
        m_logger_system.reset();
    }
} // namespace LittleEngine
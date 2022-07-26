#pragma once

#include <memory>
#include <string>
#include "runtime/function/render/window_system.h"
#include "core/log/log_system.h"

namespace LittleEngine
{
    /// Manage the lifetime and creation/destruction order of all global system
    class RuntimeGlobalContext
    {
    public:
        // create all global systems and initialize these systems
        void startSystems(const std::string& config_file_path);
        
        // destroy all global systems
        void shutdownSystems();

    public:
        std::shared_ptr<LogSystem>      m_logger_system;
        std::shared_ptr<WindowSystem>   m_window_system;
    };
} // namespace LittleEngine
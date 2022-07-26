#pragma once

#include <atomic>
#include <chrono>
#include <filesystem>
#include <string>
#include <unordered_set>
#include "runtime/global_context.h"

namespace LittleEngine
{
    extern bool                             g_is_editor_mode;
    extern std::unordered_set<std::string>  g_editor_tick_component_types;
    extern RuntimeGlobalContext             g_runtime_global_context;

    /// <summary>
    /// 为LittleEditor提供背后的功能逻辑支撑
    /// </summary>
    class Engine
    {
        friend class Editor;
        static const float k_fps_alpha;

    public:
        void startEngine(const std::string& config_file_path);
        void shutdownEngine();

        void initialize();
        void clear();

        bool isQuit() const { return m_is_quit; }
        void run();
        bool tickOneFrame(float delta_time);

        int getFPS() const { return m_fps; }

    protected:
        void logicalTick(float delta_time);
        bool rendererTick();

        void calculateFPS(float delta_time);

        /**
         *  Each frame can only be called once
         */
        float calculateDeltaTime();

    protected:
        bool m_is_quit {false};
        
        float m_average_duration{ 0.f };
        int m_frame_count{ 0 };
        int m_fps{ 0 };
    };

    
} // namespace Piccolo

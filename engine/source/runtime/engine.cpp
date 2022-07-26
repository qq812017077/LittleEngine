#include "runtime/engine.h"


namespace LittleEngine
{
    bool                            g_is_editor_mode {false};
    std::unordered_set<std::string> g_editor_tick_component_types;
    RuntimeGlobalContext g_runtime_global_context;

    /// <summary>
    /// 启动引擎
    /// </summary>
    /// <param name="config_file_path"></param>
    void Engine::startEngine(const std::string& config_file_path)
    {
        g_runtime_global_context.startSystems(config_file_path);
    }

    void Engine::shutdownEngine()
    {

    }

    void Engine::initialize()
    {

    }

    void Engine::clear()
    {
        
    }


    void Engine::run()
    {

    }

    /// <summary>
    /// 每帧的工作逻辑
    /// </summary>
    /// <param name="delta_time"></param>
    /// <returns></returns>
    bool Engine::tickOneFrame(float delta_time)
    {
        logicalTick(delta_time);
        calculateFPS(delta_time);
        
        rendererTick();
        
        return !g_runtime_global_context.m_window_system->shouldClose();
    }



    void Engine::logicalTick(float delta_time)
    {
        /*g_runtime_global_context.m_world_manager->tick(delta_time);
        g_runtime_global_context.m_input_system->tick();*/
    }

    bool Engine::rendererTick()
    {
        //g_runtime_global_context.m_render_system->tick();
        return true;
    }

    const float Engine::k_fps_alpha = 1.f / 100;
    void        Engine::calculateFPS(float delta_time)
    {
        m_frame_count++;

        if (m_frame_count == 1)
        {
            m_average_duration = delta_time;
        }
        else
        {
            m_average_duration = m_average_duration * (1 - k_fps_alpha) + delta_time * k_fps_alpha;
        }

        m_fps = static_cast<int>(1.f / m_average_duration);
    }

} // namespace LittleEngine

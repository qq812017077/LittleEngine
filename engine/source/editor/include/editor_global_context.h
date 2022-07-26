#pragma once

namespace LittleEngine
{
    class EditorGlobalContext
    {
        public:
        void initialize(Engine * engine_runtime, WindowSystem*       window_system)
        {
            m_engine_runtime = engine_runtime;
            m_window_system = window_system;
        }
        void clear()
        {
            
        }
        public:
        // class EditorSceneManager* m_scene_manager {nullptr};
        // class EditorInputManager* m_input_manager {nullptr};
        // class RenderSystem*       m_render_system {nullptr};
        class Engine*               m_engine_runtime {nullptr};
        class WindowSystem*         m_window_system {nullptr};
    };
}
#include "editor/include/editor.h"
#include "runtime/engine.h"
#include "core/macro.h"

namespace LittleEngine
{
	EditorGlobalContext g_editor_global_context;
	Editor::Editor()
	{
		
	};

	Editor::~Editor()
	{

	};

	void Editor::initialize(Engine* engine_runtime)
	{
		assert(engine_runtime);
		m_engine_runtime = engine_runtime;
		g_editor_global_context.initialize(engine_runtime,g_runtime_global_context.m_window_system.get());
		m_editor_ui                   = std::make_shared<EditorUI>();
		WindowUIInitInfo ui_initInfo;
		ui_initInfo = {g_runtime_global_context.m_window_system};
		m_editor_ui->initialize(ui_initInfo);
	};

	void Editor::clear()
	{

	};

	void Editor::run()
	{
		assert(m_engine_runtime);
        assert(m_editor_ui);
		float delta_time;
		while (true)
        {
            delta_time = m_engine_runtime->calculateDeltaTime();
            // g_editor_global_context.m_scene_manager->tick(delta_time);
            // g_editor_global_context.m_input_manager->tick(delta_time);
            if (!m_engine_runtime->tickOneFrame(delta_time))
                return;
        }
	};
}
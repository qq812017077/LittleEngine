#pragma once

#include <memory>
#include "editor_ui.h"
#include "editor_global_context.h"
namespace LittleEngine
{
    class Engine;
    extern EditorGlobalContext g_editor_global_context;
    
    class Editor
    {
        friend class EditorUI;// can access private variables of EditorUI
    public:
        Editor();
        virtual ~Editor();
        void initialize(Engine* engine);
        void clear();

        void run();
    protected:
        std::shared_ptr<EditorUI> m_editor_ui;
        Engine* m_engine_runtime{ nullptr };
    };
}
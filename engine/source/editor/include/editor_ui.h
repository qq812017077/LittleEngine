#pragma once

#include <chrono>
#include <map>
#include <vector>
#include "runtime/function/ui/window_ui.h"

namespace LittleEngine
{
    class WindowSystem;
    // class RenderSystem;

    class EditorUI : public WindowUI
    {
        public:
            virtual void initialize(WindowUIInitInfo init_info) override final;
            virtual void preRender() override final;

        public:
            EditorUI();
            ~EditorUI();

        

        private:
            void showEditorUI();
            // void showEditorMenu(bool* p_open);
            // void showEditorWorldObjectsWindow(bool* p_open);
            // void showEditorFileContentWindow(bool* p_open);
            // void showEditorGameWindow(bool* p_open);
            // void showEditorDetailWindow(bool* p_open);
    };
}
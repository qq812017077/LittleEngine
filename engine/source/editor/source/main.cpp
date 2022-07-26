#include <filesystem>
#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>

#include "runtime/engine.h"
#include "editor/include/editor.h"

int main(int argc, char** argv)
{
    std::filesystem::path executable_path(argv[0]);
    std::filesystem::path config_file_path = executable_path.parent_path() / "LittleEngineEditor.ini";
    //std::cout << config_file_path.string();

    LittleEngine::Engine * engine = new LittleEngine::Engine();
    engine->initialize();

    LittleEngine::Editor* editor = new LittleEngine::Editor();
    editor->initialize(engine);

    editor->run();

    editor->clear();
    engine->clear();
    engine->shutdownEngine();
    delete editor;
    delete engine;

}
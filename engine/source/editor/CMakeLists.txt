set(TARGET_NAME LittleEngineEditor)

#GLOB: collect target files to variables(EDITOR_HEADERS, EDITOR_SOURCES, EDITOR_RESOURCE) 
file(GLOB EDITOR_HEADERS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB EDITOR_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB EDITOR_RESOURCE CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/resource/Editor.rc)

#source_group: Define a grouping for source files in IDE project generation 
#         (to set up file tabs in Visual Studio)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${EDITOR_HEADERS} ${EDITOR_SOURCES} ${EDITOR_RESOURCE})

# Adds an executable target called <TARGET_NAME> by using specific source files
add_executable(${TARGET_NAME} ${EDITOR_HEADERS} ${EDITOR_SOURCES} ${EDITOR_RESOURCE})

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17 OUTPUT_NAME "LittleEngineEditor")
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "Engine")

target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")

target_link_libraries(${TARGET_NAME} LittleEngineRuntime)

set(POST_BUILD_COMMANDS
  COMMAND ${CMAKE_COMMAND} -E copy "${ENGINE_ROOT_DIR}/${DEVELOP_CONFIG_DIR}/${TARGET_NAME}.ini" "$<TARGET_FILE_DIR:${TARGET_NAME}>/"
)

#execute command
add_custom_command(TARGET ${TARGET_NAME} ${POST_BUILD_COMMANDS})
#precompile
#set global vari used by precompile
set(EDITOR_HEADS “${EDITOR_HEADERS}” PARENT_SCOPE)

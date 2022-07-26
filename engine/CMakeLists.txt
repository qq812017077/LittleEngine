
set(ENGINE_ROOT_DIR "${LITTLEENGINE_ROOT_DIR}/engine")
set(ENGINE_ASSET_DIR "${ENGINE_ROOT_DIR}/assets")
set(THIRD_PARTY_DIR "${ENGINE_ROOT_DIR}/3rdparty")

set(DEPLOY_CONFIG_DIR "configs/deployment")
set(DEVELOP_CONFIG_DIR "configs/development")

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/MP")
    set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT LittleEngineEditor)
endif()

set(vulkan_include ${THIRD_PARTY_DIR}/VulkanSDK/include)

if(WIN32)
    set(vulkan_lib ${THIRD_PARTY_DIR}/VulkanSDK/lib/Win32/vulkan-1.lib)
    set(glslangValidator_executable ${THIRD_PARTY_DIR}/VulkanSDK/bin/Win32/glslangValidator.exe)
    add_compile_definitions("ENGINE_VK_LAYER_PATH=${THIRD_PARTY_DIR}/VulkanSDK/bin/Win32")
else()
  message(FATAL_ERROR "NOTE:: Only Support Win Platform")
endif()

add_subdirectory(3rdparty)
add_subdirectory(source/runtime)
add_subdirectory(source/editor)

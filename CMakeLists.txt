cmake_minimum_required(VERSION 3.10)
project(HW_Controller_UI)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set source and include directories for your project files only
set(SOURCE_DIR src)
set(INCLUDE_DIR include)



include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()




# GLFW configuration (unchanged)
set(GLFW_DIR ${CMAKE_SOURCE_DIR}/glfw-3.4.bin.WIN64)
set(NPCAP_DIR ${CMAKE_SOURCE_DIR}/npcap)



list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}")
find_package(yaml-cpp REQUIRED)


# Add GLFW library directory (unchanged)
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    link_directories(${GLFW_DIR}/lib-vc2022)
    set(GLFW_LIBRARY ${GLFW_DIR}/lib-vc2022/glfw3.lib)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    link_directories(${GLFW_DIR}/lib-mingw-w64)
    set(GLFW_LIBRARY ${GLFW_DIR}/lib-mingw-w64/libglfw3.a)
endif()

# Find OpenGL (unchanged)
find_package(OpenGL REQUIRED)
# Dear ImGui configuration (unchanged)
set(IMGUI_SOURCES
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp
)

# Include directories (updated for your headers, unchanged for libraries)
include_directories(
    ${INCLUDE_DIR}               # Your project headers
    imgui imgui/backends         # Unchanged
    ${CMAKE_SOURCE_DIR}/vcpkg/spdlog-1.11.0/include  # Unchanged
    implot                       # Unchanged
    ImGuiFileDialog              # Unchanged
    ${CMAKE_SOURCE_DIR}/driver/include
    "${GLFW_DIR}/include"
    "${NPCAP_DIR}/include"
)
link_directories(${NPCAP_DIR}/Lib/x64)

# ImPlot configuration (unchanged)
set(IMPLOT_SOURCES
    implot/implot.cpp
    implot/implot_items.cpp
)

# ImGuiFileDialog configuration (unchanged)
set(IMGUI_FILE_DIALOG_SOURCES
    ImGuiFileDialog/ImGuiFileDialog.cpp
)

# Project source files - updated to point to src/ directory
set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/BTSRevoDevice.cpp
    ${SOURCE_DIR}/CaptureModuleDevice.cpp
    ${SOURCE_DIR}/GUI.cpp
    ${SOURCE_DIR}/BTSRevoGUI.cpp
    ${SOURCE_DIR}/Themes.cpp
    ${SOURCE_DIR}/Logging.cpp
    ${SOURCE_DIR}/DeviceFactory.cpp
    ${SOURCE_DIR}/CANCaptureModuleDevice.cpp
    ${SOURCE_DIR}/LINCaptureModuleDevice.cpp
    ${SOURCE_DIR}/GenericScriptGUI.cpp
    ${SOURCE_DIR}/GenericScriptBackend.cpp
    ${SOURCE_DIR}/legacygui.cpp
)

# Add executable
add_executable(HW_Controller_UI ${SOURCES} ${IMGUI_SOURCES} ${IMPLOT_SOURCES} ${IMGUI_FILE_DIALOG_SOURCES})

# Link libraries (unchanged)
target_link_libraries(HW_Controller_UI 
    ${GLFW_LIBRARY} 
    ${OPENGL_LIBRARIES}
    yaml-cpp::yaml-cpp
    wpcap Packet
    wpcap.lib
    Packet.lib
    Ws2_32.lib  
    Iphlpapi.lib 
    ${CMAKE_SOURCE_DIR}/build/Debug/TE-DriverBase.lib
)
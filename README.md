🚀 HW_Controller_UI – TECMP Hardware GUI
A GUI application for controlling and monitoring hardware modules in the TECMP platform. Built in C++ using ImGui, ImPlot, and custom modules. Dependency management is handled by Conan, with vcpkg used only for yaml-cpp.

📁 Cloning the Project
bash
Copier
Modifier
git clone https://github.com/Hadir-bahloul/Final_TECMP_
cd Final_TECMP_
📦 Step 1: Set Up vcpkg (for yaml-cpp only)
bash
Copier
Modifier
# Clone vcpkg
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg

# Bootstrap vcpkg
.\bootstrap-vcpkg.bat

# Integrate with your system
.\vcpkg integrate install

# Install only yaml-cpp (required by the GUI project)
.\vcpkg install yaml-cpp:x64-windows
cd ..
🏗️ Step 3: Configure and Build with CMake
bash
Copier
Modifier
# Create the build directory
mkdir build
cd build

# Run CMake with toolchain file for vcpkg (yaml-cpp)
cmake .. ^
  -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake ^
  -DVCPKG_TARGET_TRIPLET=x64-windows ^
  -Dyaml-cpp_DIR=../vcpkg/installed/x64-windows/share/yaml-cpp ^
  -DCMAKE_BUILD_TYPE=RelWithDebInfo

# Build the executable
cmake --build . --config RelWithDebInfo

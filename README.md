git clone https://github.com/Hadir-bahloul/Final_TECMP_/new/master?filename=README.md
cd HW_Controller_UI
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install
.\vcpkg install yaml-cpp:x64-windows spdlog:x64-windows
cd ..
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows -Dyaml-cpp_DIR=../vcpkg/installed/x64-windows/share/yaml-cpp
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build . --config RelWithDebInfo 

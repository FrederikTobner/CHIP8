ECHO Configuring CMake ...
cmake -B ../build -DCMAKE_BUILD_TYPE=Release ..
ECHO Building CHIP-8 ...
cmake --build ../build --config Release --target CHIP-8
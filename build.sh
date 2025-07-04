mkdir -p build-powermac
cd build-powermac
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=$RETRO68_SOURCE_PATH/cmake/retroppc.toolchain.cmake.in &&
make 
mkdir -p build-powermac
cd build-powermac
cmake .. -DRETRO68_ROOT=$RETRO68_TOOLCHAIN_PATH -DPLATFORM=retroppc -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=$RETRO68_SOURCE_PATH/cmake/retroppc.toolchain.cmake.in -DBUILD_EXAMPLES=ON &&
make 
 
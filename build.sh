mkdir -p build-powermac
cd build-powermac
cmake .. -DCMAKE_BUILD_TYPE=Release -DPLATFORM=retroppc -DRETRO68_ROOT=$RETRO68_TOOLCHAIN_PATH -DCMAKE_TOOLCHAIN_FILE=$RETRO68_INSTALL_PATH/cmake/retroppc.toolchain.cmake.in &&
make -j$(nproc)
# PowerGLFW

PowerGLFW is a (WIP) reimplementation of GLFW for Mac OS 8-9.

![image](https://github.com/user-attachments/assets/f0b83d0d-d712-483b-8660-d8ba3dea8b17)

The wording is important: It is a reimplementation, not a port. There are things done that wouldn't be done in upstream GLFW, there are features missing, and new bugs. Notably:

- No Vulkan support
- Gamepad functions are dummied out, to be implemented at some point in the future if I want to.
- It is not currently thread safe.
- Getting the proc address with `glfwGetProcAddress` isn't a thing yet.

Also of note:

- `GLFW_PLATFORM_MACOS9` is used in functions for testing the platform support

# Building

This relies on [Retro68](https://github.com/autc04/Retro68). PRs are welcome to get it running under alternate compilers like Metroworks or MPW.

The cmake script expects to be called with the environment variable `RETRO68_TOOLCHAIN_PATH` set to your Retro68 toolchain, i.e. `/opt/Retro68/toolchain/`. You also need to use the `CMAKE_TOOLCHAIN_FILE` option to direct cmake to the `retroppc.toolchain.cmake.in` file in your Retro68 install.

The `build.sh` file automates all this for you; if you use it, you'll additionally need to set `RETRO68_SOURCE_PATH` to the path of wherever you cloned the Retro68 repo.

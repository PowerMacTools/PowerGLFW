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

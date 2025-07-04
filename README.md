# PowerGLFW

PowerGLFW is a (WIP) reimplementation of GLFW for Mac OS 8-9.

<picture would go here>

The wording is important: It is a reimplementation, not a port. There are things done that wouldn't be done in upstream GLFW, there are features missing, and new bugs. Notably:

- No Vulkan support
- Gamepad functions are dummied out, to be implemented at some point in the future if I want to.
- It is not currently thread safe.
- Getting the proc address with `glfwGetProcAddress` isn't a thing yet.

Also of note:

- `GLFW_PLATFORM_MACOS9` is used in functions for testing the platform support
- Due to how MacOS's event loop works and its incompatibility with GLFW, currently extra functions are required on MacOS: `glfwMacWindowBegin`, and `glfwMacWindowEnd`. You can query the `GLFW_EXTRA_MAC_FUNCTIONS` definition to find out if they're present.

```c
while (!glfwWindowShouldClose(window)) {

#ifdef GLFW_EXTRA_MAC_FUNCTIONS
    glfwMacWindowBegin(window);
#endif

    // ...

#ifdef GLFW_EXTRA_MAC_FUNCTIONS
    glfwMacWindowEnd(window);
#endif
}
```

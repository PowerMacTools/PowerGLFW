#include <GLFW/glfw3.h>
#include <stddef.h>
#include <stdio.h>

GLFWmonitor *glfwGetWindowMonitor(GLFWwindow *window) {
  printf("unimpl: glfwGetWindowMonitor\n");
  return NULL;
};
void glfwSetWindowMonitor(GLFWwindow *window, GLFWmonitor *monitor, int xpos,
                          int ypos, int width, int height, int refreshRate) {
  printf("unimpl: glfwSetWindowMonitor\n");
};
GLFWmonitor **glfwGetMonitors(int *count) {
  printf("unimpl: glfwGetMonitors\n");
  return NULL;
};
GLFWmonitor *glfwGetPrimaryMonitor(void) {
  printf("unimpl: glfwGetPrimaryMonitor\n");
  return NULL;
};
void glfwGetMonitorPos(GLFWmonitor *monitor, int *xpos, int *ypos) {
  printf("unimpl: glfwGetMonitorPos\n");
  *xpos = 0;
  *ypos = 0;
};
void glfwGetMonitorWorkarea(GLFWmonitor *monitor, int *xpos, int *ypos,
                            int *width, int *height) {
  printf("unimpl: glfwGetMonitorWorkArea\n");
  *xpos = 0;
  *ypos = 0;
  *width = 0;
  *height = 0;
};
void glfwGetMonitorPhysicalSize(GLFWmonitor *monitor, int *widthMM,
                                int *heightMM) {
  printf("unimpl: glfwGetMonitorPhysicalSize\n");
  *widthMM = 0;
  *heightMM = 0;
};
void glfwGetMonitorContentScale(GLFWmonitor *monitor, float *xscale,
                                float *yscale) {
  printf("unimpl: glfwGetMonitorContentScale\n");
  *xscale = 0;
  *yscale = 0;
};
const char *glfwGetMonitorName(GLFWmonitor *monitor) {
  printf("unimpl: glfwGetMonitorName\n");
  return "";
};
void glfwSetMonitorUserPointer(GLFWmonitor *monitor, void *pointer) {
  printf("unimpl: glfwSetMonitorUserPointer\n");
};
void *glfwGetMonitorUserPointer(GLFWmonitor *monitor) {
  printf("unimpl: glfwGetMonitorUserPointer\n");
  return NULL;
};
GLFWmonitorfun glfwSetMonitorCallback(GLFWmonitorfun callback) {
  printf("unimpl: glfwSetMonitorCallback\n");
  return NULL;
};
const GLFWvidmode *glfwGetVideoModes(GLFWmonitor *monitor, int *count) {
  printf("unimpl: glfwGetVideoModes\n");
  *count = 0;
  return NULL;
};
const GLFWvidmode *glfwGetVideoMode(GLFWmonitor *monitor) {
  printf("unimpl: glfwGetVideoMode\n");
  return NULL;
};
void glfwSetGamma(GLFWmonitor *monitor, float gamma) {
  printf("unimpl: glfwSetGamma\n");
};
const GLFWgammaramp *glfwGetGammaRamp(GLFWmonitor *monitor) {
  printf("unimpl: glfwGetGammaRamp\n");
  return NULL;
};
void glfwSetGammaRamp(GLFWmonitor *monitor, const GLFWgammaramp *ramp) {
  printf("unimpl: glfwSetGammaRamp\n");
};
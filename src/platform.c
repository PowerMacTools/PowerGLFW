#include "MacTypes.h"
#include "Timer.h"
#include "internal.h"
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint64_t gTimer;
UnsignedWide gLastMicroseconds;
TimerUPP gTimerUPP;

void globalTimer() {
  UnsignedWide microseconds;
  Microseconds(&microseconds);

  UnsignedWide newMicroseconds = {
      .hi = gLastMicroseconds.hi - microseconds.hi,
      .lo = gLastMicroseconds.lo - microseconds.lo,
  };

  gTimer += *(uint64_t *)&newMicroseconds;

  Microseconds(&newMicroseconds);
};

int glfwInit(void) {
  TMTask tm = {0};
  memset(&tm, 0, sizeof(tm));
  gTimerUPP = NewTimerProc(globalTimer);
  tm.tmAddr = gTimerUPP;

  InsTime((QElemPtr)&tm);
  PrimeTime((QElemPtr)&tm, 1);

  return GLFW_TRUE;
};
void glfwTerminate(void) {};
void glfwInitHint(int hint, int value) {};
void glfwInitAllocator(const GLFWallocator *allocator) {};
void glfwGetVersion(int *major, int *minor, int *rev) {
  *major = GLFW_VERSION_MAJOR;
  *minor = GLFW_VERSION_MINOR;
  *rev = GLFW_VERSION_REVISION;
};
const char *glfwGetVersionString(void) { return "3.5.0"; };
int glfwGetError(const char **description) { return GLFW_NO_ERROR; };

int glfwGetPlatform(void) { return GLFW_PLATFORM_MACOS9; };
int glfwPlatformSupported(int platform) {
  if (platform == GLFW_PLATFORM_MACOS9) {
    return GLFW_TRUE;
  } else {
    return GLFW_FALSE;
  }
};

GLFWerrorfun errCallback = NULL;

GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun callback) {
  GLFWerrorfun prevCallback = errCallback;
  errCallback = callback;
  return prevCallback;
};
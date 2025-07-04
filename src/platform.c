#include "MacTypes.h"
#include "Processes.h"
#include "Timer.h"
#include "internal.h"
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint64_t gTimer;
TMTask gTM;

UnsignedWide gLastMicroseconds;
TimerUPP gTimerUPP;
ProcessSerialNumber gPSN;

static void globalTimer(void) {
  gTimer += 1;
  PrimeTime((QElemPtr)&gTM, 1);
};

int glfwInit(void) {
  GetCurrentProcess(&gPSN);

  gTM.tmAddr = NewTimerProc(globalTimer);
  gTM.tmWakeUp = 0;
  gTM.tmReserved = 0;

  InsTime((QElemPtr)&gTM);
  PrimeTime((QElemPtr)&gTM, 1);

  return GLFW_TRUE;
};

void glfwTerminate(void) { RmvTime((QElemPtr)&gTM); };
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

double glfwGetTime(void) {
  // printf("%ld\n", gTimer);
  return (double)gTimer;
};
void glfwSetTime(double time) { gTimer = (uint64_t)time; };
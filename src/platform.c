#include "MacMemory.h"
#include "Timer.h"
#include "internal.h"
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int glfwInit(void) {
	MaxApplZone();
	for(int i = 0; i < 35; i++) {
		MoreMasters();
	}

	gTM.tmAddr	   = NewTimerProc(timerUpdateFunc);
	gTM.tmWakeUp   = 0;
	gTM.tmReserved = 0;

	InsTime((QElemPtr)&gTM);
	PrimeTime((QElemPtr)&gTM, 1);

	return GLFW_TRUE;
};

void glfwTerminate(void) { RmvTime((QElemPtr)&gTM); };
void glfwInitHint(int hint, int value) {};
void glfwGetVersion(int* major, int* minor, int* rev) {
	*major = GLFW_VERSION_MAJOR;
	*minor = GLFW_VERSION_MINOR;
	*rev   = GLFW_VERSION_REVISION;
};
const char* glfwGetVersionString(void) { return "3.5.0"; };
int			glfwGetError(const char** description) { return GLFW_NO_ERROR; };

int glfwGetPlatform(void) { return GLFW_PLATFORM_MACOS9; };
int glfwPlatformSupported(int platform) {
	if(platform == GLFW_PLATFORM_MACOS9) {
		return GLFW_TRUE;
	} else {
		return GLFW_FALSE;
	}
};

GLFWerrorfun errCallback = NULL;

GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun callback) {
	GLFWerrorfun prevCallback = errCallback;
	errCallback				  = callback;
	return prevCallback;
};

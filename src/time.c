#include "internal.h"
#include <GLFW/glfw3.h>
#include <Timer.h>
#include <stdint.h>
#include <stdio.h>

uint64_t glfwGetTimerValue(void) {
	printf("unimpl: glfwGetTimerValue\n");
	return 0;
};
uint64_t glfwGetTimerFrequency(void) {
	printf("unimpl: glfwGetTimerFrequency\n");
	return 0;
};
double glfwGetTime(void) { return (double)gTimer; };
void   glfwSetTime(double time) { gTimer = (uint64_t)time; };

TMTask	 gTM;
uint64_t gTimer;

void timerUpdateFunc(void) {
	gTimer += 1;
	PrimeTime((QElemPtr)&gTM, 1);
};
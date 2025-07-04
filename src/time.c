#include "internal.h"
#include <GLFW/glfw3.h>
#include <Timer.h>
#include <stdint.h>
#include <stdio.h>

double glfwGetTime(void) {
  printf("%ld\n", gTimer);
  return (double)gTimer;
};
void glfwSetTime(double time) { gTimer = (uint64_t)time; };
uint64_t glfwGetTimerValue(void) {
  printf("unimpl: glfwGetTimerValue\n");
  return 0;
};
uint64_t glfwGetTimerFrequency(void) {
  printf("unimpl: glfwGetTimerFrequency\n");
  return 0;
};

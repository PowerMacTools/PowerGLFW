
#include "GLFW/glfw3.h"

#include "MacTypes.h"
#include "Quickdraw.h"
#include "agl.h"

struct GLFWwindow {
  AGLContext context;
  AGLPixelFormat pixFormat;

  WindowPtr window;
  Rect winRect;
  int shouldClose;
  const char *title;

  int fbWidth;
  int fbHeight;
  int maximized;
  Rect prevWinBounds;

  void *userPtr;

  GLFWwindowposfun windowPosCallback;
  GLFWwindowsizefun windowSizeCallback;
  GLFWwindowclosefun windowCloseCallback;
  GLFWwindowrefreshfun windowRefreshCallback;
  GLFWwindowfocusfun windowFocusCallback;
  GLFWwindowiconifyfun windowIconifyCallback;
  GLFWwindowmaximizefun windowMaximizeCallback;
  GLFWframebuffersizefun windowSetFramebufferSizeCallback;
  GLFWwindowcontentscalefun windowContentScaleCallback;
};

extern uint64_t gTimer;
extern int aglErr;

// Execute an AGL function and then exit, printing the message, if it fails.
#define AGL_ERROR(x)                                                           \
  do {                                                                         \
    x;                                                                         \
    aglErr = aglGetError();                                                    \
    if (aglErr != AGL_NO_ERROR) {                                              \
      printf("AGL Error on %s: %s\n", #x, aglErrorString(aglErr));             \
      getchar();                                                               \
      exit(1);                                                                 \
    }                                                                          \
  } while (0);

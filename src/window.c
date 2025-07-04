#include "Events.h"
#include "MacTypes.h"
#include "Menus.h"
#include "Quickdraw.h"
#include "Threads.h"
#include <GLFW/glfw3.h>

#include "MacMemory.h"
#include "MacWindows.h"
#include "Quickdraw.h"
#include "TextEdit.h"
#include "Threads.h"
#include "agl.h"
#include "aglMacro.h"
#include "internal.h"
#include <Dialogs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aglErr;

GLFWwindow *___curWindow;

GLFWwindow *glfwCreateWindow(int width, int height, const char *title,
                             GLFWmonitor *monitor, GLFWwindow *share) {

  GLFWwindow *win = malloc(sizeof(GLFWwindow *));

  // Setup the Window
  InitGraf(&qd.thePort);
  InitFonts();
  FlushEvents(everyEvent, 0);
  InitWindows();
  InitMenus();
  TEInit();
  InitDialogs(0L);
  InitCursor();

  SetRect(&win->winRect, 100, 100, width, height);

  win->window = NewCWindow(nil, &win->winRect, (ConstStr255Param) "\p", true,
                           documentProc, (WindowPtr)(-1), true, 0);

  SetPort(win->window);
  setwtitle(win->window, title);

  aglConfigure(AGL_RETAIN_RENDERERS, GL_TRUE);

  // Choose a pixel format
  GLint aglAttributes[] = {AGL_RGBA, AGL_DOUBLEBUFFER, AGL_NONE};

  AGL_ERROR(win->pixFormat = aglChoosePixelFormat(NULL, 0, aglAttributes));

  if (win->pixFormat == NULL) {
    printf(
        "The system cannot find a pixel format and virtual screen that "
        "satisfies the constraints of the buffer and renderer attributes.\n");
    getchar();
    exit(1);
  }

  // Create a context
  AGL_ERROR(win->context = aglCreateContext(win->pixFormat, NULL));

  // Set the drawable region to our window
  CGrafPtr port = GetWindowPort(win->window);
  AGL_ERROR(aglSetDrawable(win->context, port));

  // Set it to be current
  AGL_ERROR(aglSetCurrentContext(win->context));

  win->shouldClose = false;

  win->userPtr = NULL;

  win->windowPosCallback = NULL;
  win->windowSizeCallback = NULL;
  win->windowCloseCallback = NULL;
  win->windowRefreshCallback = NULL;
  win->windowFocusCallback = NULL;
  win->windowIconifyCallback = NULL;
  win->windowMaximizeCallback = NULL;
  win->windowSetFramebufferSizeCallback = NULL;
  win->windowContentScaleCallback = NULL;

  YieldToAnyThread();

  return win;
};

void glfwDestroyWindow(GLFWwindow *window) {
  CloseWindow(window->window);
  DisposePtr((Ptr)window->window);

  aglDestroyPixelFormat(window->pixFormat);
  aglSetCurrentContext(NULL);
  aglSetDrawable(window->context, NULL);
  aglDestroyContext(window->context);

  YieldToAnyThread();
};

void glfwDefaultWindowHints(void) {
  printf("unimpl: glfwGetVersionString\n");

  YieldToAnyThread();
};
void glfwWindowHint(int hint, int value) {
  printf("unimpl: glfwWindowHint\n");
  YieldToAnyThread();
};
void glfwWindowHintString(int hint, const char *value) {
  printf("unimpl: glfwWindowHintString\n");

  YieldToAnyThread();
};

int glfwWindowShouldClose(GLFWwindow *window) { return window->shouldClose; };
void glfwSetWindowShouldClose(GLFWwindow *window, int value) {
  window->shouldClose = value;
};
const char *glfwGetWindowTitle(GLFWwindow *window) { return window->title; };
void glfwSetWindowTitle(GLFWwindow *window, const char *title) {
  setwtitle(window->window, title);
};
void glfwSetWindowIcon(GLFWwindow *window, int count, const GLFWimage *images) {
  printf("unimpl: glfwSetWindowIcon\n");
};
void glfwGetWindowPos(GLFWwindow *window, int *xpos, int *ypos) {
  Rect bounds;
  GetWindowBounds(window->window, kWindowStructureRgn, &bounds);
  *xpos = bounds.left;
  *ypos = bounds.top;
};
void glfwSetWindowPos(GLFWwindow *window, int xpos, int ypos) {
  Rect bounds;
  GetWindowBounds(window->window, kWindowStructureRgn, &bounds);
  bounds.left = xpos;
  bounds.top = ypos;
  SetWindowBounds(window->window, kWindowStructureRgn, &bounds);
};
void glfwGetWindowSize(GLFWwindow *window, int *width, int *height) {
  Rect bounds;
  GetWindowBounds(window->window, kWindowStructureRgn, &bounds);
  *width = bounds.right;
  *height = bounds.bottom;
};
void glfwSetWindowSizeLimits(GLFWwindow *window, int minwidth, int minheight,
                             int maxwidth, int maxheight) {
  printf("unimpl: glfwSetWindowSizeLimits\n");
};
void glfwSetWindowAspectRatio(GLFWwindow *window, int numer, int denom) {
  printf("unimpl: glfwSetWindowAspectRatio\n");
};
void glfwSetWindowSize(GLFWwindow *window, int width, int height) {
  Rect bounds;
  GetWindowBounds(window->window, kWindowStructureRgn, &bounds);
  bounds.right = width;
  bounds.bottom = height;
  SetWindowBounds(window->window, kWindowStructureRgn, &bounds);
};
void glfwGetFramebufferSize(GLFWwindow *window, int *width, int *height) {
  Rect updateRect = (*qd.thePort->visRgn)->rgnBBox;
  *width = updateRect.left - updateRect.right;
  *height = updateRect.top - updateRect.bottom;
};
void glfwGetWindowFrameSize(GLFWwindow *window, int *left, int *top, int *right,
                            int *bottom) {

  Rect bounds;
  GetWindowBounds(window->window, kWindowContentRgn, &bounds);
  *left = bounds.left;
  *top = bounds.top;
  *right = bounds.right;
  *bottom = bounds.bottom;
};
void glfwGetWindowContentScale(GLFWwindow *window, float *xscale,
                               float *yscale) {
  printf("unimpl: glfwGetWindowContentScale\n");
};
float glfwGetWindowOpacity(GLFWwindow *window) { return 1.0; };
void glfwSetWindowOpacity(GLFWwindow *window, float opacity) {
  printf("unimpl: glfwSetWindowOpacity\n");
};
void glfwIconifyWindow(GLFWwindow *window) { HideWindow(window->window); };
void glfwRestoreWindow(GLFWwindow *window) {
  if (window->maximized) {
    SetWindowBounds(window->window, kWindowStructureRgn,
                    &window->prevWinBounds);
    window->maximized = false;
  } else {
    ShowWindow(window->window);
  }
};
void glfwMaximizeWindow(GLFWwindow *window) {
  Point mouseLoc;
  GetMouse(&mouseLoc);
  long growResult =
      GrowWindow(window->window, mouseLoc, &(*(GetGrayRgn()))->rgnBBox);
  SizeWindow(window->window, growResult & 0xFFFF, growResult >> 16, false);

  window->maximized = GLFW_TRUE;
};
void glfwShowWindow(GLFWwindow *window) { ShowWindow(window->window); };
void glfwHideWindow(GLFWwindow *window) { HideWindow(window->window); };
void glfwFocusWindow(GLFWwindow *window) {
  HiliteWindow(window->window, true);
};

int glfwGetWindowAttrib(GLFWwindow *window, int attrib) {
  printf("unimpl: glfwGetWindowAttrib\n");
  return 0;
};
void glfwSetWindowAttrib(GLFWwindow *window, int attrib, int value) {
  printf("unimpl: glfwSetWindowAttrib\n");
};
void glfwSetWindowUserPointer(GLFWwindow *window, void *pointer) {
  window->userPtr = pointer;
};
void *glfwGetWindowUserPointer(GLFWwindow *window) { return window->userPtr; };
GLFWwindowposfun glfwSetWindowPosCallback(GLFWwindow *window,
                                          GLFWwindowposfun callback) {
  GLFWwindowposfun last = window->windowPosCallback;
  window->windowPosCallback = callback;
  return last;
};
GLFWwindowsizefun glfwSetWindowSizeCallback(GLFWwindow *window,
                                            GLFWwindowsizefun callback) {
  GLFWwindowsizefun last = window->windowSizeCallback;
  window->windowSizeCallback = callback;
  return last;
};
GLFWwindowclosefun glfwSetWindowCloseCallback(GLFWwindow *window,
                                              GLFWwindowclosefun callback) {
  GLFWwindowclosefun last = window->windowCloseCallback;
  window->windowCloseCallback = callback;
  return last;
};
GLFWwindowrefreshfun
glfwSetWindowRefreshCallback(GLFWwindow *window,
                             GLFWwindowrefreshfun callback) {
  GLFWwindowrefreshfun last = window->windowRefreshCallback;
  window->windowRefreshCallback = callback;
  return last;
};
GLFWwindowfocusfun glfwSetWindowFocusCallback(GLFWwindow *window,
                                              GLFWwindowfocusfun callback) {
  GLFWwindowfocusfun last = window->windowFocusCallback;
  window->windowFocusCallback = callback;
  return last;
};
GLFWwindowiconifyfun
glfwSetWindowIconifyCallback(GLFWwindow *window,
                             GLFWwindowiconifyfun callback) {
  GLFWwindowiconifyfun last = window->windowIconifyCallback;
  window->windowIconifyCallback = callback;
  return last;
};
GLFWwindowmaximizefun
glfwSetWindowMaximizeCallback(GLFWwindow *window,
                              GLFWwindowmaximizefun callback) {
  GLFWwindowmaximizefun last = window->windowMaximizeCallback;
  window->windowMaximizeCallback = callback;
  return last;
};
GLFWframebuffersizefun
glfwSetFramebufferSizeCallback(GLFWwindow *window,
                               GLFWframebuffersizefun callback) {
  GLFWframebuffersizefun last = window->windowSetFramebufferSizeCallback;
  window->windowSetFramebufferSizeCallback = callback;
  return last;
};
GLFWwindowcontentscalefun
glfwSetWindowContentScaleCallback(GLFWwindow *window,
                                  GLFWwindowcontentscalefun callback) {
  GLFWwindowcontentscalefun last = window->windowContentScaleCallback;
  window->windowContentScaleCallback = callback;
  return last;
};

void glfwMakeContextCurrent(GLFWwindow *window) { ___curWindow = window; };
GLFWwindow *glfwGetCurrentContext(void) { return ___curWindow; };

void glfwSwapBuffers(GLFWwindow *window) {
  BeginUpdate(window->window);

  InvalRect(&window->window->portRect);

  aglSwapBuffers(window->context);

  EndUpdate(window->window);

  YieldToAnyThread();
};

void glfwSwapInterval(int interval) { printf("unimpl: glfwSwapInterval\n"); };
int glfwExtensionSupported(const char *extension) {
  const char *extensions = (const char *)glGetString(GL_EXTENSIONS);
  if (!extensions) {
    return GLFW_FALSE;
  }

  const char *start = extensions;

  for (;;) {
    const char *where;
    const char *terminator;

    where = strstr(start, extensions);
    if (!where)
      return GLFW_FALSE;

    terminator = where + strlen(extensions);
    if (where == start || *(where - 1) == ' ') {
      if (*terminator == ' ' || *terminator == '\0')
        break;
    }

    start = terminator;
  }

  return GLFW_TRUE;
};
const char **glfwGetRequiredInstanceExtensions(uint32_t *count);

void glfwRequestWindowAttention(GLFWwindow *window) {
  // This isn't really a thing on Classic Mac OS, as far as I'm concerned.
  // We don't print an unimpl message because this function, as far as I'm
  // concerned, is allowed to do nothing "on platforms that don't support it"
};

void glfwMacWindowBegin(GLFWwindow *window) { YieldToAnyThread(); };
void glfwMacWindowEnd(GLFWwindow *window) {

};
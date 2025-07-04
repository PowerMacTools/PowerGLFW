
#include "GLFW/glfw3.h"

#include "MacTypes.h"
#include "Quickdraw.h"
#include "Timer.h"
#include "agl.h"
#include <stdbool.h>

#define WINDOW_HINTS_FOCUSED				 0b000000000001
#define WINDOW_HINTS_ICONIFIED				 0b000000000010
#define WINDOW_HINTS_RESIZABLE				 0b000000000100
#define WINDOW_HINTS_VISIBLE				 0b000000001000
#define WINDOW_HINTS_DECORATED				 0b000000010000
#define WINDOW_HINTS_AUTO_ICONIFY			 0b000000100000
#define WINDOW_HINTS_FLOATING				 0b000001000000
#define WINDOW_HINTS_MAXIMIZED				 0b000010000000
#define WINDOW_HINTS_CENTER_CURSOR			 0b000100000000
#define WINDOW_HINTS_TRANSPARENT_FRAMEBUFFER 0b001000000000
#define WINDOW_HINTS_FOCUS_ON_SHOW			 0b010000000000
#define WINDOW_HINTS_SCALE_TO_MONITOR		 0b100000000000

struct GLFWwindow {
	AGLContext	   context;
	AGLPixelFormat pixFormat;

	WindowPtr	window;
	Rect		winRect;
	int			shouldClose;
	const char* title;

	int	 fbWidth;
	int	 fbHeight;
	int	 maximized;
	Rect prevWinBounds;

	void* userPtr;

	GLFWwindowposfun		  windowPosCallback;
	GLFWwindowsizefun		  windowSizeCallback;
	GLFWwindowclosefun		  windowCloseCallback;
	GLFWwindowrefreshfun	  windowRefreshCallback;
	GLFWwindowfocusfun		  windowFocusCallback;
	GLFWwindowiconifyfun	  windowIconifyCallback;
	GLFWwindowmaximizefun	  windowMaximizeCallback;
	GLFWframebuffersizefun	  windowSetFramebufferSizeCallback;
	GLFWwindowcontentscalefun windowContentScaleCallback;
};

extern uint64_t gTimer;
extern int		aglErr;

extern TMTask				gTM;
extern uint64_t				gTimer;
void						timerUpdateFunc(void);
extern struct GLFWallocator gAlloactor;

// Execute an AGL function and then exit, printing the message, if it fails.
#define AGL_ERROR(x) \
	do { \
		x; \
		aglErr = aglGetError(); \
		if(aglErr != AGL_NO_ERROR) { \
			printf("AGL Error on %s: %s\n", #x, aglErrorString(aglErr)); \
			getchar(); \
			exit(1); \
		} \
	} while(0);

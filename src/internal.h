
#include "GLFW/glfw3.h"

#include "MacTypes.h"
#include "Quickdraw.h"
#include "Timer.h"
#include "agl.h"
#include <stdbool.h>

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

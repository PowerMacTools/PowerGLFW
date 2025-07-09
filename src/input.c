#include "CarbonEvents.h"
#include "Events.h"
#include "MacWindows.h"
#include "Quickdraw.h"
#include "Threads.h"
#include "internal.h"
#include "keymap.h"
#include <GLFW/glfw3.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void eventFunc(WindowPtr window, EventRecord event) {
	switch(event.what) {
	case updateEvt:
		if(___curWindow->windowRefreshCallback != NULL) {
			___curWindow->windowRefreshCallback(___curWindow);
		}
		break;
	case osEvt:
		break;
	case mouseUp: {
		if(___curWindow->mouseButtonCallback != NULL) {
			int mods = MacModifiersToGLFWModifiers(event.modifiers);

			if(___curWindow->keyStateMap[MK_LCTRL] == 1) {
				___curWindow->mouseButtonCallback(
					___curWindow, GLFW_MOUSE_BUTTON_RIGHT, GLFW_RELEASE, mods);
			} else {
				___curWindow->mouseButtonCallback(
					___curWindow, GLFW_MOUSE_BUTTON_LEFT, GLFW_RELEASE, mods);
			}
		}
	}
	case mouseDown: {
		// start with callback stuff
		if(___curWindow->mouseButtonCallback != NULL) {
			int mods = MacModifiersToGLFWModifiers(event.modifiers);

			if(___curWindow->keyStateMap[MK_LCTRL] == 1) {
				___curWindow->mouseButtonCallback(
					___curWindow, GLFW_MOUSE_BUTTON_RIGHT, GLFW_PRESS, mods);
			} else {
				___curWindow->mouseButtonCallback(
					___curWindow, GLFW_MOUSE_BUTTON_LEFT, GLFW_PRESS, mods);
			}
		}

		// then do system stuff
		switch(FindWindow(event.where, &window)) {
		case inDrag:
			DragWindow(window, event.where, &qd.screenBits.bounds);
			if(___curWindow->windowPosCallback != NULL) {
				___curWindow->windowPosCallback(___curWindow, event.where.h,
												event.where.v);
			}
			break;
		case inGrow: {
			long growResult =
				GrowWindow(window, event.where, &qd.screenBits.bounds);

			int width  = growResult & 0xFFFF;
			int height = growResult >> 16;

			SizeWindow(window, growResult & 0xFFFF, growResult >> 16, true);

			Rect rect;
			GetWindowBounds(window, kWindowStructureRgn, &rect);
			rect.right	= width;
			rect.bottom = height;
			SetWindowBounds(window, kWindowStructureRgn, &rect);

			___curWindow->width	 = width;
			___curWindow->height = height;

			if(___curWindow->windowSizeCallback != NULL) {
				___curWindow->windowSizeCallback(___curWindow, width, height);
			}
			if(___curWindow->windowSetFramebufferSizeCallback != NULL) {
				___curWindow->windowSetFramebufferSizeCallback(___curWindow,
															   width, height);
			}
		} break;

		case inGoAway: {
			if(TrackGoAway(window, event.where)) {
				if(___curWindow->windowCloseCallback != NULL) {
					___curWindow->windowCloseCallback(___curWindow);
				}
				___curWindow->shouldClose = true;
			}
		} break;
		}
	}
	case autoKey:
	case keyDown:
	case keyUp: {
		// key char stuff
		unsigned char ch = (event.message & charCodeMask);
		if(*___curWindow->charCallback != NULL) {
			___curWindow->charCallback(___curWindow, ch);
		}

		// key state map
		unsigned char key			   = (event.message & keyCodeMask) >> 8;
		___curWindow->keyStateMap[key] = 0;
		if(event.what == keyDown || event.what == autoKey) {
			___curWindow->keyStateMap[key] &= 1;
		}

		if(*___curWindow->keyCallback != NULL) {
			int key		 = MacKeyToGLFWKey(event.message);
			int scancode = (event.message & adbAddrMask) >> 16;

			int mods = MacModifiersToGLFWModifiers(event.modifiers);

			int action;
			if(event.what == keyUp) {
				action = GLFW_RELEASE;
			} else {
				action = GLFW_PRESS;
			}
			___curWindow->keyCallback(___curWindow, key, scancode, action,
									  mods);
		}
	}
	}
	Point mouseLoc;
	GetMouse(&mouseLoc);
	if(mouseLoc.h != ___curWindow->lastMousePos.h ||
	   mouseLoc.v != ___curWindow->lastMousePos.v) {
		if(___curWindow->cursorPosCallback != NULL) {
			___curWindow->cursorPosCallback(___curWindow, mouseLoc.h,
											mouseLoc.v);
			___curWindow->lastMousePos = mouseLoc;
		}
	}

	FlushEvents(everyEvent, -1);
	YieldToAnyThread();
}

void glfwPollEvents(void) {
	WindowPtr	window = ___curWindow->window;
	EventRecord event;

	SystemTask();

	RgnHandle rgn = NewRgn();
	while(!GetNextEvent(everyEvent, &event)) {
		YieldToAnyThread();
	}

	eventFunc(window, event);
};

void glfwWaitEvents(void) { glfwWaitEventsTimeout(1); };
void glfwWaitEventsTimeout(double timeout) {
	WindowPtr	window = ___curWindow->window;
	EventRecord event;

	SystemTask();

	while(!WaitNextEvent(everyEvent, &event, timeout, window->visRgn)) {
		YieldToAnyThread();
	}

	eventFunc(window, event);
};
void glfwPostEmptyEvent(void) { /* ... */ };
int	 glfwGetInputMode(GLFWwindow* window, int mode) { return 0; };
void glfwSetInputMode(GLFWwindow* window, int mode, int value) {};
int	 glfwRawMouseMotionSupported(void) { return GLFW_FALSE; };

const char* glfwGetKeyName(int key, int scancode) { return ""; };
int			glfwGetKeyScancode(int key) { return 0; };
int			glfwGetKey(GLFWwindow* window, int key) {
	uint8_t state = ___curWindow->keyStateMap[GLFWKeyToMacKey(key)];
	if(state == 1) {
		return GLFW_PRESS;
	} else {
		return GLFW_RELEASE;
	}
};

GLFWmousebuttonfun glfwSetMouseButtonCallback(GLFWwindow*		 window,
											  GLFWmousebuttonfun callback) {
	GLFWmousebuttonfun last		= window->mouseButtonCallback;
	window->mouseButtonCallback = callback;
	return last;
};
int	 glfwGetMouseButton(GLFWwindow* window, int button) { return 0; };
void glfwGetCursorPos(GLFWwindow* window, double* xpos, double* ypos) {
	*xpos = 0;
	*ypos = 0;
};
void		glfwSetCursorPos(GLFWwindow* window, double xpos, double ypos) {};
GLFWcursor* glfwCreateCursor(const GLFWimage* image, int xhot, int yhot) {
	return NULL;
};
GLFWcursor* glfwCreateStandardCursor(int shape) { return NULL; };
void		glfwDestroyCursor(GLFWcursor* cursor) {

};
void glfwSetCursor(GLFWwindow* window, GLFWcursor* cursor) {};

GLFWkeyfun glfwSetKeyCallback(GLFWwindow* window, GLFWkeyfun callback) {
	GLFWkeyfun last		= window->keyCallback;
	window->keyCallback = callback;
	return last;
};
GLFWcharfun glfwSetCharCallback(GLFWwindow* window, GLFWcharfun callback) {
	return NULL;
};
GLFWcharmodsfun glfwSetCharModsCallback(GLFWwindow*		window,
										GLFWcharmodsfun callback) {
	return NULL;
};

GLFWcursorposfun glfwSetCursorPosCallback(GLFWwindow*	   window,
										  GLFWcursorposfun callback) {
	GLFWcursorposfun last	  = window->cursorPosCallback;
	window->cursorPosCallback = callback;
	return last;
};
GLFWcursorenterfun glfwSetCursorEnterCallback(GLFWwindow*		 window,
											  GLFWcursorenterfun callback) {

	return NULL;
};
GLFWscrollfun glfwSetScrollCallback(GLFWwindow*	  window,
									GLFWscrollfun callback) {

	return NULL;
};
GLFWdropfun glfwSetDropCallback(GLFWwindow* window, GLFWdropfun callback) {
	return NULL;
};
int					 glfwJoystickPresent(int jid) { return GLFW_FALSE; };
const float*		 glfwGetJoystickAxes(int jid, int* count) { return NULL; };
const unsigned char* glfwGetJoystickButtons(int jid, int* count) {
	return NULL;
};
const unsigned char* glfwGetJoystickHats(int jid, int* count) { return NULL; };
const char*			 glfwGetJoystickName(int jid) { return ""; };
const char*			 glfwGetJoystickGUID(int jid) { return ""; };
void			glfwSetJoystickUserPointer(int jid, void* pointer) { return; };
void*			glfwGetJoystickUserPointer(int jid) { return NULL; };
int				glfwJoystickIsGamepad(int jid) { return GLFW_FALSE; };
GLFWjoystickfun glfwSetJoystickCallback(GLFWjoystickfun callback) {
	return NULL;
};
int glfwUpdateGamepadMappings(const char* string) { return GLFW_FALSE; };
const char* glfwGetGamepadName(int jid) { return ""; };
int			glfwGetGamepadState(int jid, GLFWgamepadstate* state) {
	return GLFW_FALSE;
};
void		glfwSetClipboardString(GLFWwindow* window, const char* string) {};
const char* glfwGetClipboardString(GLFWwindow* window) { return ""; };

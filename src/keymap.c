#include "keymap.h"
#include "Events.h"
#include "GLFW/glfw3.h"

int MacKeyToGLFWKey(int message) {
	unsigned char ch = (message & keyCodeMask) >> 8;
	switch(ch) {
	case MK_ESCAPE:
		return GLFW_KEY_ESCAPE;
	case MK_F1:
		return GLFW_KEY_F1;
	case MK_F2:
		return GLFW_KEY_F2;
	case MK_F3:
		return GLFW_KEY_F3;
	case MK_F4:
		return GLFW_KEY_F4;
	case MK_F5:
		return GLFW_KEY_F5;
	case MK_F6:
		return GLFW_KEY_F6;
	case MK_F7:
		return GLFW_KEY_F7;
	case MK_F8:
		return GLFW_KEY_F8;
	case MK_F9:
		return GLFW_KEY_F9;
	case MK_F10:
		return GLFW_KEY_F10;
	case MK_F11:
		return GLFW_KEY_F11;
	case MK_F12:
		return GLFW_KEY_F12;
	case MK_PRINT:
		return GLFW_KEY_PRINT_SCREEN;
	case MK_SCROLLOCK:
		return GLFW_KEY_SCROLL_LOCK;
	case MK_PAUSE:
		return GLFW_KEY_PAUSE;
	case MK_BACKQUOTE:
		return GLFW_KEY_GRAVE_ACCENT;
	case MK_1:
		return GLFW_KEY_1;
	case MK_2:
		return GLFW_KEY_2;
	case MK_3:
		return GLFW_KEY_3;
	case MK_4:
		return GLFW_KEY_4;
	case MK_5:
		return GLFW_KEY_5;
	case MK_6:
		return GLFW_KEY_6;
	case MK_7:
		return GLFW_KEY_7;
	case MK_8:
		return GLFW_KEY_8;
	case MK_9:
		return GLFW_KEY_9;
	case MK_0:
		return GLFW_KEY_0;
	case MK_q:
		return GLFW_KEY_Q;
	case MK_w:
		return GLFW_KEY_W;
	case MK_e:
		return GLFW_KEY_E;
	case MK_r:
		return GLFW_KEY_R;
	case MK_t:
		return GLFW_KEY_T;
	case MK_y:
		return GLFW_KEY_Y;
	case MK_u:
		return GLFW_KEY_U;
	case MK_i:
		return GLFW_KEY_I;
	case MK_o:
		return GLFW_KEY_O;
	case MK_p:
		return GLFW_KEY_P;

	case MK_a:
		return GLFW_KEY_A;
	case MK_s:
		return GLFW_KEY_S;
	case MK_d:
		return GLFW_KEY_D;
	case MK_f:
		return GLFW_KEY_F;
	case MK_g:
		return GLFW_KEY_G;
	case MK_h:
		return GLFW_KEY_H;
	case MK_j:
		return GLFW_KEY_J;
	case MK_k:
		return GLFW_KEY_K;
	case MK_l:
		return GLFW_KEY_L;

	case MK_z:
		return GLFW_KEY_Z;
	case MK_x:
		return GLFW_KEY_X;
	case MK_c:
		return GLFW_KEY_C;
	case MK_v:
		return GLFW_KEY_V;
	case MK_b:
		return GLFW_KEY_B;
	case MK_n:
		return GLFW_KEY_N;
	case MK_m:
		return GLFW_KEY_M;

	case MK_LCTRL:
		return GLFW_KEY_LEFT_CONTROL;
	case MK_LALT:
		return GLFW_KEY_LEFT_ALT;
	case MK_LMETA:
		return GLFW_KEY_LEFT_SUPER;
	case MK_SPACE:
		return GLFW_KEY_SPACE;
	case MK_LEFT:
		return GLFW_KEY_LEFT;
	case MK_DOWN:
		return GLFW_KEY_DOWN;
	case MK_RIGHT:
		return GLFW_KEY_RIGHT;
	case MK_KP0:
		return GLFW_KEY_KP_0;
	case MK_KP1:
		return GLFW_KEY_KP_1;
	case MK_KP2:
		return GLFW_KEY_KP_2;
	case MK_KP3:
		return GLFW_KEY_KP_3;
	case MK_KP4:
		return GLFW_KEY_KP_4;
	case MK_KP5:
		return GLFW_KEY_KP_5;
	case MK_KP6:
		return GLFW_KEY_KP_6;
	case MK_KP7:
		return GLFW_KEY_KP_7;
	case MK_KP8:
		return GLFW_KEY_KP_8;
	case MK_KP9:
		return GLFW_KEY_KP_9;
	case MK_KP_MINUS:
		return GLFW_KEY_KP_SUBTRACT;
	case MK_KP_PLUS:
		return GLFW_KEY_KP_ADD;
	case MK_KP_ENTER:
		return GLFW_KEY_KP_ENTER;
	case MK_KP_PERIOD:
		return GLFW_KEY_KP_DECIMAL;
	case MK_KP_EQUALS:
		return GLFW_KEY_KP_EQUAL;
	case MK_KP_DIVIDE:
		return GLFW_KEY_KP_DIVIDE;
	case MK_KP_MULTIPLY:
		return GLFW_KEY_KP_MULTIPLY;

	case MK_LEFTBRACKET:
		return GLFW_KEY_LEFT_BRACKET;
	case MK_RIGHTBRACKET:
		return GLFW_KEY_RIGHT_BRACKET;
	case MK_BACKSLASH:
		return GLFW_KEY_BACKSLASH;
	case MK_DELETE:
		return GLFW_KEY_DELETE;
	case MK_END:
		return GLFW_KEY_END;
	case MK_PAGEDOWN:
		return GLFW_KEY_PAGE_DOWN;
	case MK_CAPSLOCK:
		return GLFW_KEY_CAPS_LOCK;

	case MK_MINUS:
		return GLFW_KEY_MINUS;
	case MK_EQUALS:
		return GLFW_KEY_EQUAL;
	case MK_BACKSPACE:
		return GLFW_KEY_BACKSPACE;
	case MK_INSERT:
		return GLFW_KEY_INSERT;
	case MK_HOME:
		return GLFW_KEY_HOME;
	case MK_PAGEUP:
		return GLFW_KEY_PAGE_UP;
	case MK_NUMLOCK:
		return GLFW_KEY_NUM_LOCK;
	case MK_TAB:
		return GLFW_KEY_TAB;

	case MK_SEMICOLON:
		return GLFW_KEY_SEMICOLON;
	case MK_ENTER:
		return GLFW_KEY_ENTER;
	case MK_LSHIFT:
		return GLFW_KEY_LEFT_SHIFT;

	case MK_COMMA:
		return GLFW_KEY_COMMA;
	case MK_PERIOD:
		return GLFW_KEY_PERIOD;
	case MK_SLASH:
		return GLFW_KEY_SLASH;
	case MK_UP:
		return GLFW_KEY_UP;
	}
	return GLFW_KEY_UNKNOWN;
}

int GLFWKeyToMacKey(int ch) {
	switch(ch) {
	case GLFW_KEY_ESCAPE:
		return MK_ESCAPE;
	case GLFW_KEY_F1:
		return MK_F1;
	case GLFW_KEY_F2:
		return MK_F2;
	case GLFW_KEY_F3:
		return MK_F3;
	case GLFW_KEY_F4:
		return MK_F4;
	case GLFW_KEY_F5:
		return MK_F5;
	case GLFW_KEY_F6:
		return MK_F6;
	case GLFW_KEY_F7:
		return MK_F7;
	case GLFW_KEY_F8:
		return MK_F8;
	case GLFW_KEY_F9:
		return MK_F9;
	case GLFW_KEY_F10:
		return MK_F10;
	case GLFW_KEY_F11:
		return MK_F11;
	case GLFW_KEY_F12:
		return MK_F12;
	case GLFW_KEY_PRINT_SCREEN:
		return MK_PRINT;
	case GLFW_KEY_SCROLL_LOCK:
		return MK_SCROLLOCK;
	case GLFW_KEY_PAUSE:
		return MK_PAUSE;
	case GLFW_KEY_GRAVE_ACCENT:
		return MK_BACKQUOTE;
	case GLFW_KEY_1:
		return MK_1;
	case GLFW_KEY_2:
		return MK_2;
	case GLFW_KEY_3:
		return MK_3;
	case GLFW_KEY_4:
		return MK_4;
	case GLFW_KEY_5:
		return MK_5;
	case GLFW_KEY_6:
		return MK_6;
	case GLFW_KEY_7:
		return MK_7;
	case GLFW_KEY_8:
		return MK_8;
	case GLFW_KEY_9:
		return MK_9;
	case GLFW_KEY_0:
		return MK_0;
	case GLFW_KEY_Q:
		return MK_q;
	case GLFW_KEY_W:
		return MK_w;
	case GLFW_KEY_E:
		return MK_e;
	case GLFW_KEY_R:
		return MK_r;
	case GLFW_KEY_T:
		return MK_t;
	case GLFW_KEY_Y:
		return MK_y;
	case GLFW_KEY_U:
		return MK_u;
	case GLFW_KEY_I:
		return MK_i;
	case GLFW_KEY_O:
		return MK_o;
	case GLFW_KEY_P:
		return MK_p;

	case GLFW_KEY_A:
		return MK_a;
	case GLFW_KEY_S:
		return MK_s;
	case GLFW_KEY_D:
		return MK_d;
	case GLFW_KEY_F:
		return MK_f;
	case GLFW_KEY_G:
		return MK_g;
	case GLFW_KEY_H:
		return MK_h;
	case GLFW_KEY_J:
		return MK_j;
	case GLFW_KEY_K:
		return MK_k;
	case GLFW_KEY_L:
		return MK_l;

	case GLFW_KEY_Z:
		return MK_z;
	case GLFW_KEY_X:
		return MK_x;
	case GLFW_KEY_C:
		return MK_c;
	case GLFW_KEY_V:
		return MK_v;
	case GLFW_KEY_B:
		return MK_b;
	case GLFW_KEY_N:
		return MK_n;
	case GLFW_KEY_M:
		return MK_m;

	case GLFW_KEY_LEFT_CONTROL:
		return MK_LCTRL;
	case GLFW_KEY_LEFT_ALT:
		return MK_LALT;
	case GLFW_KEY_LEFT_SUPER:
		return MK_LMETA;
	case GLFW_KEY_SPACE:
		return MK_SPACE;
	case GLFW_KEY_LEFT:
		return MK_LEFT;
	case GLFW_KEY_DOWN:
		return MK_DOWN;
	case GLFW_KEY_RIGHT:
		return MK_RIGHT;
	case GLFW_KEY_KP_0:
		return MK_KP0;
	case GLFW_KEY_KP_1:
		return MK_KP1;
	case GLFW_KEY_KP_2:
		return MK_KP2;
	case GLFW_KEY_KP_3:
		return MK_KP3;
	case GLFW_KEY_KP_4:
		return MK_KP4;
	case GLFW_KEY_KP_5:
		return MK_KP5;
	case GLFW_KEY_KP_6:
		return MK_KP6;
	case GLFW_KEY_KP_7:
		return MK_KP7;
	case GLFW_KEY_KP_8:
		return MK_KP8;
	case GLFW_KEY_KP_9:
		return MK_KP9;
	case GLFW_KEY_KP_SUBTRACT:
		return MK_KP_MINUS;
	case GLFW_KEY_KP_ADD:
		return MK_KP_PLUS;
	case GLFW_KEY_KP_ENTER:
		return MK_KP_ENTER;
	case GLFW_KEY_KP_DECIMAL:
		return MK_KP_PERIOD;
	case GLFW_KEY_KP_EQUAL:
		return MK_KP_EQUALS;
	case GLFW_KEY_KP_DIVIDE:
		return MK_KP_DIVIDE;
	case GLFW_KEY_KP_MULTIPLY:
		return MK_KP_MULTIPLY;

	case GLFW_KEY_LEFT_BRACKET:
		return MK_LEFTBRACKET;
	case GLFW_KEY_RIGHT_BRACKET:
		return MK_RIGHTBRACKET;
	case GLFW_KEY_BACKSLASH:
		return MK_BACKSLASH;
	case GLFW_KEY_DELETE:
		return MK_DELETE;
	case GLFW_KEY_END:
		return MK_END;
	case GLFW_KEY_PAGE_DOWN:
		return MK_PAGEDOWN;
	case GLFW_KEY_CAPS_LOCK:
		return MK_CAPSLOCK;

	case GLFW_KEY_MINUS:
		return MK_MINUS;
	case GLFW_KEY_EQUAL:
		return MK_EQUALS;
	case GLFW_KEY_BACKSPACE:
		return MK_BACKSPACE;
	case GLFW_KEY_INSERT:
		return MK_INSERT;
	case GLFW_KEY_HOME:
		return MK_HOME;
	case GLFW_KEY_PAGE_UP:
		return MK_PAGEUP;
	case GLFW_KEY_NUM_LOCK:
		return MK_NUMLOCK;
	case GLFW_KEY_TAB:
		return MK_TAB;

	case GLFW_KEY_SEMICOLON:
		return MK_SEMICOLON;
	case GLFW_KEY_ENTER:
		return MK_ENTER;
	case GLFW_KEY_LEFT_SHIFT:
		return MK_LSHIFT;

	case GLFW_KEY_COMMA:
		return MK_COMMA;
	case GLFW_KEY_PERIOD:
		return MK_PERIOD;
	case GLFW_KEY_SLASH:
		return MK_SLASH;
	case GLFW_KEY_UP:
		return MK_UP;
	}
	return 0x00;
}

int MacModifiersToGLFWModifiers(EventModifiers modifiers) {
	int mods = 0;
	if((modifiers & cmdKeyBit) == cmdKeyBit) {
		mods |= GLFW_MOD_SUPER;
	};
	if((modifiers & shiftKeyBit) == shiftKeyBit ||
	   (modifiers & rightShiftKeyBit) == rightShiftKeyBit) {
		mods |= GLFW_MOD_SHIFT;
	};
	if((modifiers & alphaLockBit) == alphaLockBit) {
		mods |= GLFW_MOD_CAPS_LOCK;
	};
	if((modifiers & optionKeyBit) == optionKeyBit ||
	   (modifiers & rightOptionKeyBit) == rightOptionKeyBit) {
		mods |= GLFW_MOD_ALT;
	};
	if((modifiers & controlKeyBit) == controlKeyBit ||
	   (modifiers & rightControlKeyBit) == rightControlKeyBit) {
		mods |= GLFW_MOD_CONTROL;
	}
	return mods;
}
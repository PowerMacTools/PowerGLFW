#include "GLFW/glfw3.h"
#include <Interrupts.h>
#include <MacMemory.h>
#include <string.h>

static void* defaultAllocatorFunc(size_t size, void* user) {
	Ptr ptr = NewPtr(size);
	if(ptr == NULL || MemError()) {
		// todo: glfw out of memory
	}
	return ptr;
}
static void* defaultRellocatorFunc(void* block, size_t size, void* user) {
	if(block == NULL) {
		return defaultAllocatorFunc(size, user);
	} else {
		SetPtrSize(block, size);
		if(MemError()) {
			// todo: out of memory or operation on free
		}
		return block;
	}
}
static void defaultDeallocatorFunc(void* block, void* user) {
	DisposePtr(block);
	if(MemError()) {
		// todo: operation on free
	}
}

GLFWallocator gAlloactor = {
	.allocate	= defaultAllocatorFunc,
	.deallocate = defaultDeallocatorFunc,
	.reallocate = defaultRellocatorFunc,
};

void glfwInitAllocator(const GLFWallocator* allocator) {
	if(allocator) {
		if(allocator->allocate && allocator->reallocate &&
		   allocator->deallocate) {
			gAlloactor = *allocator;
		} else {
			//   _glfwInputError(GLFW_INVALID_VALUE, "Missing function in
			//   allocator");
		}
	} else {
		memset(&gAlloactor, 0, sizeof(GLFWallocator));
	}
};

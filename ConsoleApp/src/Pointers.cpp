#include "pch.h"

namespace LANG_CONSTRUCTS
{
	#pragma region RAW_POINTERS
	/*
		*	Win32 Memory Map Overview:
		*	- Program Image
		*		- .TEXT section:
		*			→ Contains compiled machine code (instructions)
		*			→ Marked as read + execute (RX), not writable
		*
		*		- .DATA and .BSS sections:
		*			→ .DATA = initialized globals/static vars
		*			→ .BSS = uninitialized globals/statics (zero-initialized)
		*
		*	- Heap:
		*		→ Dynamically allocated memory via `new`, `malloc`, etc.
		*		→ Grows upward in memory
		*
		*	- Stack:
		*		→ Stores local variables, function parameters, return addresses
		*		→ Grows downward
		*
		*	- DLLs:
		*		→ Each loaded DLL gets mapped into the process address space
		*		→ Each has its own .text, .data, etc., sections
		*
		*	- TEB (Thread Environment Block):
		*		→ Per-thread data, exception handlers, stack info, etc.
		*
		*	- PEB (Process Environment Block):
		*		→ Process-wide info: loaded modules, heap info, etc.
		*
		*	- Kernel Space:
		*		→ Not directly accessible by user-mode code
		*		→ Mapped higher in virtual memory (e.g., 0x80000000+ on 32-bit)
		*
		*	- Free / Reserved:
		*		→ Unused regions of the virtual address space
		* 
		*	A pointer is an object / variable that holds a memory address (which is an integer, e.g: 0x0040FF10).
		*	Remember that the pointer itself can't really have a type, this is just fiction, it just points to
		*	something which we can only assume to be of a certain type.
		*/

	void* ptr{ 0 };
	void* ptr1{ NULL };
	void* ptr2{ nullptr };

	int variableWithAddress{ 8 };
	// Giving a value to a pointer
	int* pointerPointingToVariable{ &variableWithAddress };
	double* castDoublePtr{ (double*)&variableWithAddress };

	// Why not always use a void* ?
	// Well eventually the computer will need to know
	// How many bytes to write into the pointer
	#pragma endregion
}
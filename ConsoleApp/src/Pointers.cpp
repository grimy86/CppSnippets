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

	void Raw_Pointers()
	{
		// Nullptrs
		void* ptr{ 0 };
		void* ptr1{ NULL };
		void* ptr2{ nullptr };

		// Initializing a pointer
		int variableWithAddress{ 8 };
		int* pointerPointingToVariable{ &variableWithAddress };
		double* castDoublePtr{ (double*)&variableWithAddress };

		/*
		*	Why not always use a void* ?
		*		void* is a generic pointer, it holds an address,
		*		but the compiler doesn't know what type it's pointing to, so:
		*			- You can't dereference it (e.g: *ptr) without casting.
		*			- You can't perform pointer arithmetic (e.g: ptr + 1) without casting.
		*	The compiler needs to know how many bytes to read/write — which it gets from the pointer's type.
		*/ 

		// Read from & Write to a pointer (dereferencing)
		*pointerPointingToVariable = 10; // Write to the pointer
		int intFromPointer{ *pointerPointingToVariable }; // Read from the pointer

		// Create a variable on the heap / allocate memory
		// Allocate 8 bytes of memory on the heap, our pointer points to the beginning
		char* buffer{ new char[8] };
		// Fill the buffer with 0's for 8 bytes
		memset(buffer, 0, 8);
		// Free the memory when done
		delete[] buffer;

		char* buffer2{ new char[4] };
		char** ptrToBuffer2{ &buffer2 }; // Pointer to a pointer
	}
	#pragma endregion

	#pragma region REFERENCES
	/*
		*	A reference is an object / variable that doesn't typically occupy memory since it's simply a reference to another address.
	*/

	void IncrementByPtr(int* value);
	void IncrementByRef(int& value);

	void References()
	{
		// References are aliases for existing variables
		int variable{ 5 };
		int& referenceToVariable{ variable }; // referenceToVariable is an alias for variable

		// Changing the value of the reference changes the original variable
		referenceToVariable = 10; // variable is now 10

		// References must be initialized when declared and cannot be changed to refer to another variable
		int anotherVariable{ 20 };
		referenceToVariable = anotherVariable; // This does NOT change the reference, it just assigns the value of anotherVariable to variable

		IncrementByPtr(&variable); // Pass by pointer
		IncrementByRef(variable); // Pass by reference
	}

	void IncrementByPtr(int* value) { (*value)++; }
	void IncrementByRef(int& value) { value++; }
	#pragma endregion
}

#pragma region ARROW_OPERATOR
class PlayerArr {
public:
	void PrintName()
	{
		std::cout << "Player" << std::endl;
	}
};
#pragma endregion

void TestArrOperator()
{
	PlayerArr* p = new PlayerArr(); // Remember the new keyword returns a pointer
	// If you use new, you must use delete or you create memory leaks.
	p->PrintName(); // Instead of p.PrintName();
	delete p; // Memory cleanup
}

/*
🔁 Optional Additions (only if you want to go deeper later):
	Pointer arithmetic (e.g., ptr + 1)

	const pointers and pointer to const

	Function pointers

	Smart pointers (std::unique_ptr, shared_ptr) — not raw, but a critical modern alternative

	Dangling pointers / memory leaks / undefined behavior

	Reference collapsing (in templates) if you go into advanced topics
*/
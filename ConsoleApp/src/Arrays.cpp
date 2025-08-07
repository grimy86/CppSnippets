#include "pch.h"

namespace Arrays
{
	/*
	* An array in C++ is a contiguous block of memory.
	* When you declare an array like `int example[5];`, the compiler allocates space for 5 integers on the stack.
	* The array variable `example` itself is a pointer to the first element of that array.
	* You can access elements in the array using the indexer `[]`, which translates to pointer arithmetic.
	* For example, `example[0]` is equivalent to `*(example + 0)`, and `example[4]` is equivalent to `*(example + 4)`.
	*/
	void Arrays()
	{
		int example[5];
		int* ptrToExampleStart{ example };
		
		example[2] = 5;
		*(ptrToExampleStart + 2) = 5; // This is the same as above
		*(int*)((char*)ptrToExampleStart + 8) = 5; // This is the same as above, just cast to a char* to move 8 times by 1 byte and then cast back into a int* to be derefernced..

		// Heap array
		int* anotherArray = new int[5];
		delete[] anotherArray;
	}
}
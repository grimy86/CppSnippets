#include "pch.h"

namespace CONSTSPACE
{
#pragma region CONSTANTS
	/*
	*	They keyword const marks an object as immutable.
	*	It's a promise to the compiler that the data is readonly.
	*	
	*	Const correctness is the practice of using this mark consistently.
	*		- Prevent accidental modification of data
	*		- Enable safer and more optimized code
	*/

	class ConstClass
	{
	public:
		void exampleFunc()
		{
			// VARIABLES
			int var = 5;
			const int x = 5;
			// x = 6;, illegal because x is immutable


			// POINTERS
			// pointer to const int (data is const, pointer is not)
			// This is logical because x is const, we can't do: int* ptr = &x;
			// int* ptr = &x; // illegal, x is const
			const int* ptr1 = &x;
			int const* ptr0 = &x; // same as above, just different syntax
			// const pointer to int (pointer is const, data is not)
			int* const ptr2 = &var;
			// const pointer to const int
			const int* const ptr3 = &x;
			// what NOT TO DO, bypass constness
			int* ptr{ (int*)&x };
		}

		// PARAMETERS
		// Avoids unnecessary copies and enforces immutability.
		void printValue(const std::string& str) { return; }

		// Returning const values can prevent modification
		const std::string getName() { return "myName"; }

		// A method that cannot modify any class-members
		// It won't change the object and is only a readonly method.
		int getValue() const { return 0; }

		// EXAMPLE
		const int* const GetX() const
		{
			m_value = 5;
			return m_x;
		}

	private:
		mutable int m_value{ 5 }; // mutable allows modification in const methods
		int* m_x, *m_y;
	};
#pragma endregion
}
#include "pch.h"

namespace LANG_CONSTRUCTS
{
	#pragma region FUNCTIONS
	/*
	*	Functions vs. Methods:	Functions inside of a class are (class) methods
	*/
	int Multiply(int a, int b)
	{
		return a * b;
	}

	void LogMultiply(int a, int b)
	{
		std::cout << (a * b) << '\n';
	}
	#pragma endregion
}
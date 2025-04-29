#include "pch.h"

namespace CONSTSPACE
{
#pragma region CONSTANTS
	/*
	*	Const is more like a promise to the compiler that you have to keep. It just means, this code won't change.
	*/

	void Const()
	{
		const int MAX_AGE{ 90 };
		
		int* a = new int;

		*a = 2;
		a = (int*)&MAX_AGE;

		std::cout << *a << std::endl;
	}
#pragma endregion
}
#include "pch.h"

namespace Enums
{
	/*
	*	An enum just adds a way of adding text to a integer value
	*/

	// Problem:
	/*
	* int A {0};
	* int B {1};
	* int C {2};
	* 
	* int value = B
	* 
	* if( value == B)
	* {
	*	// Code();
	* }
	* 
	* The biggest issue is that the integers aren't grouped anymore,
	*	and when we change the value of our int value it doesn't make sense anymore.
	*/

	class EnumClass
	{
	public:
		enum Example
		{
			A, B, C
		};

		void TestEnums()
		{
			std::cout << "Enum Example::B is equal to: " << Example::B << std::endl;
		}
	};

	void TestEnumClass()
	{
		EnumClass e;
		e.TestEnums();
	}
}
#include "pch.h"

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
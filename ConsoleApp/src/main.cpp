#include "pch.h" // Our own pre-compiled header-file

void TestClasses();
void TestTerribleLogClass();
void TestEnumClass();
void TestArrOperator();
void TestVirtualFunctions();
void TestInterfaces_PureVirtualFunctions();

int main()
{
    TestClasses();
    TestTerribleLogClass();
    TestEnumClass();
    TestArrOperator();
    TestVirtualFunctions();
    TestInterfaces_PureVirtualFunctions();

    return 0;
}

/*
C++ Style guide :
    1. Avoid globals
    2. Const corectness
    3. References > pointers
    4. RAII
    5. Copy & Copy Assignment Constructor + Destructor if needed
    6.  Minimize #include's

Functions:
	| Type of Data                                                             | How to Pass                             | Why                                            |
	| ------------------------------------------------------------------------ | --------------------------------------- | ---------------------------------------------- |
	| **Small types (ints, floats, chars, bools, enums)**                      | By **value**                            | Copying is faster and simpler; avoids aliasing |
	| **Large types (std::string, std::vector, user-defined structs/classes)** | By **const reference**                  | Avoids expensive copies                        |
	| **Objects that need to be modified**                                     | By **non-const reference**              | So the function can change the original        |
	| **Ownership transfer needed**                                            | By **value or rvalue reference (`&&`)** | Enables move semantics                         |

Classes:
	class Example {
		int x;             // uninitialized
		std::string name;  // default-constructed to ""
	public:
		Example() {}
	};
	//OR
	class Example {
		int x { 0 };
		std::string name { "" };
		Example() {}
	};
	//OR
	class Example {
		int x;
		std::string name;
	public:
		Example() : x(0), name(""){}
	};
	//OR
	class Example {
		int x { 0 };
		std::string name { "" };
	public:
		Example () = default; // uses the in-class default initializers
		Example (int num, std::string someName) : x(num), name (someName) {} // overrides them
	};

Just remember for constructors:
use the initializer list to initialize members, use the body to assign to already default constructed members
*/


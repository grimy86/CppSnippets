#pragma region InitializationStandards
/*
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

MORE STYLE TIPS:
| Type of Data                                                             | How to Pass                             | Why                                            |
| ------------------------------------------------------------------------ | --------------------------------------- | ---------------------------------------------- |
| **Small types (ints, floats, chars, bools, enums)**                      | By **value**                            | Copying is faster and simpler; avoids aliasing |
| **Large types (std::string, std::vector, user-defined structs/classes)** | By **const reference**                  | Avoids expensive copies                        |
| **Objects that need to be modified**                                     | By **non-const reference**              | So the function can change the original        |
| **Ownership transfer needed**                                            | By **value or rvalue reference (`&&`)** | Enables move semantics                         |

Additional tips:
1. Never allocate on heap
2. Less code is more code
3. Order members by object size (for better memory alignment)
4. Pass by const reference
5. Implement a logging system for every project; https://www.youtube.com/watch?v=dZr-53LAlOw
6. Avoid Cache-misses; https://www.youtube.com/watch?v=OBp7rpdg_IQ
7. Implement the rule of 5
*/
#pragma endregion
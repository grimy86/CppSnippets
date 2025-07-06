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

    std::cout << "=== Pointer Types & Address Arithmetic ===\n\n";

    int value = 1337;
    std::cout << "Original int value: " << value << "\n";
    std::cout << "Address of value (&value): " << &value << "\n\n";

    // -------------------------------
    // 1. void* - Generic Pointer
    // -------------------------------
    void* voidPtr = &value;
    std::cout << "[void*] voidPtr = &value => " << voidPtr << "\n";

    // void* must be cast before use
    int dereferencedViaVoid = *(int*)voidPtr;
    std::cout << "[void*] Dereferenced (int*)voidPtr => " << dereferencedViaVoid << "\n\n";

    // -------------------------------
    // 2. BYTE* - Pointer to 1 byte
    // -------------------------------
    BYTE* bytePtr = (BYTE*)&value;
    std::cout << "[BYTE*] bytePtr = (BYTE*)&value => " << static_cast<void*>(bytePtr) << "\n";

    std::cout << "[BYTE*] Individual bytes of int 1337 (little endian): ";
    for (int i = 0; i < sizeof(int); i++) {
        std::cout << std::hex << (int)bytePtr[i] << " ";
    }
    std::cout << std::dec << "\n\n";

    // Modify a byte in memory (change least significant byte of 1337 -> 0x39 -> 0x00)
    bytePtr[0] = 0x00;
    std::cout << "[BYTE*] After modification, value = " << value << "\n\n";

    // Reset value
    value = 1337;

    // -------------------------------
    // 3. uintptr_t - Integer to hold pointer address
    // -------------------------------
    uintptr_t addrInt = (uintptr_t)&value;
    std::cout << "[uintptr_t] Address of value as integer: " << std::hex << addrInt << std::dec << "\n";

    // Address arithmetic: simulate adding offset (like in a JMP instruction)
    uintptr_t offset = 4;
    uintptr_t newAddrInt = addrInt + offset;
    std::cout << "[uintptr_t] newAddrInt = addrInt + 4 => " << std::hex << newAddrInt << std::dec << "\n\n";

    // -------------------------------
    // 4. uintptr_t -> Pointer (back)
    // -------------------------------
    int* intPtrFromInt = (int*)addrInt;
    std::cout << "[uintptr_t -> int*] Dereferenced: " << *intPtrFromInt << "\n\n";

    // -------------------------------
    // 5. DWORD* - 4-byte memory patch
    // -------------------------------
    DWORD* dwordPtr = (DWORD*)&value;
    std::cout << "[DWORD*] dwordPtr = (DWORD*)&value => " << dwordPtr << "\n";
    std::cout << "[DWORD*] *dwordPtr (should match value): " << *dwordPtr << "\n";

    // Change value via DWORD*
    *dwordPtr = 0xDEADBEEF;
    std::cout << "[DWORD*] After writing 0xDEADBEEF, value = " << std::hex << value << std::dec << "\n\n";

    // -------------------------------
    // 6. uintptr_t* - Rarely used
    // -------------------------------
    uintptr_t addrHolder = (uintptr_t)&value;
    uintptr_t* ptrToIntAddress = &addrHolder;
    std::cout << "[uintptr_t*] Points to variable holding an address: " << std::hex << *ptrToIntAddress << std::dec << "\n";

    std::cout << "\n=== End ===\n";

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


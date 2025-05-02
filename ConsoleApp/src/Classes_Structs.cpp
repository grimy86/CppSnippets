#include "pch.h"

	/*
	*	Classes are essentially just a "management" difference,
	*	you could write the same code perfectly without classes.
	* 
	*	Classes & Structs are essentially the same
	*	the only difference is a minor visibility difference.
	*	However, structs are usually used for small reference types.
	*/
	#pragma region CLASSES
	class PlayerTest
	{
	public:
		int x, y;
		int speed;

		void Move(int xa, int ya)
		{
			x += xa * speed;
			y += ya * speed;
		}
	};

	struct PlayerType2
	{
	// public by default
		int x, y;
		int speed;

		void Move(int xa, int ya)
		{
			x += xa * speed;
			y += ya * speed;
		}
	};
#pragma endregion

#pragma region CONSTRUCTORS AND DESTRUCTORS
	/*
	*	CONSTRUCTOR:
	*
	*	For static classes we could either hide the constructor by making it private
	*	or, we could put "= delete;" after the constructor.
	*	This avoids object instances...
	*/

	class EntityTest
	{
	private:
		float _x;
		float _y;

	public:
		// EntityTest() = delete;  Removes the constructor

		// Constructor
		EntityTest()
		{
			_x = 0.0f;
			_y = 0.0f;

			std::cout << "Created entity!" << std::endl;
		}

		// Destructor
		~EntityTest()
		{
			std::cout << "Destroyed entity!" << std::endl;
		}

		void Print()
		{
			std::cout << _x << ", " << _y << std::endl;
		}
	};

	// When you define a constructor,
	// you can initialize member variables
	// using an initialization list
	// instead of doing it manually inside {}.
	class InitializationListExplained
	{
	private:
		int X;
		int Y;

	public:
		// Initialization list after :
		InitializationListExplained(int xValue, int yValue)
			: X(xValue), Y(yValue) // <--- This part
		{
			// Constructor body (optional)
		}
	};

	void TestClasses()
	{
		PlayerTest playerOne;
		playerOne.x = 5;
		playerOne.y = 5;
		playerOne.Move(10, 10);

		EntityTest e;
		e.Print();
	}
#pragma endregion

namespace COPYING
{
	#pragma region COPYING
	struct Vec2
	{
		float x, y;
	};

	void Copying()
	{
		// Both vectors have seperate memory addresses
		// All we did was copy the value at &a into b
		Vec2 a{ 2, 3 };
		Vec2 b{a};

		Vec2* aPtr{ new Vec2() };
		Vec2* bPtr{ aPtr };
		bPtr->x = 5; // This affects both pointers

		// While on the topic of copying, passing an object to a function makes a copy
		// Therefor usually pass by reference
	}

	class String
	{
		/*
			Your class does not define a copy constructor or copy assignment operator, so C++ uses the default implementations.
			These perform a shallow copy, meaning both objects end up pointing to the same m_Buffer.

			The solution is to deep copy by providing a copy constructor!
		*/

	private:
		char* m_Buffer;
		unsigned int m_Size;
	public:
		String(const char* string)
		{
			m_Size = strlen(string);
			m_Buffer = new char[m_Size + 1];
			memcpy(m_Buffer, string, m_Size);
			m_Buffer[m_Size] = 0;
		}

		/* C++ default shallow copy constructor
			String(const String& other)
			{
				memcpy(this, &other, sizeof(String));
			}
		*/
		
		String(const String& other)
			:m_Size(other.m_Size)
		{
			m_Buffer = new char[m_Size + 1];
			memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		}

		~String()
		{
			delete[] m_Buffer;
		}

		char& operator[](unsigned int index)
		{
			return m_Buffer[index];
		}

		friend std::ostream& operator<<(std::ostream& stream, const String& string);
	};

	std::ostream& operator<<(std::ostream& stream, const String& string)
	{
		stream << string.m_Buffer;
		return stream;
	}
	#pragma endregion
}


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
*/
#pragma endregion

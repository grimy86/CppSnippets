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
#pragma endregion

	void TestClasses()
	{
		PlayerTest playerOne;
		playerOne.x = 5;
		playerOne.y = 5;
		playerOne.Move(10, 10);

		EntityTest e;
		e.Print();
	}


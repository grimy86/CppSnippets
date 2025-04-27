#include "pch.h"

namespace LANG_CONSTRUCTS
{
#pragma region INHERITANCE
	/*
	*	Used to share functionality between classes and create less repitive code.
	*/

	class EntityBase
	{
	public:
		float X, Y;
		
		void Move(float xa, float ya)
		{
			X += xa;
			Y += ya;
		}
	};

	// Everything that's publicly accessible in EntityBase,
	// is now also accesible in player
	class PlayerObject : public EntityBase 
	{
	public:
		const char* Name;

		void PrintName()
		{
			std::cout << Name << std::endl;
		}
	};
}
#pragma endregion

/*
*	A virtual function in C++ is a function that is defined in the base class
*	and CAN be overridden by the derived class.
* 
*	A pure virtual function is a virtual function that does not have a definition
*	in the base class and MUST be overridden by any derived class.
*/
#pragma region VIRTUAL_FUNCTIONS
/*
* Pointer instances:
	The new keyword returns a pointer, hence "std::string* MyString = new std::string("Hello");"
	And a pointer's properties are accessed by arrow operator (->) instead of a dot (.)
*/

class EntityVF
{
public:
	virtual std::string GetName() { return "Entity"; }
};

class PlayerVF : public EntityVF
{
private:
	std::string _name;
public:
	PlayerVF(const std::string& name)
		: _name(name) {}

	// Not required but good practice to
	// mark your virtual functions as override
	// also this could prevent spelling mistakes, etc.
		std::string GetName() override { return _name; }
};

void PrintName(EntityVF* entity)
{
	std::cout << entity->GetName() << std::endl;
}

void TestVirtualFunctions()
{
	// without marking entity's GetName() as virtual,
	// this would print entity twice cause it uses
	// the type's GetName() and doesn't even look at
	// the vTable
	EntityVF* evf = new EntityVF();
	PrintName(evf);

	PlayerVF* pvf = new PlayerVF("Grimy");
	PrintName(pvf);
}
#pragma endregion

#pragma region INTERFACES_PURE_VIRTUAL_fUNCTIONS
class IPrintable
{
public:
	virtual std::string GetClassName() = 0;
};

class SomeBaseType : public IPrintable
{
public:
	virtual std::string GetClassName() override { return "SomeBaseType"; }
};

class SomePlayerType : public SomeBaseType
{
public:
	virtual std::string GetClassName() override { return "SomePlayerType"; }
};

void Print(IPrintable* entity)
{
	std::cout << entity->GetClassName() << std::endl;
}

void TestInterfaces_PureVirtualFunctions()
{
	SomeBaseType* evf = new SomeBaseType();
	Print(evf);

	SomePlayerType* pvf = new SomePlayerType();
	Print(pvf);
}
#pragma endregion
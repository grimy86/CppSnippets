#include "pch.h"

namespace CONVERSION
{
#pragma region CONVERSION
	class Entity
	{
	private:
		std::string m_Name;
		int m_Age;

	public:
		explicit Entity(const std::string& name)
			: m_Name(name), m_Age(-1) {
		}

		Entity(int age)
			: m_Name("Unknown"), m_Age(age) {
		}
	};

	void PrintEntity(const Entity& entity) {}

	void Foo()
	{
		// Entity a("Grimy");
		// Entity b(99);
		// Entity a{ "Grimy" };
		// Entity b{ 99 };
		Entity a = 99; // If you want to prevent stuff like this you can mark the constructor as "explicit"
		Entity b = Entity(std::string("Grimy")); // This is the effect of that, you have to explicitly call the constructor

		PrintEntity(Entity("Grimy"));
		PrintEntity(22);
	}
#pragma endregion
}
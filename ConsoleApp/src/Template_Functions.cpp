#include "pch.h"

namespace TemplateFunctions
{
	class templates
	{
		/*
		*	Get the compiler to write code for me based on the rules I've given it.
		*	It like a blueprint.
		*/

		template<typename T>
		void Print(T value)
		{
			std::cout << value << std::endl;
		}

		void Templates()
		{
			Print(5); // The compiler figures it out
			Print<int>(5); // Explicit type passing
		}
	};
}
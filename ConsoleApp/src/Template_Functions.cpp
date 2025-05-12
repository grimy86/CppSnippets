#include "pch.h"

namespace templatefunctions
{
	class templateExamples
	{
		template<typename T>
		void Print(T value)
		{
			std::cout << value << std::endl;
		}
	};
}
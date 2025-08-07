#include "pch.h"

namespace Statics
{
	/*
	*	The static keyword has 2 context definitions:
	*	1. Inside of class or struct:
	*		There's only one instance of this symbol accross all instances.
	*		Static methods also don't have a class instance, therefor they can't
	*		access non-static members. It's the equivalent of writing
			the method outside of the class.
	* 
	*	2. Outside of class or struct:
	*		The linkage of this static symbol is going to be internal (only visible to this translation unit).
	*		It's kind of like marking a variable private. Even the "extern" keyword won't resolve it.
	*/

	static void Code() // Internal linkage
	{
	 
	}
}
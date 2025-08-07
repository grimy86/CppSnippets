namespace LvaluesAndRvalues
{
	class Example
	{
		int& LValueRefFunc()
		{
			static int value{0};
			return value;
		}

		void Foo()
		{
			// lvalue is mostly on the left side of operator
			// rvalue is mostly on the right side of operator
			int i = 10;
			// We can't store data into an rvalue: 10 = i;
			// If this didn't return a mutable int& then this wouldn't work.
			LValueRefFunc() = 5;

			/*
				Lvalue:
					A MUTABLE object that has a PERSISTENT location in memory.
					Persistent location, addressable & assignable.
				Rvalue:
					A temporary object or a value that doesn't have a persistent location in memory.
					About to be discarded or moved.
					Temporary location, unaddressable & unassignable.
			*/
		}
	};
}
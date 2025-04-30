namespace LANG_CONSTRUCTS
{
	#pragma region BRANCHES
    /*
    *   If statement:       executes the block if the condition is true
    *   If-else:            one of the two blocks will run depending on the condition
    *   If-else if-else:    multiple conditions checked in order
    *   Switch:             useful when checking the same variable against multiple values
    *   Ternary operator:   shorthand for simple if-else
    */
    
    void Code() { return; }

    void Branches()
    {
        int value = 42;
        if (value > 10)
        {
            // Executes because 42 > 10
            Code();
        }

        if (value < 10)
        {
            // This won't run because 42 is not less than 10
            Code();
        }
        else
        {
            // This will run instead
            Code();
        }

        if (value == 0)
        {
            Code();
        }
        else if (value == 42)
        {
            // This will run
            Code();
        }
        else
        {
            Code();
        }

        switch (value)
        {
        case 0:
            Code();
            break;
        case 1:
            // fallthrough (intentional)
        case 42:
            // This case matches and runs
            Code();
            break;
        default:
            Code();
            break;
        }

        // Ternary operator
        int result = (value > 10) ? 1 : 0;
        int result2 = (value > 10) ? (value < 10) ? 1 : 0 : 1; // Chaining is also possible
    }
	#pragma endregion
	#pragma region LOOPS
    /*
    *   For:        Loops a fixed number of times
    *   While:      Loops while a condition is true
    *   Do While:   Executes once, then loops while condition is true
    */

    void Loops()
	{
		int iterations{ 5 };
		// for (code executed once at the beginning of the for loop; bool evaluated before next iteration; executed code)
		for (int indexer = 0; indexer < iterations; indexer++)
		{
			Code();
		}

		bool condition{ true };
		while (condition)
		{
			Code();
		}

		do
		{
			Code();
		} while (condition);
	}
	#pragma endregion
	#pragma region CONTROL_FLOW_STATEMENTS
	/*
	 *  continue: Skips the rest of the current loop iteration
	 *            and jumps straight to the next one.
	 *
	 *  break:    Immediately exits the loop.
	 *
	 *  return:   Exits the current function entirely.
	 *            If the function returns void, use 'return;' by itself.
	 *            Otherwise, you must return a value of the correct type.
     * 
     *  Be aware that control flow statements could lead to dead code.
     *  Always check every (continue / return) path.
	 */

    void ControlFlow()
    {
        for (int i = 0; i < 5; i++)
        {
            if (i == 2)
            {
                // Skip iteration when i is 2
                continue;
            }

            if (i == 4)
            {
                // Exit the loop entirely when i is 4
                break;
            }

            Code();
        }

        // Exit the function entirely
        return;

        // This won't run because of the return above
        Code();
    }
	#pragma endregion
}
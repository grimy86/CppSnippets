namespace LANG_CONSTRUCTS
{
	#pragma region PRIMITIVE_TYPES
	/*
	*	By default C++ doesn't initialize variables like Java or C# does.
	*	This means you get whatever is left over inside of that memory.
	*	Most of the time this is undefined behavior / utter garbage.
	* 
	*	Naming convention:
	*		m_ = private member variables
	*		s_ = static class variables or internal linkage variables
	*		g_ = global variables
	*		c_ = constant variables (optional)
	*/
	
	// Primitive types
	// The only difference is the size / memory the variables occupy
	char a; short b; int c; long d; long long e;
	float f{ 5.5f }; bool g{ true };

	// Getting the size
	int h = sizeof(f);
	int i = sizeof(float);

	// Pointers
	bool* _boolPointer;
	// bool& _boolReference;
	#pragma endregion
}
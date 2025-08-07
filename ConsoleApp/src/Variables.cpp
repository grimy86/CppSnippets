#include <new>

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

	// Example type
	class Entity
	{

	};

	void HeapFunc()
	{
		// Heap allocated objects
		Entity* e = new Entity(); // == Entity* e = (Entity*)malloc(sizeof(Entity));
		delete e; // == free(e); known as scalar delete

		// Arrays are a bit different however
		int* b = new int[50]; // 200 bytes
		delete[] b;

		// Placement new, decide where memory comes from
		char buffer[sizeof(Entity)];
		Entity* o = new(buffer) Entity();

	} // e won't actually be freed here because it's a heap object

	#pragma endregion
}
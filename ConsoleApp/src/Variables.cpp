namespace LANG_CONSTRUCTS
{
	#pragma region PRIMITIVE_TYPES
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
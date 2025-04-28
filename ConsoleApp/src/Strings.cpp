#include "pch.h"

namespace LANG_CONSTRUCTS
{
#pragma region STRINGS
	/*
	*	A string is an array of characters and as we know an array is just pointer.
	*	So a char* is a pointer to a character (e.g. the first char in a string..).
	* 
	*	The reason is const is because you don't want to change a string's value
	*	since they are immutable (incapable of being changed) because the array
	*	size is fixed.
	* 
	*	Another reason is because literals between double quotes
	*	are already const char arrays.
	* 
	*	ASCII-encoding is the default encoding where characters are 1 byte meaning,
	*	we have 265 character possibilities for each char in the string.
	* 
	*	Remember that at the end of every string we have a special NULL terminator
	*	character, which is why "Hello" actually has 6 elements instead of 5.
	*	Think of the string as {'H','e','l','l','o','\0'}
	* 
	*	Read-only strings should be passed by const reference
	*	const as in, it's read-only and thus immutable,
	*	reference as in don't make a local copy for the function,
	*	this would be done on the heap and would also be very slow.
	* 
	*	Literals:
	*		const char* = "" or u8"" - 1byte/char (UTF-8)
	*		const wchar_t* = L"" - 2 or 4 bytes (platform-dependent)
	*		const char16t_t* = u"" - 2byte/char (UTF16-Unicode)
	*		const char32_t* = U"" - 4byte/char (UTF32-Unicode)
	* 
	*		using namespace std::string_literals;
	*		std::string = ""s
	*		u8""s, L""s, u""s, U""s, etc.
	* 
	*		ignore escape characters = R"" - (RAW string)
	*/
#pragma endregion
}
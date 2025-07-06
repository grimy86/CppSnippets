/*
*	Avoids including this headerfile multiple times
*	into a single translation unit.
*
*	Traditionally IFNDEF was used in combination
*	with DEFINE.
*
*	Angular brackets are only for
*	compiler-include path
*
*	Quotes are for everything
*
*	C stdlib files often end in .h
*
*	C++ stdlib files often
*	have no extension or end in .hpp
*/

#pragma once
#include <iostream>
#include <string>
#include <Windows.h> // For BYTE, DWORD
#include <memory>
#include <cstdint>  // For uintptr_t
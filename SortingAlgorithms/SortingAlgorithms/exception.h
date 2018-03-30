#pragma once
enum EXCEPTION_CODE
{
	openError,
	readError,
	lackOfMemory,
	valueOutsideOfRange
};
void seeException(EXCEPTION_CODE error);

#include "exception.cpp"
#include "myarray.h"
#include "exception.h"
int * createNewTab(int iSize)
{
	try
	{
		int *T = new int[iSize];
		return T;
	}
	catch (std::bad_alloc)
	{
		throw EXCEPTION_CODE::lackOfMemory;
	}
}
#include "CSortTablicy.h"


CSortTablicy::CSortTablicy(int arraySize) : CTablica(arraySize)
{

}


void CSortTablicy::CShuffle(int startIndex, int endIndex)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int>dist(1, 1000);
	for (int i = startIndex; i < endIndex; i++)
	{
		*(pArray + i) = dist(mt);
	}

}

void CSortTablicy::CfillSorted()
{
	for (int i = 0; i < elementCount; i++)
	{
		*(pArray + i) = i;
	}
}

void CSortTablicy::CfillReverseSorted()
{
	int tempIndex = elementCount;
	for (int i = 0; i < elementCount; i++)
	{
		*(pArray + i) = --tempIndex;
	}
}


void CSortTablicy::CfillAlmostSorted()
{
	int ninetyPercent = static_cast<int>(0.9 * elementCount);
	CShuffle(ninetyPercent, elementCount);
}

void CSortTablicy::CPrintArray()
{
	for (int i = 0; i < elementCount; i++)
	{
		cout << *(pArray + i) << " ";
	}
	cout << endl;
}

CSortTablicy::~CSortTablicy()
{
	delete[] pArray;
}

void CSortTablicy::CPrintCount()
{
	cout << "Liczba porownan: " << compareCount << "\t" << "przestawien: " << shiftCount << endl;
}


int CSortTablicy::CGetElementCount()
{
	return this->elementCount;
}
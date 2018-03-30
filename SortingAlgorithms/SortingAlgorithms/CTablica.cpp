#include "CTablica.h"
using namespace std;
CTablica::CTablica(int arraySize)
{

	elementCount = arraySize;
	shiftCount = 0;
	compareCount = 0;
	try
	{
		pArray = createNewTab(elementCount);
	}
	catch (EXCEPTION_CODE error)
	{
		seeException(error);
	}
	// Wypelnienie wartosciam
	std::fill_n(pArray, elementCount, 1);;
}

void CTablica::CBubbleSort()
{
	compareCount = 0;
	shiftCount = 0;
	int i = -1, j;
	bool bSwap;
	do {
		bSwap = false;
		for (++i, j = elementCount - 1; j > i; --j)
		{
			if (*(pArray + j) < *(pArray + j - 1))
			{
				swap(*(pArray + j), *(pArray + j - 1));
				bSwap = true;
				shiftCount++;
			}
			compareCount++;
		}
	} while (bSwap);
}


void CTablica::CQuickSort(int l, int r)
{
	if (l >= r) return; // Przerywa wykonywanie funkcji.
	int pivot = partition_Lomuto(l, r); // Lomuto.
	CQuickSort(l, pivot - 1);
	CQuickSort(pivot + 1, r);
}


int CTablica::partition_Lomuto(int l, int r)
{
	int x = *(pArray + r), // Podzia³ wzglêdem prawego elementu.
		i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (*(pArray + j) < x)
		{
			i++;
			swap(*(pArray + i), *(pArray + j));
			shiftCount++;
		}
		compareCount++;
	}
	swap(*(pArray + i + 1), *(pArray + r));
	shiftCount++;
	return i + 1;
}

void CTablica::CBucketSort()
{
	int minValue = pArray[0];
	int maxValue = pArray[0];

	for (int i = 1; i < elementCount; i++)
	{
		if (pArray[i] > maxValue)
		{
			maxValue = pArray[i];
		}

		if (pArray[i] < minValue)
		{
			minValue = pArray[i];
		}
		compareCount++;
	}

	int bucketLength = maxValue - minValue + 1;
	vector<int>* bucket = new vector<int>[bucketLength];

	for (int i = 0; i < bucketLength; i++)
	{
		bucket[i] = vector<int>();
	}

	for (int i = 0; i < elementCount; i++)
	{
		bucket[pArray[i] - minValue].push_back(pArray[i]);
	}

	int k = 0;
	for (int i = 0; i < bucketLength; i++)
	{
		int bucketSize = bucket[i].size();

		if (bucketSize > 0)
		{
			for (int j = 0; j < bucketSize; j++)
			{
				pArray[k] = bucket[i][j];
				shiftCount++;
				k++;
			}
		}
		compareCount++;
	}
}


void CTablica::findMaxMinAndStartCountingSort(int & min, int & max) {

	int pom = 0;
	for (int j = 0; j < elementCount; j++)
	{
		pom = pArray[j];
		if (max < pom)
		{
			max = pom;
		}
	}
	pom = 0;
	min = max;
	for (int i = 0; i < elementCount; i++)
	{
		pom = pArray[i];
		if (min > pom)
		{
			min = pom;
		}
	}
}


void CTablica::CCountingSort()
{
	int min = 0, max = 0;
	CTablica::findMaxMinAndStartCountingSort(min, max);
	int cLen = max - min + 1;
	int * count = createNewTab(cLen);
	int z = 0;

	for (int i = 0; i < cLen; i++)
		count[i] = 0;

	for (int i = 0; i <elementCount; i++)
		count[pArray[i] - min]++;

	for (int i = min; i <= max; i++)
	{
		while (count[i - min]-- > 0)
		{
			compareCount++;
			pArray[z] = i;
			++z;
		}

	}
	delete count;
}

void CTablica::validateMaxHeap_FunctionHeapSort(int * pArray2, int heapSize, int parentIndex)
{
	int maxIndex = parentIndex;
	int leftChild = parentIndex * 2 + 1;
	int rightChild = parentIndex * 2 + 2;
	if (leftChild<heapSize && pArray2[leftChild] > pArray2[maxIndex])
	{
		maxIndex = leftChild;
	}
	if (rightChild < heapSize&& pArray2[rightChild] > pArray2[maxIndex])
	{

		maxIndex = rightChild;
	}
	if (maxIndex != parentIndex)
	{
		shiftCount++;
		swap(pArray2[maxIndex], pArray2[parentIndex]);
		validateMaxHeap_FunctionHeapSort(pArray2, heapSize, maxIndex);
	}
	compareCount++;
}


void  CTablica::CHeapSort()
{
	int n = elementCount;
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		validateMaxHeap_FunctionHeapSort(pArray, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		swap(pArray[0], pArray[i]);
		shiftCount++;
		--n;
		validateMaxHeap_FunctionHeapSort(pArray, n, 0);

	}
}

void CTablica::CShakerSort()
{
	for (int i = 1; i < elementCount; ++i)
	{
		for (int j = i - 1; j < elementCount - i; ++j)
		{
			if (pArray[j] > pArray[j + 1])
			{
				shiftCount++;
				swap(pArray[j], pArray[j + 1]);
			}
			compareCount++;
		}

		for (int j = elementCount - i - 1; j >= i; --j)
		{
			compareCount++;
			if (pArray[j] < pArray[j - 1])
			{
				shiftCount++;
				swap(pArray[j], pArray[j - 1]);
			}
		}
	}
}


void CTablica::CstartClock()
{
	begin = clock();
}

void CTablica::CstopClock()
{
	end = clock();
}

void CTablica::CgetTime()
{
	double dTime = static_cast<double>(end - begin);
	cout << elementCount << "liczb, czas sortowania: " << dTime << "ms\n";
}
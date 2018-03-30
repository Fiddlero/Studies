#include "main.h"

int main()
{
	int elementCount = readElementCount();
	CSortTablicy * dataArray = new CSortTablicy(elementCount);

	// Wybor sposobu uporzadkowania danych oraz metody sortowania.
	dataSortChoice(dataArray);
	//dataArray->CPrintArray();

	sortMethodChoice(dataArray);

	// Wyswietlenie liczby przestawien i porownan.
	//dataArray->CPrintArray();
	dataArray->CgetTime();
	dataArray->CPrintCount();

	delete dataArray;

	return 0;
}


int readElementCount()
{
	int elementCount2;
	try
	{

		cout << "Podaj liczbe elementow: " << endl;
		cin >> elementCount2;
		if (elementCount2 < 0 || elementCount2 > 1000000)
		{
			throw EXCEPTION_CODE::valueOutsideOfRange;
		}
	}
	catch (EXCEPTION_CODE error)
	{
		seeException(error);
	}
	return elementCount2;

}

void dataSortChoice(CSortTablicy * dataArray)
{
	int dataSortType,
		elementCount = dataArray->CGetElementCount();
	cout << "Wybierz sposob uporzadkowania danych:\n[0] \t Calkowicie uporzadkowane \n";
	cout << "[2] \t Uporzodkowane w odwrotnej kolejnosci\n";
	cout << "[1] \t Prawie uporzadkowane (10% na zlych pozycjach)\n";
	cout << "[3] \t Brak uporzadkowania (losowosc danych)\n";

	cin >> dataSortType;


	switch (dataSortType)
	{
	case fullSorted:
		dataArray->CfillSorted();
		break;
	case reverseSorted:
		dataArray->CfillReverseSorted();
		break;
	case almostSorted:
		dataArray->CfillAlmostSorted();
		break;
	case notSorted:
		dataArray->CShuffle(0, elementCount);
		break;
	default:
		cout << "Wybierz poprawna metode\n";
		dataSortChoice(dataArray);

	}
}

void sortMethodChoice(CSortTablicy * dataArray)
{
	int choice,
		elementCount = dataArray->CGetElementCount();
	cout << "Wybierz metode:\n[0] \t Sortowanie babelkowe (kontrola monotonicznosci)\n";
	cout << "[1] \t Sortowanie babelkowe (wahadlowe)\n";
	cout << "[2] \t Sortowanie kubelkowe\n";
	cout << "[3] \t Sortowanie przez zliczanie\n";
	cout << "[4] \t Sortowanie szybkie (alg. podzialu Lomuto)\n";
	cout << "[5] \t Sortowanie przez kopcowanie\n";

	cin >> choice;
	switch (choice)
	{
	case bubbleSort:
		dataArray->CstartClock();
		dataArray->CBubbleSort();
		dataArray->CstopClock();
		break;
	case shakerSort:
		dataArray->CstartClock();
		dataArray->CShakerSort();
		dataArray->CstopClock();
		break;
	case bucketSort:
		dataArray->CstartClock();
		dataArray->CBucketSort();
		dataArray->CstopClock();
		break;
	case countingSort:
		dataArray->CstartClock();
		dataArray->CCountingSort();
		dataArray->CstopClock();
		break;
	case quickSort:
		dataArray->CstartClock();
		dataArray->CQuickSort(0, elementCount - 1);
		dataArray->CstopClock();
		break;
	case heapSort:
		dataArray->CstartClock();
		dataArray->CHeapSort();
		dataArray->CstopClock();
		break;
	default:
		cout << "Wybierz poprawna metode\n";
		sortMethodChoice(dataArray);

	}
}






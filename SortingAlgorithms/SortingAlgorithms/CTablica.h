#pragma once

class CTablica
{
protected:
	clock_t begin, end;
	int elementCount,
		*pArray;
	long compareCount,
		shiftCount;
public:
	/**
	* Tworzy tablice typu int podanej wielkosci.
	*
	* @param iTabSize Wielkosc tablicy.
	*/
	CTablica(int iTabSize);
	/**
	* Sortowanie algorytmem babelkowym,
	* z ciagla kontrola monotonicznosci.
	* Ciagla kontrola monotoniczności → zmienna logiczna
	* Przed każdym przebiegiem false, po przestawieniu true
	* jesli true, to sortuj dalej, jeśli nie — zakoncz.
	*/
	void CBubbleSort();
	/**
	* Sortowanie algorytmem kubelkowym.
	* Podział przedziału [0, elementCount] na l podprzedziałów, które odpowiadają
	* liczbie kubełków (bucket)
	* Dystrybucja elementów n-elementowej tablicy do odpowiednich
	* kubełków.	Oczekujemy, że dzięki jednostajnemu rozkładowi
	* w każdym kubełku będzie niewiele liczb
	* Sortujemy liczby w każdym kubelku i scalamy rozwiazanie.
	*/
	void CBucketSort();
	/**
	* Sortowanie szybkie z podzialem Lomuto.
	* Idea: wywoływana jest procedura Quick Sort, aż to otrzymania
	* podzbiorów o małej liczebności, a następnie te małe zbiory o
	* rozłącznych wartościach są sortowane jednym z prostych algorytmów
	* sortowania (np. Insert Sort), które chociaż mają złożoność
	* obliczeniową rzędu O(n2), to dla zbiorów o niewielkim rozmiarze
	* działają relatywnie szybko.
	*/
	void CQuickSort(int l, int r);
	/**
	* Sortowanie przez zliczanie.
	*/
	void CCountingSort();
	/**
	* Sortowanie przez kopcowanie.
	* Funkcja wyznacza ostatniego rodzica,
	* od niego poruszamy sie az do korzenia.
	*/
	void CHeapSort();

	/**
	* Sortowanie wahadlowe.
	* Funkcja wykonuje algorytm "shakerSort" polegający na
	* sortowaniu liczb od lewej do prawej i od prawej do lewej.
	* Algorytm wykonuje się do czasu posortowania calej talicy rosnąco.
	*/
	void CShakerSort();

	/**
	* Algorytm podzialu Lomuto.
	*/
	int partition_Lomuto(int l, int r);
	/**
	* Funkcja znajduje skrajne liczby znajdujące się w tablicy tj.
	* minimalną liczbę i maksymalną liczbę w tablicy.Funkcja niezbędna
	* do działania algorytmu przez zliczanie.
	*
	* @param [in, out] min Zmienna do przechowywania minimalnej liczby.
	* @param [in, out] max Zmienna do przechowywania maxymalnej liczby.
	*/
	void findMaxMinAndStartCountingSort(int & min, int & max);
	/**
	* Funkcja wyznacza ideks maksymalny, prawego dziecka i lewego dziecka. Następnie
	* sprawdzamy czy ideks mieści się w rozmiarze tablicy oraz czy ideks lewego dziecka
	* jest większy od elementu z pod maxIdex(analogicznie dla prawego dziecka). Jeśli założenie
	* jest spełnione to dziecko jest przypisywane jako maksymalny ideks. Jeśli maksymanlny ideks
	* jest różny od indeksu rodzica to elementy w tablicy są zamieniane a funkcja ufuchamia się rekurencyjnie.
	*
	* @param [in, out] pArray2      Tablica z danymi do walidacji.
	* @param           heapSize	    Ilosc elementow w kopcu.
	* @param           parentIndex  Indeks rodzica.
	*/
	void validateMaxHeap_FunctionHeapSort(int * pArray2, int heapSize, int parentIndex);
	void CstartClock();
	void CstopClock();
	void CgetTime();

};

#include "CTablica.cpp"

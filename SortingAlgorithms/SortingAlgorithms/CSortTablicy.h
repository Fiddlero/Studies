#pragma once

class CSortTablicy
	: public CTablica
{
private:
	int elementCounts;
public:
	CSortTablicy(int elementCount);
	/**
	* Losowo generuje liczby do tablicy z predzialu 1 - 1mln.
	*
	* @param startIndex Indeks od ktorego zaczyna wypelniac tablice.
	* @param endIndex Indeks do ktorego wypelnia tablice.
	*/
	void CShuffle(int startIndex, int endIndex);
	/**
	* Wypelnia tablice posortowanymi wartosciami.
	*/
	void CfillSorted();
	/**
	* Wypelnia tablice odwrotnie posortowanymi wartosciami.
	*/
	void CfillReverseSorted();
	/**
	* Wypelnia tablice posortowana dobrze w 90%.
	*/
	void CfillAlmostSorted();
	/**
	* Wyswietla tablice.
	*/
	void CPrintArray();
	/**
	* Wyswietla ilosc przestawien oraz porownan.
	*/
	void CPrintCount();
	/**
	* Zwraca ilosc elementow tablicy.
	*/
	int  CGetElementCount();
	~CSortTablicy();

};


#include "CSortTablicy.cpp"
#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <ctime>
#include "exception.h"
#include "myArray.h"
#include "CTablica.h"
#include "CSortTablicy.h"

using namespace std;


enum methodChoice
{
	bubbleSort,
	shakerSort,
	bucketSort,
	countingSort,
	quickSort,
	heapSort
};

enum dataSort
{
	fullSorted,
	almostSorted,
	reverseSorted,
	notSorted
};

/**
* Wybor sposobu posortowania wstepnych danych.
*
* @param dataArray Klasa z tablica do wypelnienia.
*/
void dataSortChoice(CSortTablicy * dataArray);

/**
* Wybor sposobu sortowania danych.
*
* @param dataArray Klasa z tablica do posortowania.
*/
void sortMethodChoice(CSortTablicy * dataArray);

/**
* Wczytanie ilosci danych.
*
* @return Ilosc danych.
*/
int readElementCount();
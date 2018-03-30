#include "stdafx.h"
#include<iostream>
#include <random>
#include<fstream>

using namespace std;
void Otworz_Plik_do_zapisu_Generator_LCG(fstream &plik);
void Otworz_Plik_do_odczytu(fstream &plik);
void Zamiana_wartosci_w_tablicy(int tab1[], int tab2[], int wielkosc_tablic);
int *Stworz_Tablice(int size);
int Liczba_losowa(int min, int max);                                             
int NWD(int a, int b);                                                         
int SzukajPrzyrost(int m);
int Licznik_modulo(int a, int b, int m);
void Generator_LCG(int Xmax, int n, fstream &plik);
void Zamknij_Plik(fstream &plik);
void Generator_addytywny(int Xmax, int n, fstream &plik);
void Otworz_Plik_do_zapisu_Addytywny(fstream &plik);
void Otworz_Plik_do_odczytu_pary_liczb(ifstream& plik);
void Rekomendowane_Pary(int n, int &j, int &k);                                
int *Pierwsze_dzielniki(int n, int &rozmiarTab);

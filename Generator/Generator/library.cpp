#include"header.h";
/*
>Funkcja otwiera plik aby zapisa� dane
kt�re pochodz� z generatora LCG
*/
void Otworz_Plik_do_zapisu_Generator_LCG(fstream &plik) {

	string nazwaPliku;
	nazwaPliku = "Gotowy_zapisany_wynik_Generator_LCG";
	nazwaPliku += ".txt";
	plik.open(nazwaPliku.c_str(), ios::out);

}
/*
>Funkcja otwiera plik aby zapisa� dane
kt�re pochodz� z generatora Addytywnegoo
*/
void Otworz_Plik_do_zapisu_Addytywny(fstream &plik) {

	string nazwaPliku;
	nazwaPliku = "Gotowy_zapisany_wynik_Generator_Addytywny";
	nazwaPliku += ".txt";
	plik.open(nazwaPliku.c_str(), ios::out);

}
/*
>Funkcja otwiera plik do odczytu gotowych
wynik�w z generatora LCG
*/
void Otworz_Plik_do_odczytu(fstream& plik) {

	plik.open("Gotowy_zapisany_wynik_Generator_LCG.txt");

	if (!plik.good())
		cout << "Plik nie zosta� otwarty" << endl;
}
/*
>Funkcja odczytuje plik do oczytu rekomendowanych par
*/
void Otworz_Plik_do_odczytu_pary_liczb(ifstream& plik) {

	plik.open("pary_liczb.txt");

	if (!plik.good())
		cout << "Plik nie zosta� otwarty" << endl;
}
/*
>Funkcja kt�ra zapisuje elementy jednej tablicy w
tabkicy drugiej tylko ze od ko�ca
*/
void Zamiana_wartosci_w_tablicy(int tab1[], int tab2[], int wielkosc_tablic) {
	int wartosc_tablicy = 1;
	for (int j = (wielkosc_tablic - 1); j >= 0; j--) {
		tab2[wartosc_tablicy] = tab1[j];
		wartosc_tablicy++;
	}

}
/*
>Funkcja tworzy tablic� dynamiczn�
z kontrol� b��d�w. Je�li tablica nie
zostanie utworzona u�ytkownik otzyma
komunikat.
*/
int *Stworz_Tablice(int size) {
	int *ptr = nullptr;
	try
	{
		ptr = new int[size];
	}
	catch (bad_alloc)
	{
		cout << "Tablica nie mog�a zosta� utworzona";
	}

	return ptr;
}
/*
>Funkcja losuje randomowa liczbe, korzystajac
z generatora nowego standaru.
*/
int Liczba_losowa(int min, int max) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int>dist(min, max);
	return dist(mt);

}
/*
>Funkcja szuka nawiekszego wsp�lnego dzielnika
za pomoc� algorytmu Euklidesa.
*/
int NWD(int a, int b)
{
	while (a != b)
		if (a > b)
			a -= b;
		else
			b -= a;
	return a;
}
/*
>Funkcja znajduje przyrost.
Znajduje losowe c, nast�pnie
szuka wyniku kt�ry jest najwi�kszym
wspo�nym dzielnikiem dw�ch liczb
*/
int SzukajPrzyrost(int m) {
	int c = 0, wynik = 0;
	do {
		c = Liczba_losowa(0, m - 1);
		wynik = NWD(c, m);
	} while (wynik != 1);
	return wynik;

}
/*
>Funcja liczby a^b mod m
*/
int Licznik_modulo(int a, int b, int m)
{
	int i;
	int result = 1;
	long int x = a%m;

	for (i = 1; i <= b; i <<= 1)
	{
		x %= m;
		if ((b&i) != 0)
		{
			result *= x;
			result %= m;
		}
		x *= x;
	}

	return result;
}
/*
>Funkcja uruchamia generator LCG
*/
void Generator_LCG(int Xmax, int n, fstream &plik) {
	cout << "/////////UWAGA DZIALA GENERATOR KONGURENTNY LCG////////////" << endl;
	int tabSize;
	int m, a, c, x_zero;
	//wyznaczam m z warunk�w zadania
	m = Xmax + 1;                                                 
	// rozkladamy na czynniki pierwsze
	int *dzielniki_pierwsze_m = Pierwsze_dzielniki(m, tabSize);           
	int *tab = Stworz_Tablice(m);
	int *tab2 = Stworz_Tablice(m);
	c = Liczba_losowa(0, Xmax);
	//sprawdzanie warunku nr1  
	SzukajPrzyrost(m);      
	//sprawdz wszystkie mo�liwe "a" czy b�dzie dla nich spe�niony warunek
	for (int a = 2; a < m; a++) {               
	//szukaj najwi�kszych lambda
		for (int lambda = 1; lambda < 50; lambda++) {                      
			if (Licznik_modulo(a, lambda, m) == 1) {
				// zapisuj lambd� do tablicy.
				tab[a] = lambda;                                           
				break;
			}
		}
	}
	int liczba_wyrazow_a = 0, pomocnicza, max = 0, j = 0;
	for (int i = 2; i < m; i++) {
		//do zmiennej pomocznicej zapisuje warto�� naszego lambda
		pomocnicza = tab[i];            
		//wyszukuj najwi�kszej lambdy z mo�liwie dost�pnych
		if (max < pomocnicza) {                                             
			max = pomocnicza;
		}
		if (tab[i] == max) {
			tab2[j] = i;                                                    
			liczba_wyrazow_a++;                                             
	// zmienna pomocnicza sie inkremetuje aby uzyska� poprawn� licz� element�w w tablicy 
			j++;                                                            
		}
	}
	int b;                                                                  
	max = 0;               
	// warunek nr3     jesli m jest wielokrotno�ci� 4 to sprawdzaj dalej
	if (m % 4 == 0) {                                                      
		for (int g = 0; g < liczba_wyrazow_a; g++) {                        
			b = tab2[g] - 1;                                                
			if ((b % 4 == 0) && (max < tab2[g])) {                          
				max = tab2[g];
			}
		}
		// drugi warunek
		for (int j = 0; j < tabSize; j++)
		{
			if (b % *(dzielniki_pierwsze_m + j) != 0);
		} // b jest wielokrotnoscia kazdej liczby pierwszej p
	}
	// w przeciwnym przypadku szukamy tylko najwi�kszego a
	else {
		for (int g = 0; g < liczba_wyrazow_a; g++) {                    
			if (max < tab2[g]) {
				max = tab2[g];
			}
		}
		cout << "Przy obecnych wsp�czynnikach generator nie ma maksymalnego okresu" << endl;
	}
	// nasze a to maksymalne a spe�niaj�ce lub niespe�niajace warunk�w
	a = max;                                                               
	//nasze ziarno jest wybierane losowo
	x_zero = Liczba_losowa(0, Xmax);                                        
	Otworz_Plik_do_zapisu_Generator_LCG(plik);                             
	for (int t = 0; t < n; ++t)
	{
		x_zero = (a * x_zero + c) % m;
		plik << x_zero << endl;
		cout << x_zero << endl;
	}
	Zamknij_Plik(plik);
}

void Zamknij_Plik(fstream &plik) {
	plik.close();
}/*
 >Funkcja uruchamia generator addytywny
 */
void Generator_addytywny(int Xmax, int n, fstream &plik) {

	int m = Xmax + 1;
	int *tablicaX = Stworz_Tablice(n);
	int *tablicaY = Stworz_Tablice(n);
	Generator_LCG(Xmax, n, plik);
	Otworz_Plik_do_odczytu(plik);
	for (int i = 0; i < n; i++) {
		// zapisuje liczby z pliku do tablicy X
		plik >> tablicaX[i];
		//tablica y posiada wartosci tablicy x zapisane od ko�ca
	} Zamiana_wartosci_w_tablicy(tablicaX, tablicaY, n);
	Zamknij_Plik(plik);
	// otwieram plik aby zapisa� liczby Addytynego generatora
	Otworz_Plik_do_zapisu_Addytywny(plik);
	int k = 0, j = 0;
	// szukam idealnego przedzia�u pasuj�cego do podanych liczb
	Rekomendowane_Pary(n, j, k);
	cout << "/////////UWAGA DZIALA GENERATOR ADDYTYWNY////////////" << endl;
	for (int i = n; i > 0; i--) {
		tablicaY[i] = (tablicaY[j] + tablicaY[k]) % m;
		plik << tablicaY[i] << endl;
		cout << tablicaY[i] << endl;
		k--;
		j--;

		if (k == 0)
			k = n;
		else if (j == 0)
			j = n;
	}
	Zamknij_Plik(plik);
}
/*
>Funkcja przeszukuje plik i szuka odpowiedniej
rekomendowanej pary spe�niaj�cej za�o�enia zadania.
Wczytuje z pliku pare liczb dop�ki indeks po prawej
miesci si� w rozmiarze tablicy.
*/
void Rekomendowane_Pary(int n, int &j, int &k) {
	ifstream plik;
	Otworz_Plik_do_odczytu_pary_liczb(plik);
	j = 0;
	k = 0;
	int pierwsza_liczba = 0, druga_liczba = 0;
	//Wczytuje z pliku pare liczb dop�ki indeks po prawej
	//miesci si� w rozmiarze tablicy.
	while (plik >> pierwsza_liczba
		&& plik >> druga_liczba
		&& druga_liczba < n) {
		j = pierwsza_liczba;
		k = druga_liczba;
	}
}
/*
>Funkcja szuka dzielnik�w pierwszych liczby m
aby sprwdzi� drugi warunek zadania
*/
int *Pierwsze_dzielniki(int n, int &rozmiarTab)
{
	int *tab = Stworz_Tablice(n), i = 0;
	int k = 2, ostatni = 0;
	while (n > 1)
	{// wykonujemy dop�ki liczba jest podzielna przez k
		while (n%k == 0)
		{//zapobiegamy powt�rzeniu sie dzielnik�w
			if (ostatni != k) *(tab + i++) = k;
			ostatni = k;
			n /= k;
		}
		++k;
	}
	rozmiarTab = i;
	int *tab2 = Stworz_Tablice(i);
	//przepisuje i element�w tablicy z dzielnikami pierwszymi
	for (int j = 0; j < i; j++)
		*(tab2 + j) = *(tab + j);
	delete[] tab;
	return tab2;
}
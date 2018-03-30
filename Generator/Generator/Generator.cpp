#include"library.cpp";

int main()
{
	int Xmax, n, wybor;
	fstream plik;
	do {
		cout << "Wprowadz gorny zakres liczb do wygenerowania: ";
		cin >> Xmax;
	} while (Xmax < 0);

	do {
		cout << "Wprowadz ilosc liczb: ";
		cin >> n;
	} while (n < 0);
	cout << "Liniowa metoda kongruencyjna. Wpisz nr1" << endl;
	cout << "Addytywna metoda kongruencyjna. Wpisz nr2 " << endl;
	cin >> wybor;

	switch (wybor)
	{
	case 1:
		Generator_LCG(Xmax, n, plik);
		break;
	case 2:
		Generator_addytywny(Xmax, n, plik);
		break;
	default:
		cout << " B³êdnie wybrana liczba;";
	}
	return 0;
}

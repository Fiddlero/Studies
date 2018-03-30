#include "exception.h"
void seeException(EXCEPTION_CODE error)
{
	switch (error) {
	case EXCEPTION_CODE::openError:
		std::cerr << "Blad otwarcia pliku odczytu\n";
		exit(0);
		break;
	case EXCEPTION_CODE::readError:
		std::cerr << "Blad odczytu z pliku lub nie prawidlowa wartosc\n";
		exit(0);
		break;
	case EXCEPTION_CODE::lackOfMemory:
		std::cerr << "Brak pamieci do stworzenia tablicy\n";
		exit(0);
		break;
	case EXCEPTION_CODE::valueOutsideOfRange:
		std::cerr << "Wartosc niedozwolona\n";
		exit(0);
		break;
	default:
		std::cerr << "Nieznany blad\n";
		exit(0);
		break;
	}
}
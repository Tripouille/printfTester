extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 17

int iTest = 1;
bool showTest = false;
int main(int ac, char ** av)
{
	int testNumber;
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "[n]" << RESET_ALL;
	
	if (ac != 1)
	{
		testNumber = atoi(av[1]);
		cout << FG_LYELLOW << "[n°" << testNumber << "]" << RESET_ALL;
		if (testNumber == 0 || testNumber > TEST_LIMIT)
			throw std::runtime_error("invalid test number");
		showTest = true;
	}
	cout << endl; int n;
	if (ac == 1 || testNumber == 1) checkn("%n");
	if (ac == 1 || testNumber == 2) checkn("%s%n", "tripouille");
	if (ac == 1 || testNumber == 3) checkn("%s%n42", "tripouille");
	if (ac == 1 || testNumber == 4) checkn("%s%i%n42", "tripouille", INT_MAX);
	if (ac == 1 || testNumber == 5) checkn("%s%i%n42", "tripouille", INT_MIN);
	if (ac == 1 || testNumber == 6) checkn("%s%x%n42", "tripouille", LONG_MAX);
	if (ac == 1 || testNumber == 7) checkn("%s%x%n42", "tripouille", LONG_MIN);
	if (ac == 1 || testNumber == 8) checkn("%s%x%n42", "", 0);
	if (ac == 1 || testNumber == 9) checkn("n%.s%x%n ", "42", -1);
	if (ac == 1 || testNumber == 10) checkn("%%n%.s%x%n ", "42", -1);
	if (ac == 1 || testNumber == 11) checkn("%%n%.s%p%n ", "42", (void*)1);
	if (ac == 1 || testNumber == 12) checkn("%.s%n", "12345");
	if (ac == 1 || testNumber == 13) checkn("%s%c42%n", "12345", 0);
	if (ac == 1 || testNumber == 14) checkn("%s%c42%n", "12345", 0);
	if (ac == 1 || testNumber == 15) checkn("%s%c42%n", "12345", 'A');
	if (ac == 1 || testNumber == 16) checkn("%s%d42%n", "12345", -42);
	if (ac == 1 || testNumber == 17) checkn("%s%X42%n", "12345", 42);
	cout << ENDL;
	return (0);
}
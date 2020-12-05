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
	cout << FG_LYELLOW << "[p]" << RESET_ALL;
	
	if (ac != 1)
	{
		testNumber = atoi(av[1]);
		cout << FG_LYELLOW << "[n°" << testNumber << "]" << RESET_ALL;
		if (testNumber == 0 || testNumber > TEST_LIMIT)
			throw std::runtime_error("invalid test number");
		showTest = true;
	}
	cout << endl;
	if (ac == 1 || testNumber == 1) print(" %p ", -1);
	if (ac == 1 || testNumber == 2) print(" %p ", 1);
	if (ac == 1 || testNumber == 3) print(" %p ", 15);
	if (ac == 1 || testNumber == 4) print(" %p ", 16);
	if (ac == 1 || testNumber == 5) print(" %p ", 17);
	if (ac == 1 || testNumber == 6) print(" %10p %10p ", 1, -1);
	if (ac == 1 || testNumber == 7) print(" %-10p %10p ", 1, -1);
	if (ac == 1 || testNumber == 8) print(" %10p %-10p ", 1, -1);
	if (ac == 1 || testNumber == 9) print(" %-10p %-10p ", 1, -1);
	if (ac == 1 || testNumber == 10) print(" %10p %-10p ", 1, -1);
	if (ac == 1 || testNumber == 11) print(" %p %p ", 1, -1);
	if (ac == 1 || testNumber == 12) print(" %p %p ", 1, -1);
	if (ac == 1 || testNumber == 13) print(" %p %p ", LONG_MIN, LONG_MAX);
	if (ac == 1 || testNumber == 14) print(" %p %p ", INT_MIN, INT_MAX);
	if (ac == 1 || testNumber == 15) print(" %p %p ", ULONG_MAX, -ULONG_MAX);
	if (ac == 1 || testNumber == 16) print(" %*p %-*p ", -10, 101, -10, 42);
	if (ac == 1 || testNumber == 17) print(" .-0*%*p %-*p*0-. ", 11, 101, 11, 42);
	cout << ENDL;
	return (0);
}
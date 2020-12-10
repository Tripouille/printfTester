extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 47

int iTest = 1;
bool showTest = false;
int main(int ac, char ** av)
{
	int testNumber;
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "[f]" << RESET_ALL;
	
	if (ac != 1)
	{
		testNumber = atoi(av[1]);
		cout << FG_LYELLOW << "[n°" << testNumber << "]" << RESET_ALL;
		if (testNumber == 0 || testNumber > TEST_LIMIT)
			throw std::runtime_error("invalid test number");
		showTest = true;
	}
	cout << endl; int n;
	if (ac == 1 || testNumber == 1) print(" %f %f ", 42.0, -42.0);
	if (ac == 1 || testNumber == 2) print(" %8f %9f %10f ", 42.0, -42.0, 42.0);
	if (ac == 1 || testNumber == 3) print(" %7f %8f %9f ", 0.0, -1.0, 1.0);
	if (ac == 1 || testNumber == 4) print(" %7.f %8.1f %9.2f ", 0.0, -1.0, 1.0);
	if (ac == 1 || testNumber == 5) print(" %7.f %8.1f %9.2f ", 0.0, -1.0, 0.0);
	if (ac == 1 || testNumber == 6) print(" %-7.f %-8.1f %-9.2f ", 0.0, -1.0, 0.0);
	if (ac == 1 || testNumber == 7) print(" %-7.f %-8.1f %-9.2f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 8) print(" %07.f %08.1f %09.2f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 9) print(" %01.f %01.1f %01.2f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 10) print(" %02.f %02.1f %02.2f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 11) print(" %-02.f %-02.1f %-02.2f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 12) print(" %-02.1f %-02.1f %-02.1f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 13) print(" %-02.2f %-02.2f %-02.2f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 14) print(" %-02.3f %-02.3f %-02.3f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 15) print(" %-03.3f %-03.3f %-03.3f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 16) print(" %-04.3f %-04.3f %-04.3f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 17) print(" %-4.3f %-4.3f %-4.3f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 18) print(" %-5.3f %-5.3f %-5.3f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 19) print(" %-6.3f %-6.3f %-6.3f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 20) print(" %-06.3f %-06.3f %-06.3f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 21) print(" %06.3f %06.3f %06.3f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 22) print(" %05.3f %05.3f %05.3f ", 0.0, -1.0, 42.0);
	if (ac == 1 || testNumber == 23) print(" %05.3f %05.3f %05.3f ", 42.0, 420.0, -420.0);
	if (ac == 1 || testNumber == 24) print(" %f %f ", LONG_MIN * 1.0, LONG_MAX * 1.0);
	if (ac == 1 || testNumber == 25) print(" %.32f %.32f ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901);
	if (ac == 1 || testNumber == 26) print(" %32.32f %32.32f ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901);
	if (ac == 1 || testNumber == 27) print(" %33.32f %33.32f ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901);
	if (ac == 1 || testNumber == 28) print(" %.f ", 42.101);
	if (ac == 1 || testNumber == 29) print(" %f ", 0.101);
	if (ac == 1 || testNumber == 30) print(" %10f ", 1.0 / 0);
	if (ac == 1 || testNumber == 31) print(" %10.10f ", 1.0 / 0);
	if (ac == 1 || testNumber == 32) print(" %0.20f ", 1.0 / 0);
	if (ac == 1 || testNumber == 33) print(" %020.20f ", 1.0 / 0);
	if (ac == 1 || testNumber == 34) print(" %-020.20f ", 1.0 / 0);
	if (ac == 1 || testNumber == 35) print(" %-20.f ", 1.0 / 0);
	if (ac == 1 || testNumber == 36) print(" %10f ", -1.0 / 0);
	if (ac == 1 || testNumber == 37) print(" %10.10f ", -1.0 / 0);
	if (ac == 1 || testNumber == 38) print(" %0.20f ", -1.0 / 0);
	if (ac == 1 || testNumber == 39) print(" %020.20f ", -1.0 / 0);
	if (ac == 1 || testNumber == 40) print(" %-020.20f ", -1.0 / 0);
	if (ac == 1 || testNumber == 41) print(" %-20.f ", -1.0 / 0);
	if (ac == 1 || testNumber == 42) print(" %10f ", 0.0 / 0);
	if (ac == 1 || testNumber == 43) print(" %10.10f ", 0.0 / 0);
	if (ac == 1 || testNumber == 44) print(" %0.20f ", 0.0 / 0);
	if (ac == 1 || testNumber == 45) print(" %020.20f ", 0.0 / 0);
	if (ac == 1 || testNumber == 46) print(" %-020.20f ", 0.0 / 0);
	if (ac == 1 || testNumber == 47) print(" %-20.f ", 0.0 / 0);
	cout << ENDL;
	return (0);
}
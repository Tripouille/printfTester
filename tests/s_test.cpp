extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 33

int iTest = 1;
bool showTest = false;
int main(int ac, char ** av)
{
	int testNumber;
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "[s]" << RESET_ALL;
	
	if (ac != 1)
	{
		testNumber = atoi(av[1]);
		cout << FG_LYELLOW << "[n°" << testNumber << "]" << RESET_ALL;
		if (testNumber == 0 || testNumber > TEST_LIMIT)
			throw std::runtime_error("invalid test number");
		showTest = true;
	}
	cout << endl;
	if (ac == 1 || testNumber == 1) print("%s", "");
	if (ac == 1 || testNumber == 2) print("%s", "0");
	if (ac == 1 || testNumber == 3) print("%s %s", "", "");
	if (ac == 1 || testNumber == 4) print("%s %s", "0", "1");
	if (ac == 1 || testNumber == 5) print(" %s %s ", "0", "1");
	if (ac == 1 || testNumber == 6) print(" %s %s ", "", "");
	if (ac == 1 || testNumber == 7) print(" %1s %1s ", "123", "4567");
	if (ac == 1 || testNumber == 8) print(" %4s %4s ", "123", "4567");
	if (ac == 1 || testNumber == 9) print(" %-4s %4s ", "123", "4567");
	if (ac == 1 || testNumber == 10) print(" %4s %-4s ", "123", "4567");
	if (ac == 1 || testNumber == 11) print(" %-4s %-4s ", "123", "4567");
	if (ac == 1 || testNumber == 12) print(" %-4s %-4s ", "123", "4567");
	if (ac == 1 || testNumber == 13) print(" %*s %*s ", 1, "123", 10, "4567");
	if (ac == 1 || testNumber == 14) print(" *%s %*s ", "123", 10, "4567");
	if (ac == 1 || testNumber == 15) print(" %*s %s ", 10, "123", "4567");
	if (ac == 1 || testNumber == 16) print(" %*.s %.1s ", 10, "123", "4567");
	if (ac == 1 || testNumber == 17) print(" %*.0s %.2s ", 10, "123", "4567");
	if (ac == 1 || testNumber == 18) print(" %*.3s %.3s ", 10, "123", "4567");
	if (ac == 1 || testNumber == 19) print(" %*.4s %.4s ", 10, "123", "4567");
	if (ac == 1 || testNumber == 20) print(" %*.5s %.5s ", 10, "123", "4567");
	if (ac == 1 || testNumber == 21) print(" %*.5s %*.5s ", 10, "123", 10, "4567");
	if (ac == 1 || testNumber == 22) print(" %*.5s %*.5s ", -10, "123", 10, "4567");
	if (ac == 1 || testNumber == 23) print(" %*.5s %*.5s ", 10, "123", -10, "4567");
	if (ac == 1 || testNumber == 24) print(" %*.5s %*.5s ", -10, "123", -10, "4567");
	if (ac == 1 || testNumber == 25) print(" %10.s %1.s ", "123", "4567");
	if (ac == 1 || testNumber == 26) print(" %0.s %0.s ", "123", "4567");
	if (ac == 1 || testNumber == 27) print(" %.s %.s ", "123", "4567");
	if (ac == 1 || testNumber == 28) print(" %3.3s %3.3s ", "123", "4567");
	if (ac == 1 || testNumber == 29) print(" %4.3s %-4.3s ", "123", "4567");
	if (ac == 1 || testNumber == 30) print("%.s", "");
	if (ac == 1 || testNumber == 31) print("%.0s", "");
	if (ac == 1 || testNumber == 32) print("%.1s", "");
	if (ac == 1 || testNumber == 33) print(" %4.2s %-4.2s ", "123", "4567");
	cout << ENDL;
	return (0);
}
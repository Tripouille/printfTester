extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 29

int iTest = 1;
bool showTest = false;
int main(int ac, char ** av)
{
	int testNumber;
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "[%]" << RESET_ALL;
	
	if (ac != 1)
	{
		testNumber = atoi(av[1]);
		cout << FG_LYELLOW << "[n°" << testNumber << "]" << RESET_ALL;
		if (testNumber == 0 || testNumber > TEST_LIMIT)
			throw std::runtime_error("invalid test number");
		showTest = true;
	}
	cout << endl;
	if (ac == 1 || testNumber == 1) print(" %% ");
	if (ac == 1 || testNumber == 2) print(" %%%% ");
	if (ac == 1 || testNumber == 3) print(" %%%%%% ");
	if (ac == 1 || testNumber == 4) print(" %1% ");
	if (ac == 1 || testNumber == 5) print(" %2% ");
	if (ac == 1 || testNumber == 6) print(" %10% ");
	if (ac == 1 || testNumber == 7) print(" %-1% ");
	if (ac == 1 || testNumber == 8) print(" %-2% ");
	if (ac == 1 || testNumber == 9) print(" %-10% ");
	if (ac == 1 || testNumber == 10) print(" -%%- ");
	if (ac == 1 || testNumber == 11) print(" *%%* ");
	if (ac == 1 || testNumber == 12) print(" 0%%0 ");
	if (ac == 1 || testNumber == 13) print(" %% ");
	if (ac == 1 || testNumber == 14) print(" %0% ");
	if (ac == 1 || testNumber == 15) print(" %1% ");
	if (ac == 1 || testNumber == 16) print(" %2% ");
	if (ac == 1 || testNumber == 17) print(" %10% ");
	if (ac == 1 || testNumber == 18) print(" %-1% ");
	if (ac == 1 || testNumber == 19) print(" %-10% ");
	if (ac == 1 || testNumber == 20) print(" %-2% ");
	if (ac == 1 || testNumber == 21) print(" %-20% ");
	if (ac == 1 || testNumber == 22) print(" %-10% ");
	if (ac == 1 || testNumber == 23) print("  %-*%  %*% ", 10, 20, 20, 10);
	if (ac == 1 || testNumber == 24) print("  %-*%  %*% ", -20, 10, -20, 10);
	if (ac == 1 || testNumber == 25) print("  *0-%-*%  %*%-0* ", 10, 20);
	if (ac == 1 || testNumber == 26) print("  *0-%-*%  %*%-0* ", 4, 5);
	if (ac == 1 || testNumber == 27) print("  *0-%-*%  %*%-0* ", 5, 3);
	if (ac == 1 || testNumber == 28) print("  *0-%-*%  %*%-0* ", 10, 10);
	if (ac == 1 || testNumber == 29) print("  *0-%-*%  %*%-0* ", -20, -20);
	cout << ENDL;
	return (0);
}
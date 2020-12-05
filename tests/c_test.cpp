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
	cout << FG_LYELLOW << "[c]" << RESET_ALL;
	
	if (ac != 1)
	{
		testNumber = atoi(av[1]);
		cout << FG_LYELLOW << "[n°" << testNumber << "]" << RESET_ALL;
		if (testNumber == 0 || testNumber > TEST_LIMIT)
			throw std::runtime_error("invalid test number");
		showTest = true;
	}
	cout << endl;
	if (ac == 1 || testNumber == 1) print("%c", '0');
	if (ac == 1 || testNumber == 2) print(" %c ", '0');
	if (ac == 1 || testNumber == 3) print("10%c", '0');
	if (ac == 1 || testNumber == 4) print("%10c", '0');
	if (ac == 1 || testNumber == 5) print("-10%c", '0');
	if (ac == 1 || testNumber == 6) print("%-10c", '0');
	if (ac == 1 || testNumber == 7) print("%-10c", '0');
	if (ac == 1 || testNumber == 8) print("%*c", 1, '0');
	if (ac == 1 || testNumber == 9) print("%*c", 0, '0');
	if (ac == 1 || testNumber == 10) print("%*c", 2, '0');
	if (ac == 1 || testNumber == 11) print("%*c", -2, '0');
	if (ac == 1 || testNumber == 12) print("%*c", 0, '0');
	if (ac == 1 || testNumber == 13) print("%*c", 10, '0');
	if (ac == 1 || testNumber == 14) print("%*c", -10, '0');
	if (ac == 1 || testNumber == 15) print("%*c%*c", -10, '0', 10, '1');
	if (ac == 1 || testNumber == 16) print("*%c%*c", '0', 10, '1');
	if (ac == 1 || testNumber == 17) print("%*c%c*", -10, '0', '1');
	if (ac == 1 || testNumber == 18) print("%-10c*",'0');
	if (ac == 1 || testNumber == 19) print("%-10c%*c%c*",'0', 10, '1', '2');
	if (ac == 1 || testNumber == 20) print("%c%c%c*",'0', '1', '2');
	if (ac == 1 || testNumber == 21) print("%-c%-c%c*", 1, '0', 0);
	if (ac == 1 || testNumber == 22) print("%c", '0' - 256);
	if (ac == 1 || testNumber == 23) print("%c", '0' + 256);
	if (ac == 1 || testNumber == 24) print("%c", 0);
	if (ac == 1 || testNumber == 25) print("0%c", 0);
	if (ac == 1 || testNumber == 26) print("%c", -129);
	if (ac == 1 || testNumber == 27) print("%c", 128);
	if (ac == 1 || testNumber == 28) print("%-*c", 10, "1");
	if (ac == 1 || testNumber == 29) print("%-*c", -10, "1");
	cout << ENDL;
	return (0);
}
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
	cout << FG_LYELLOW << "[mix]" << RESET_ALL;
	
	if (ac != 1)
	{
		testNumber = atoi(av[1]);
		cout << FG_LYELLOW << "[n°" << testNumber << "]" << RESET_ALL;
		if (testNumber == 0 || testNumber > TEST_LIMIT)
			throw std::runtime_error("invalid test number");
		showTest = true;
	}
	cout << endl;
	if (ac == 1 || testNumber == 1) print("");
	if (ac == 1 || testNumber == 2) print("ccccc");
	if (ac == 1 || testNumber == 3) print("ddddd");
	if (ac == 1 || testNumber == 4) print("ppppp");
	if (ac == 1 || testNumber == 5) print(" %%c%%s%%p%%d%%i%%u%%x%%X%% ");
	if (ac == 1 || testNumber == 6) print(" a%c%%c%%s%%p%%d%%i%%u%%x%%X%% ", 0);
	if (ac == 1 || testNumber == 7) print(" coucou ");
	if (ac == 1 || testNumber == 8) print(" a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%p", 0, (void *)42);
	if (ac == 1 || testNumber == 9) print(" a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%s", 0, "");
	if (ac == 1 || testNumber == 10) print("%%%%%%%%%%%%%%%%%s%%%s%%%s", "", "", "");
	if (ac == 1 || testNumber == 11) print("%scoucou", "");
	if (ac == 1 || testNumber == 12) print("%scoucou%s", "a", "b");
	if (ac == 1 || testNumber == 13) print("%scoucou%s", "", "");
	if (ac == 1 || testNumber == 14) print("%s", NULL);
	if (ac == 1 || testNumber == 15) print(" 10%s ", "42");
	/*if (ac == 1 || testNumber == 15) print();
	if (ac == 1 || testNumber == 16) print();
	if (ac == 1 || testNumber == 17) print();
	if (ac == 1 || testNumber == 18) print();
	if (ac == 1 || testNumber == 19) print();
	if (ac == 1 || testNumber == 20) print();
	if (ac == 1 || testNumber == 21) print();
	if (ac == 1 || testNumber == 22) print();
	if (ac == 1 || testNumber == 23) print();
	if (ac == 1 || testNumber == 24) print();
	if (ac == 1 || testNumber == 25) print();
	if (ac == 1 || testNumber == 26) print();
	if (ac == 1 || testNumber == 27) print();
	if (ac == 1 || testNumber == 28) print();
	if (ac == 1 || testNumber == 29) print();
	if (ac == 1 || testNumber == 30) print();
	if (ac == 1 || testNumber == 31) print();
	if (ac == 1 || testNumber == 32) print();
	if (ac == 1 || testNumber == 33) print();*/
	cout << ENDL;
	return (0);
}
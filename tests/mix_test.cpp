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
	if (ac == 1 || testNumber == 7) print(" Tripouille ");
	if (ac == 1 || testNumber == 8) print(" a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%p", 0, (void *)42);
	if (ac == 1 || testNumber == 9) print(" a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%s", 0, "");
	if (ac == 1 || testNumber == 10) print("%%%%%%%%%%%%%%%%%s%%%s%%%s", "", "", "");
	if (ac == 1 || testNumber == 11) print("%s+", "");
	if (ac == 1 || testNumber == 12) print("%sChinimala%s", "xXx ", " xXx");
	if (ac == 1 || testNumber == 13) print("%s = <3 %s", "", "");
	if (ac == 1 || testNumber == 14) print("%s", NULL);
	if (ac == 1 || testNumber == 15) print(" 10%s ", "42");
	if (ac == 1 || testNumber == 16) print("%.4s%.s", "12345", "12345");
	if (ac == 1 || testNumber == 17) print("%10.4s%.5s", "12345", "12345");
	if (ac == 1 || testNumber == 18) print("%10.4s%s", "12345", "12345");
	if (ac == 1 || testNumber == 19) print("s%10.4s%ss", "12345", "54321");
	if (ac == 1 || testNumber == 20) print("0%10.4s0%ss", "12345", "54321");
	if (ac == 1 || testNumber == 21) print("*%10.4s*%ss", "1", "5");
	if (ac == 1 || testNumber == 22) print("%%*.s%10.4s*%ss", "1", "5");
	if (ac == 1 || testNumber == 23) print("%%*.s%10.4s%%*.s*%ss%%*.s", "1", "5");
	if (ac == 1 || testNumber == 24) print("%%*.s%c%%*.s*%ss%%*.s", 0, "5");
	if (ac == 1 || testNumber == 25) print("%%*.s%c%%*.s*%ss%%*.s", '2', "");
	if (ac == 1 || testNumber == 26) print("%%*.s%c%%*.s*%ss%%*.s", '0', "  ");
	if (ac == 1 || testNumber == 27) print("%.5s%.s", "12345", "12345");
	if (ac == 1 || testNumber == 28) print("%%*.c%c%%*.s*%ps%%*.X", '0', NULL);
	if (ac == 1 || testNumber == 29) print("%%%s%c%%c", "", 0);
	if (ac == 1 || testNumber == 30) print("%10.*i%*.10i", 7, 42, 8, -42);
	if (ac == 1 || testNumber == 31) print(" %% %% %% %% %c %%cc%%cc%%%c ", -1, 0);
	if (ac == 1 || testNumber == 32) print(" %%* *%%. %%* *%%. .-%c -%%*cc*%%c*c%%%c %s%%%c", -1, 1, "Tripouille", 0);
	if (ac == 1 || testNumber == 33) print("xXx%x%XxXx%%xXx%x%X", 15, 15, 16, 16);
	cout << ENDL;
	return (0);
}
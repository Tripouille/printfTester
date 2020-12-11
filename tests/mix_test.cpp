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
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: mix" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(""));
	TEST(2, print("ccccc"));
	TEST(3, print("ddddd"));
	TEST(4, print("ppppp"));
	TEST(5, print(" %%c%%s%%p%%d%%i%%u%%x%%X%% "));
	TEST(6, print(" a%c%%c%%s%%p%%d%%i%%u%%x%%X%% ", 0));
	TEST(7, print(" Tripouille "));
	TEST(8, print(" a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%p", 0, (void *)42));
	TEST(9, print(" a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%s", 0, ""));
	TEST(10, print("%%%%%%%%%%%%%%%%%s%%%s%%%s", "", "", ""));
	TEST(11, print("%s+", ""));
	TEST(12, print("%sChinimala%s", "xXx ", " xXx"));
	TEST(13, print("%s = <3 %s", "", ""));
	TEST(14, print("%s", NULL));
	TEST(15, print(" 10%s ", "42"));
	TEST(16, print("%.4s%.s", "12345", "12345"));
	TEST(17, print("%10.4s%.5s", "12345", "12345"));
	TEST(18, print("%10.4s%s", "12345", "12345"));
	TEST(19, print("s%10.4s%ss", "12345", "54321"));
	TEST(20, print("0%10.4s0%ss", "12345", "54321"));
	TEST(21, print("*%10.4s*%ss", "1", "5"));
	TEST(22, print("%%*.s%10.4s*%ss", "1", "5"));
	TEST(23, print("%%*.s%10.4s%%*.s*%ss%%*.s", "1", "5"));
	TEST(24, print("%%*.s%c%%*.s*%ss%%*.s", 0, "5"));
	TEST(25, print("%%*.s%c%%*.s*%ss%%*.s", '2', ""));
	TEST(26, print("%%*.s%c%%*.s*%ss%%*.s", '0', "  "));
	TEST(27, print("%.5s%.s", "12345", "12345"));
	TEST(28, print("%%*.c%c%%*.s*%ps%%*.X", '0', NULL));
	TEST(29, print("%%%s%c%%c", "", 0));
	TEST(30, print("%10.*i%*.10i", 7, 42, 8, -42));
	TEST(31, print(" %% %% %% %% %c %%cc%%cc%%%c ", -1, 0));
	TEST(32, print(" %%* *%%. %%* *%%. .-%c -%%*cc*%%c*c%%%c %s%%%c", -1, 1, "Tripouille", 0));
	TEST(33, print("xXx%x%XxXx%%xXx%x%X", 15, 15, 16, 16));
	cout << ENDL;
	return (0);
}
extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 31

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: X" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %X ", 0));
	TEST(2, print(" %X ", -1));
	TEST(3, print(" %X ", 1));
	TEST(4, print(" %X ", 9));
	TEST(5, print(" %X ", 10));
	TEST(6, print(" %X ", 11));
	TEST(7, print(" %X ", 15));
	TEST(8, print(" %X ", 16));
	TEST(9, print(" %X ", 17));
	TEST(10, print(" %X ", 99));
	TEST(11, print(" %X ", 100));
	TEST(12, print(" %X ", 101));
	TEST(13, print(" %X ", -9));
	TEST(14, print(" %X ", -10));
	TEST(15, print(" %X ", -11));
	TEST(16, print(" %X ", -14));
	TEST(17, print(" %X ", -15));
	TEST(18, print(" %X ", -16));
	TEST(19, print(" %X ", -99));
	TEST(20, print(" %X ", -100));
	TEST(21, print(" %X ", -101));
	TEST(22, print(" %X ", INT_MAX));
	TEST(23, print(" %X ", INT_MIN));
	TEST(24, print(" %X ", LONG_MAX));
	TEST(25, print(" %X ", LONG_MIN));
	TEST(26, print(" %X ", UINT_MAX));
	TEST(27, print(" %X ", ULONG_MAX));
	TEST(28, print(" %X ", 9223372036854775807LL));
	TEST(29, print(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(30, print(" %X ", 42));
	TEST(31, print(" %X ", -42));
	cout << ENDL;
	return (0);
}
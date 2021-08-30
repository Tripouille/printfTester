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
	cout << FG_LYELLOW << "category: x" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %x ", 0));
	TEST(2, print(" %x ", -1));
	TEST(3, print(" %x ", 1));
	TEST(4, print(" %x ", 9));
	TEST(5, print(" %x ", 10));
	TEST(6, print(" %x ", 11));
	TEST(7, print(" %x ", 15));
	TEST(8, print(" %x ", 16));
	TEST(9, print(" %x ", 17));
	TEST(10, print(" %x ", 99));
	TEST(11, print(" %x ", 100));
	TEST(12, print(" %x ", 101));
	TEST(13, print(" %x ", -9));
	TEST(14, print(" %x ", -10));
	TEST(15, print(" %x ", -11));
	TEST(16, print(" %x ", -14));
	TEST(17, print(" %x ", -15));
	TEST(18, print(" %x ", -16));
	TEST(19, print(" %x ", -99));
	TEST(20, print(" %x ", -100));
	TEST(21, print(" %x ", -101));
	TEST(22, print(" %x ", INT_MAX));
	TEST(23, print(" %x ", INT_MIN));
	TEST(24, print(" %x ", LONG_MAX));
	TEST(25, print(" %x ", LONG_MIN));
	TEST(26, print(" %x ", UINT_MAX));
	TEST(27, print(" %x ", ULONG_MAX));
	TEST(28, print(" %x ", 9223372036854775807LL));
	TEST(29, print(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(30, print(" %x ", 42));
	TEST(31, print(" %x ", -42));
	cout << ENDL;
	return (0);
}
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
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: i" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %i ", 0));
	TEST(2, print(" %i ", -1));
	TEST(3, print(" %i ", 1));
	TEST(4, print(" %i ", 9));
	TEST(5, print(" %i ", 10));
	TEST(6, print(" %i ", 11));
	TEST(7, print(" %i ", 15));
	TEST(8, print(" %i ", 16));
	TEST(9, print(" %i ", 17));
	TEST(10, print(" %i ", 99));
	TEST(11, print(" %i ", 100));
	TEST(12, print(" %i ", 101));
	TEST(13, print(" %i ", -9));
	TEST(14, print(" %i ", -10));
	TEST(15, print(" %i ", -11));
	TEST(16, print(" %i ", -14));
	TEST(17, print(" %i ", -15));
	TEST(18, print(" %i ", -16));
	TEST(19, print(" %i ", -99));
	TEST(20, print(" %i ", -100));
	TEST(21, print(" %i ", -101));
	TEST(22, print(" %i ", INT_MAX));
	TEST(23, print(" %i ", INT_MIN));
	TEST(24, print(" %i ", LONG_MAX));
	TEST(25, print(" %i ", LONG_MIN));
	TEST(26, print(" %i ", UINT_MAX));
	TEST(27, print(" %i ", ULONG_MAX));
	TEST(28, print(" %i ", 9223372036854775807LL));
	TEST(29, print(" %i %i %i %i %i %i %i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	cout << ENDL;
	return (0);
}
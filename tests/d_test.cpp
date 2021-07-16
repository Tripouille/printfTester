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
	cout << FG_LYELLOW << "category: d" << RESET_ALL;

	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %d ", 0));
	TEST(2, print(" %d ", -1));
	TEST(3, print(" %d ", 1));
	TEST(4, print(" %d ", 9));
	TEST(5, print(" %d ", 10));
	TEST(6, print(" %d ", 11));
	TEST(7, print(" %d ", 15));
	TEST(8, print(" %d ", 16));
	TEST(9, print(" %d ", 17));
	TEST(10, print(" %d ", 99));
	TEST(11, print(" %d ", 100));
	TEST(12, print(" %d ", 101));
	TEST(13, print(" %d ", -9));
	TEST(14, print(" %d ", -10));
	TEST(15, print(" %d ", -11));
	TEST(16, print(" %d ", -14));
	TEST(17, print(" %d ", -15));
	TEST(18, print(" %d ", -16));
	TEST(19, print(" %d ", -99));
	TEST(20, print(" %d ", -100));
	TEST(21, print(" %d ", -101));
	TEST(22, print(" %d ", INT_MAX));
	TEST(23, print(" %d ", INT_MIN));
	TEST(24, print(" %d ", LONG_MAX));
	TEST(25, print(" %d ", LONG_MIN));
	TEST(26, print(" %d ", UINT_MAX));
	TEST(27, print(" %d ", ULONG_MAX));
	TEST(28, print(" %d ", 9223372036854775807LL));
	TEST(29, print(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	cout << ENDL;
	return (0);
}
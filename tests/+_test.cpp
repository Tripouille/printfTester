extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 56

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: +" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	SUBCATEGORY(1, 28, cout << endl << FG_LGRAY << "subcategory: d" << RESET_ALL << endl;)
	TEST(1, print(" %+d ", 0));
	TEST(2, print(" %+d ", -1));
	TEST(3, print(" %+d ", 9));
	TEST(4, print(" %+d ", 10));
	TEST(5, print(" %+d ", 11));
	TEST(6, print(" %+d ", 15));
	TEST(7, print(" %+d ", 16));
	TEST(8, print(" %+d ", 17));
	TEST(9, print(" %+d ", 99));
	TEST(10, print(" %+d ", 100));
	TEST(11, print(" %+d ", 101));
	TEST(12, print(" %+d ", -9));
	TEST(13, print(" %+d ", -10));
	TEST(14, print(" %+d ", -11));
	TEST(15, print(" %+d ", -14));
	TEST(16, print(" %+d ", -15));
	TEST(17, print(" %+d ", -16));
	TEST(18, print(" %+d ", -99));
	TEST(19, print(" %+d ", -100));
	TEST(20, print(" %+d ", -101));
	TEST(21, print(" %+d ", INT_MAX));
	TEST(22, print(" %+d ", INT_MIN));
	TEST(23, print(" %+d ", LONG_MAX));
	TEST(24, print(" %+d ", LONG_MIN));
	TEST(25, print(" %+d ", UINT_MAX));
	TEST(26, print(" %+d ", ULONG_MAX));
	TEST(27, print(" %+d ", 9223372036854775807LL));
	TEST(28, print(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(29, 56, cout << endl << FG_LGRAY << "subcategory: i" << RESET_ALL << endl;)
	TEST(29, print(" %+i ", 0));
	TEST(30, print(" %+i ", -1));
	TEST(31, print(" %+i ", 1));
	TEST(32, print(" %+i ", 9));
	TEST(33, print(" %+i ", 10));
	TEST(34, print(" %+i ", 11));
	TEST(35, print(" %+i ", 15));
	TEST(36, print(" %+i ", 16));
	TEST(37, print(" %+i ", 17));
	TEST(38, print(" %+i ", 99));
	TEST(39, print(" %+i ", 100));
	TEST(40, print(" %+i ", 101));
	TEST(41, print(" %+i ", -9));
	TEST(41, print(" %+i ", -10));
	TEST(42, print(" %+i ", -11));
	TEST(43, print(" %+i ", -14));
	TEST(44, print(" %+i ", -15));
	TEST(45, print(" %+i ", -16));
	TEST(46, print(" %+i ", -99));
	TEST(47, print(" %+i ", -100));
	TEST(48, print(" %+i ", -101));
	TEST(49, print(" %+i ", INT_MAX));
	TEST(50, print(" %+i ", INT_MIN));
	TEST(51, print(" %+i ", LONG_MAX));
	TEST(52, print(" %+i ", LONG_MIN));
	TEST(53, print(" %+i ", UINT_MAX));
	TEST(54, print(" %+i ", ULONG_MAX));
	TEST(55, print(" %+i ", 9223372036854775807LL));
	TEST(56, print(" %+i %+i %+i %+i %+i %+i %+i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	cout << ENDL;
	return (0);
}
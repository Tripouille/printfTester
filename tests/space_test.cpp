extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 67

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: ' '" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	SUBCATEGORY(1, 9, cout << endl << FG_LGRAY << "subcategory: s" << RESET_ALL << endl;)
	TEST(1, print("% s", ""));
	TEST(2, print(" % 1s", ""));
	TEST(3, print("% 1s ", ""));
	TEST(4, print(" % s ", ""));
	TEST(5, print(" % s ", "-"));
	TEST(6, print(" % s % s ", "", "-"));
	TEST(7, print(" % s % s ", " - ", ""));
	TEST(8, print(" % s % s % s % s ", " - ", "", "4", ""));
	TEST(9, print(" % s % s % s % s % s ", " - ", "", "4", "", "2 "));
	SUBCATEGORY(10, 38, cout << endl << FG_LGRAY << "subcategory: d" << RESET_ALL << endl;)
	TEST(10, print(" % d ", 0));
	TEST(11, print(" % d ", -1));
	TEST(12, print(" % d ", 1));
	TEST(13, print(" % d ", 9));
	TEST(14, print(" % d ", 10));
	TEST(15, print(" % d ", 11));
	TEST(16, print(" % d ", 15));
	TEST(17, print(" % d ", 16));
	TEST(18, print(" % d ", 17));
	TEST(19, print(" % d ", 99));
	TEST(20, print(" % d ", 100));
	TEST(21, print(" % d ", 101));
	TEST(22, print(" % d ", -9));
	TEST(23, print(" % d ", -10));
	TEST(24, print(" % d ", -11));
	TEST(25, print(" % d ", -14));
	TEST(26, print(" % d ", -15));
	TEST(27, print(" % d ", -16));
	TEST(28, print(" % d ", -99));
	TEST(29, print(" % d ", -100));
	TEST(30, print(" % d ", -101));
	TEST(31, print(" % d ", INT_MAX));
	TEST(32, print(" % d ", INT_MIN));
	TEST(33, print(" % d ", LONG_MAX));
	TEST(34, print(" % d ", LONG_MIN));
	TEST(35, print(" % d ", UINT_MAX));
	TEST(36, print(" % d ", ULONG_MAX));
	TEST(37, print(" % d ", 9223372036854775807LL));
	TEST(38, print(" % d % d % d % d % d % d % d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(39, 67, cout << endl << FG_LGRAY << "subcategory: i" << RESET_ALL << endl;)
	TEST(39, print(" % i ", 0));
	TEST(40, print(" % i ", -1));
	TEST(41, print(" % i ", 1));
	TEST(42, print(" % i ", 9));
	TEST(43, print(" % i ", 10));
	TEST(44, print(" % i ", 11));
	TEST(45, print(" % i ", 15));
	TEST(46, print(" % i ", 16));
	TEST(47, print(" % i ", 17));
	TEST(48, print(" % i ", 99));
	TEST(49, print(" % i ", 100));
	TEST(50, print(" % i ", 101));
	TEST(51, print(" % i ", -9));
	TEST(52, print(" % i ", -10));
	TEST(53, print(" % i ", -11));
	TEST(54, print(" % i ", -14));
	TEST(55, print(" % i ", -15));
	TEST(56, print(" % i ", -16));
	TEST(57, print(" % i ", -99));
	TEST(58, print(" % i ", -100));
	TEST(59, print(" % i ", -101));
	TEST(60, print(" % i ", INT_MAX));
	TEST(61, print(" % i ", INT_MIN));
	TEST(62, print(" % i ", LONG_MAX));
	TEST(63, print(" % i ", LONG_MIN));
	TEST(64, print(" % i ", UINT_MAX));
	TEST(65, print(" % i ", ULONG_MAX));
	TEST(66, print(" % i ", 9223372036854775807LL));
	TEST(67, print(" % i % i % i % i % i % i % i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	cout << ENDL;
	return (0);
}
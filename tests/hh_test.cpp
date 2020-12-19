extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 19
#define UCHAR_MIN (0)

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: hh" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	SUBCATEGORY(1, 4, cout << endl << FG_LGRAY << "subcategory: d" << RESET_ALL << endl;)
	TEST(1, print(" %hhd ", CHAR_MAX));
	TEST(2, print(" %hhd ", CHAR_MIN));
	TEST(3, print(" %hhd ", CHAR_MAX + 1));
	TEST(4, print(" %hhd ", CHAR_MIN - 1));
	SUBCATEGORY(5, 8, cout << endl << FG_LGRAY << "subcategory: i" << RESET_ALL << endl;)
	TEST(5, print(" %hhi ", CHAR_MAX));
	TEST(6, print(" %hhi ", CHAR_MIN));
	TEST(7, print(" %hhi ", CHAR_MAX + 1));
	TEST(8, print(" %hhi ", CHAR_MIN - 1));
	SUBCATEGORY(9, 11, cout << endl << FG_LGRAY << "subcategory: u" << RESET_ALL << endl;)
	TEST(9, print(" %hhu ", UCHAR_MAX));
	TEST(10, print(" %hhu ", UCHAR_MAX + 1));
	TEST(11, print(" %hhu ", UCHAR_MIN - 1));
	SUBCATEGORY(12, 14, cout << endl << FG_LGRAY << "subcategory: x" << RESET_ALL << endl;)
	TEST(12, print(" %hhx ", UCHAR_MAX));
	TEST(13, print(" %hhx ", UCHAR_MAX + 1));
	TEST(14, print(" %hhx ", UCHAR_MIN - 1));
	SUBCATEGORY(15, 17, cout << endl << FG_LGRAY << "subcategory: X" << RESET_ALL << endl;)
	TEST(15, print(" %hhX ", UCHAR_MAX));
	TEST(16, print(" %hhX ", UCHAR_MAX + 1));
	TEST(17, print(" %hhX ", UCHAR_MIN - 1));
	SUBCATEGORY(18, 19, cout << endl << FG_LGRAY << "subcategory: n" << RESET_ALL << endl;)
	TEST(18, checkn<signed char>("%hhn"));
	TEST(19, checkn<signed char>(" %hhn "));
	cout << ENDL;
	return (0);
}
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
#define USHRT_MIN (0)

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: h" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	SUBCATEGORY(1, 4, cout << endl << FG_LGRAY << "subcategory: d" << RESET_ALL << endl;)
	TEST(1, print(" %hd ", SHRT_MAX));
	TEST(2, print(" %hd ", SHRT_MIN));
	TEST(3, print(" %hd ", SHRT_MAX + 1));
	TEST(4, print(" %hd ", SHRT_MIN - 1));
	SUBCATEGORY(5, 8, cout << endl << FG_LGRAY << "subcategory: i" << RESET_ALL << endl;)
	TEST(5, print(" %hi ", SHRT_MAX));
	TEST(6, print(" %hi ", SHRT_MIN));
	TEST(7, print(" %hi ", SHRT_MAX + 1));
	TEST(8, print(" %hi ", SHRT_MIN - 1));
	SUBCATEGORY(9, 11, cout << endl << FG_LGRAY << "subcategory: u" << RESET_ALL << endl;)
	TEST(9, print(" %hu ", USHRT_MAX));
	TEST(10, print(" %hu ", USHRT_MAX + 1));
	TEST(11, print(" %hu ", USHRT_MIN - 1));
	SUBCATEGORY(12, 14, cout << endl << FG_LGRAY << "subcategory: x" << RESET_ALL << endl;)
	TEST(12, print(" %hx ", USHRT_MAX));
	TEST(13, print(" %hx ", USHRT_MAX + 1));
	TEST(14, print(" %hx ", USHRT_MIN - 1));
	SUBCATEGORY(15, 17, cout << endl << FG_LGRAY << "subcategory: X" << RESET_ALL << endl;)
	TEST(15, print(" %hX ", USHRT_MAX));
	TEST(16, print(" %hX ", USHRT_MAX + 1));
	TEST(17, print(" %hX ", USHRT_MIN - 1));
	SUBCATEGORY(18, 19, cout << endl << FG_LGRAY << "subcategory: n" << RESET_ALL << endl;)
	TEST(18, checkn<short int>("%hn"));
	TEST(19, checkn<short int>(" %hn "));
	cout << ENDL;
	return (0);
}
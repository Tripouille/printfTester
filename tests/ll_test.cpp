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
#define ULLONG_MIN ((unsigned long long int)0)

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: ll" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	SUBCATEGORY(1, 4,  cout << endl << FG_LGRAY << "subcategory: d" << RESET_ALL << endl;)
	TEST(1, print(" %lld ", LONG_MAX + 1));
	TEST(2, print(" %lld ", LONG_MIN - 1));
	TEST(3, print(" %lld ", LLONG_MAX + 1));
	TEST(4, print(" %lld ", LLONG_MIN - 1));
	SUBCATEGORY(5, 8, cout << endl << FG_LGRAY << "subcategory: i" << RESET_ALL << endl;)
	TEST(5, print(" %lli ", LONG_MAX + 1));
	TEST(6, print(" %lli ", LONG_MIN - 1));
	TEST(7, print(" %lli ", LLONG_MAX + 1));
	TEST(8, print(" %lli ", LLONG_MIN - 1));
	SUBCATEGORY(9, 11, cout << endl << FG_LGRAY << "subcategory: u" << RESET_ALL << endl;)
	TEST(9, print(" %llu ", ULLONG_MAX));
	TEST(10, print(" %llu ", ULLONG_MAX + 1));
	TEST(11, print(" %llu ", ULLONG_MIN - 1));
	SUBCATEGORY(12, 14, cout << endl << FG_LGRAY << "subcategory: x" << RESET_ALL << endl;)
	TEST(12, print(" %llx ", ULLONG_MAX));
	TEST(13, print(" %llx ", ULLONG_MAX + 1));
	TEST(14, print(" %llx ", ULLONG_MIN - 1));
	SUBCATEGORY(15, 17, cout << endl << FG_LGRAY << "subcategory: X" << RESET_ALL << endl;)
	TEST(15, print(" %llX ", ULLONG_MAX));
	TEST(16, print(" %llX ", ULLONG_MAX + 1));
	TEST(17, print(" %llX ", ULLONG_MIN - 1));
	SUBCATEGORY(18, 19, cout << endl << FG_LGRAY << "subcategory: n" << RESET_ALL << endl;)
	TEST(18, checkn<long long int>("%lln"));
	TEST(19, checkn<long long int>(" %lln "));
	cout << ENDL;
	return (0);
}
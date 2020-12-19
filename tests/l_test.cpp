extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 30
#define ULONG_MIN ((unsigned long int)0)


int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	#ifdef __unix__
		setlocale(LC_ALL, "");
	#endif
	#ifdef __APPLE__
		setlocale(LC_ALL, "en_US");
	#endif
	cout << FG_LYELLOW << "category: l" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	SUBCATEGORY(1, 4, cout << endl << FG_LGRAY << "subcategory: d" << RESET_ALL << endl;)
	TEST(1, print(" %ld ", INT_MAX + 1));
	TEST(2, print(" %ld ", INT_MIN - 1));
	TEST(3, print(" %ld ", LONG_MAX + 1));
	TEST(4, print(" %ld ", LONG_MIN - 1));
	SUBCATEGORY(5, 8, cout << endl << FG_LGRAY << "subcategory: i" << RESET_ALL << endl;)
	TEST(5, print(" %li ", INT_MAX + 1));
	TEST(6, print(" %li ", INT_MIN - 1));
	TEST(7, print(" %li ", LONG_MAX + 1));
	TEST(8, print(" %li ", LONG_MIN - 1));
	SUBCATEGORY(9, 11, cout << endl << FG_LGRAY << "subcategory: u" << RESET_ALL << endl;)
	TEST(9, print(" %lu ", ULONG_MAX));
	TEST(10, print(" %lu ", ULONG_MAX + 1));
	TEST(11, print(" %lu ", ULONG_MIN - 1));
	SUBCATEGORY(12, 14, cout << endl << FG_LGRAY << "subcategory: x" << RESET_ALL << endl;)
	TEST(12, print(" %lx ", ULONG_MAX));
	TEST(13, print(" %lx ", ULONG_MAX + 1));
	TEST(14, print(" %lx ", ULONG_MIN - 1));
	SUBCATEGORY(15, 17, cout << endl << FG_LGRAY << "subcategory: X" << RESET_ALL << endl;)
	TEST(15, print(" %lX ", ULONG_MAX));
	TEST(16, print(" %lX ", ULONG_MAX + 1));
	TEST(17, print(" %lX ", ULONG_MIN - 1));
	SUBCATEGORY(18, 19, cout << endl << FG_LGRAY << "subcategory: n" << RESET_ALL << endl;)
	TEST(18, checkn<long int>("%ln"));
	TEST(19, checkn<long int>(" %ln "));
	SUBCATEGORY(20, 28, cout << endl << FG_LGRAY << "subcategory: c" << RESET_ALL << endl;)
	TEST(20, print(" %lc ", u'ƀ'));
	TEST(21, print(" %lc ", u'ɏ'));
	TEST(22, print(" %lc ", u'ɐ'));
	TEST(23, print(" %lc ", u'ʯ'));
	TEST(24, print(" %lc ", u'ʰ'));
	TEST(25, print(" %lc ", u'˿'));
	TEST(26, print(" %lc ", u'ୟ'));
	TEST(27, print(" %lc ", u'௫'));
	TEST(28, print(" %lc ", u'࿚'));
	SUBCATEGORY(29, 30, cout << endl << FG_LGRAY << "subcategory: s" << RESET_ALL << endl;)
	wchar_t	 empty[] = {0};
	wchar_t	 s[] = {' ', u'ƀ', u'ɏ', u'ɐ', ' ', u'ʯ', ' ', u'ʰ', u'˿', ' ', u'ୟ', ' ', u'௫', ' ', ' ', u'࿚', 0};
	TEST(29, print(" %ls ", empty));
	TEST(30, print(" %ls ", s));
	cout << ENDL;
	return (0);
}
extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 17

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: p" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %p ", -1));
	TEST(2, print(" %p ", 1));
	TEST(3, print(" %p ", 15));
	TEST(4, print(" %p ", 16));
	TEST(5, print(" %p ", 17));
	TEST(6, print(" %10p %10p ", 1, -1));
	TEST(7, print(" %-10p %10p ", 1, -1));
	TEST(8, print(" %10p %-10p ", 1, -1));
	TEST(9, print(" %-10p %-10p ", 1, -1));
	TEST(10, print(" %10p %-10p ", 1, -1));
	TEST(11, print(" %p %p ", 1, -1));
	TEST(12, print(" %10p %-10p ", 0, 0));
	TEST(13, print(" %p %p ", LONG_MIN, LONG_MAX));
	TEST(14, print(" %p %p ", INT_MIN, INT_MAX));
	TEST(15, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
	TEST(16, print(" %*p %-*p ", -10, 101, -10, 42));
	TEST(17, print(" .-0*%*p %-*p*0-. ", 11, 101, 11, 42));
	cout << ENDL;
	return (0);
}
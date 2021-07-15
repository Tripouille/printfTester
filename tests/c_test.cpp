extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 9

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: c" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print("%c", '0'));
	TEST(2, print(" %c ", '0'));
	TEST(3, print(" %c", '0' - 256));
	TEST(4, print("%c ", '0' + 256));
	TEST(5, print(" %c %c %c ", '0', 0, '1'));
	TEST(6, print(" %c %c %c ", ' ', ' ', ' '));
	TEST(7, print(" %c %c %c ", '1', '2', '3'));
	TEST(8, print(" %c %c %c ", '2', '1', 0));
	TEST(9, print(" %c %c %c ", 0, '1', '2'));
	cout << ENDL;
	return (0);
}
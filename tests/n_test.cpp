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
	cout << FG_LYELLOW << "category: n" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, checkn("%n"));
	TEST(2, checkn("%s%n", "tripouille"));
	TEST(3, checkn("%s%n42", "tripouille"));
	TEST(4, checkn("%s%i%n42", "tripouille", INT_MAX));
	TEST(5, checkn("%s%i%n42", "tripouille", INT_MIN));
	TEST(6, checkn("%s%x%n42", "tripouille", LONG_MAX));
	TEST(7, checkn("%s%x%n42", "tripouille", LONG_MIN));
	TEST(8, checkn("%s%x%n42", "", 0));
	TEST(9, checkn("n%.s%x%n ", "42", -1));
	TEST(10, checkn("%%n%.s%x%n ", "42", -1));
	TEST(11, checkn("%%n%.s%p%n ", "42", (void*)1));
	TEST(12, checkn("%.s%n", "12345"));
	TEST(13, checkn("%s%c42%n", "12345", 0));
	TEST(14, checkn("%s%c%i42%n", "12345", 0, 42));
	TEST(15, checkn("%s%c42%n", "12345", 'A'));
	TEST(16, checkn("%s%d42%n", "12345", -42));
	TEST(17, checkn("%s%X42%n", "12345", 42));
	cout << ENDL;
	return (0);
}
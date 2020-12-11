extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 7

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: %" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %% "));
	TEST(2, print(" %%%% "));
	TEST(3, print(" %% %% %% "));
	TEST(4, print(" %%  %%  %% "));
	TEST(5, print(" %%   %%   %% "));
	TEST(6, print("%%"));
	TEST(7, print("%% %%"));
	cout << ENDL;
	return (0);
}
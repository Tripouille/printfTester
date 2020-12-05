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
bool showTest = false;
int main(int ac, char ** av)
{
	int testNumber;
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "[%]" << RESET_ALL;
	
	if (ac != 1)
	{
		testNumber = atoi(av[1]);
		cout << FG_LYELLOW << "[n°" << testNumber << "]" << RESET_ALL;
		if (testNumber == 0 || testNumber > TEST_LIMIT)
			throw std::runtime_error("invalid test number");
		showTest = true;
	}
	cout << endl;
	if (ac == 1 || testNumber == 1) print(" %% ");
	if (ac == 1 || testNumber == 2) print(" %%%% ");
	if (ac == 1 || testNumber == 3) print(" %% %% %% ");
	if (ac == 1 || testNumber == 4) print(" %%  %%  %% ");
	if (ac == 1 || testNumber == 5) print(" %%   %%   %% ");
	if (ac == 1 || testNumber == 6) print("%%");
	if (ac == 1 || testNumber == 7) print("%% %%");
	cout << ENDL;
	return (0);
}
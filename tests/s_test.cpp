extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"

# ifdef __unix__
# define TEST_LIMIT 33
# endif
# ifdef __APPLE__
# define TEST_LIMIT 36
# endif

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: s" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print("%s", ""));
	TEST(2, print("%s", "0"));
	TEST(3, print("%s %s", "", ""));
	TEST(4, print("%s %s", "0", "1"));
	TEST(5, print(" %s %s ", "0", "1"));
	TEST(6, print(" %s %s ", "", ""));
	TEST(7, print(" %1s %1s ", "123", "4567"));
	TEST(8, print(" %4s %4s ", "123", "4567"));
	TEST(9, print(" %-4s %4s ", "123", "4567"));
	TEST(10, print(" %4s %-4s ", "123", "4567"));
	TEST(11, print(" %-4s %-4s ", "123", "4567"));
	TEST(12, print(" %-4s %-4s ", "123", "4567"));
	TEST(13, print(" %*s %*s ", 1, "123", 10, "4567"));
	TEST(14, print(" *%s %*s ", "123", 10, "4567"));
	TEST(15, print(" %*s %s ", 10, "123", "4567"));
	TEST(16, print(" %*.s %.1s ", 10, "123", "4567"));
	TEST(17, print(" %*.0s %.2s ", 10, "123", "4567"));
	TEST(18, print(" %*.3s %.3s ", 10, "123", "4567"));
	TEST(19, print(" %*.4s %.4s ", 10, "123", "4567"));
	TEST(20, print(" %*.5s %.5s ", 10, "123", "4567"));
	TEST(21, print(" %*.5s %*.5s ", 10, "123", 10, "4567"));
	TEST(22, print(" %*.5s %*.5s ", -10, "123", 10, "4567"));
	TEST(23, print(" %*.5s %*.5s ", 10, "123", -10, "4567"));
	TEST(24, print(" %*.5s %*.5s ", -10, "123", -10, "4567"));
	TEST(25, print(" %10.s %1.s ", "123", "4567"));
	TEST(26, print(" %0.s %0.s ", "123", "4567"));
	TEST(27, print(" %.s %.s ", "123", "4567"));
	TEST(28, print(" %3.3s %3.3s ", "123", "4567"));
	TEST(29, print(" %4.3s %-4.3s ", "123", "4567"));
	TEST(30, print("%.s", ""));
	TEST(31, print("%.0s", ""));
	TEST(32, print("%.1s", ""));
	TEST(33, print(" %4.2s %-4.2s ", "123", "4567"));
	# ifdef __APPLE__
		TEST(34, print(" %-3.s ", NULL));
		TEST(35, print(" %-9.1s ", NULL));
		TEST(36, print(" %.*s ", -2, NULL));
	# endif
	cout << ENDL;
	return (0);
}

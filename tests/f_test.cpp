extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 93

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: f" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %f %f ", 42.0, -42.0));
	TEST(2, print(" %8f %9f %10f ", 42.0, -42.0, 42.0));
	TEST(3, print(" %7f %8f %9f ", 0.0, -1.0, 1.0));
	TEST(4, print(" %7.f %8.1f %9.2f ", 0.0, -1.0, 1.0));
	TEST(5, print(" %7.f %8.1f %9.2f ", 0.0, -1.0, 0.0));
	TEST(6, print(" %-7.f %-8.1f %-9.2f ", 0.0, -1.0, 0.0));
	TEST(7, print(" %-7.f %-8.1f %-9.2f ", 0.0, -1.0, 42.0));
	TEST(8, print(" %07.f %08.1f %09.2f ", 0.0, -1.0, 42.0));
	TEST(9, print(" %01.f %01.1f %01.2f ", 0.0, -1.0, 42.0));
	TEST(10, print(" %02.f %02.1f %02.2f ", 0.0, -1.0, 42.0));
	TEST(11, print(" %-02.f %-02.1f %-02.2f ", 0.0, -1.0, 42.0));
	TEST(12, print(" %-02.1f %-02.1f %-02.1f ", 0.0, -1.0, 42.0));
	TEST(13, print(" %-02.2f %-02.2f %-02.2f ", 0.0, -1.0, 42.0));
	TEST(14, print(" %-02.3f %-02.3f %-02.3f ", 0.0, -1.0, 42.0));
	TEST(15, print(" %-03.3f %-03.3f %-03.3f ", 0.0, -1.0, 42.0));
	TEST(16, print(" %-04.3f %-04.3f %-04.3f ", 0.0, -1.0, 42.0));
	TEST(17, print(" %-4.3f %-4.3f %-4.3f ", 0.0, -1.0, 42.0));
	TEST(18, print(" %-5.3f %-5.3f %-5.3f ", 0.0, -1.0, 42.0));
	TEST(19, print(" %-6.3f %-6.3f %-6.3f ", 0.0, -1.0, 42.0));
	TEST(20, print(" %-06.3f %-06.3f %-06.3f ", 0.0, -1.0, 42.0));
	TEST(21, print(" %06.3f %06.3f %06.3f ", 0.0, -1.0, 42.0));
	TEST(22, print(" %05.3f %05.3f %05.3f ", 0.0, -1.0, 42.0));
	TEST(23, print(" %05.3f %05.3f %05.3f ", 42.0, 420.0, -420.0));
	TEST(24, print(" %f %f ", LONG_MIN * 1.0, LONG_MAX * 1.0));
	TEST(25, print(" %.16f %.16f ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901));
	TEST(26, print(" %32.16f %32.16f ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901));
	TEST(27, print(" %33.16f %33.16f ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901));
	TEST(28, print(" %.f ", 42.101));
	TEST(29, print(" %f ", 0.101));
	TEST(30, print(" %10f ", 1.0 / 0));
	TEST(31, print(" %10.10f ", 1.0 / 0));
	TEST(32, print(" %0.20f ", 1.0 / 0));
	TEST(33, print(" %020.20f ", 1.0 / 0));
	TEST(34, print(" %-020.20f ", 1.0 / 0));
	TEST(35, print(" %-20.f ", 1.0 / 0));
	TEST(36, print(" %10f ", -1.0 / 0));
	TEST(37, print(" %10.10f ", -1.0 / 0));
	TEST(38, print(" %0.20f ", -1.0 / 0));
	TEST(39, print(" %020.20f ", -1.0 / 0));
	TEST(40, print(" %-020.20f ", -1.0 / 0));
	TEST(41, print(" %-20.f ", -1.0 / 0));
	TEST(42, print(" %10f ", 0.0 / 0));
	TEST(43, print(" %10.10f ", 0.0 / 0));
	TEST(44, print(" %0.20f ", 0.0 / 0));
	TEST(45, print(" %020.20f ", 0.0 / 0));
	TEST(46, print(" %-020.20f ", 0.0 / 0));
	TEST(47, print(" %-20.f ", 0.0 / 0));
	TEST(48, print(" %f ", 1.0 / 1000));
	TEST(49, print(" %.f ", 1.0 / 1000));
	TEST(50, print(" %.1f ", 1.0 / 1000));
	TEST(51, print(" %.2f ", 1.0 / 1000));
	TEST(52, print(" %.16f ", 1.0 / 1000));
	TEST(53, print(" %-f ", 1.0 / 1000));
	TEST(54, print(" %-.f ", 1.0 / 1000));
	TEST(55, print(" %-.1f ", 1.0 / 1000));
	TEST(56, print(" %-.2f ", 1.0 / 1000));
	TEST(57, print(" %-.16f ", 1.0 / 1000));
	TEST(58, print(" %f ", 1.0 / 10000));
	TEST(59, print(" %.f ", 1.0 / 10000));
	TEST(60, print(" %.1f ", 1.0 / 10000));
	TEST(61, print(" %.2f ", 1.0 / 10000));
	TEST(62, print(" %.16f ", 1.0 / 10000));
	TEST(63, print(" %-f ", 1.0 / 10000));
	TEST(64, print(" %-.f ", 1.0 / 10000));
	TEST(65, print(" %-.1f ", 1.0 / 10000));
	TEST(66, print(" %-.2f ", 1.0 / 10000));
	TEST(67, print(" %-.16f ", 1.0 / 10000));
	TEST(68, print(" %f ", 1.0 / 100000));
	TEST(69, print(" %.f ", 1.0 / 100000));
	TEST(70, print(" %.1f ", 1.0 / 100000));
	TEST(71, print(" %.2f ", 1.0 / 100000));
	TEST(72, print(" %.16f ", 1.0 / 100000));
	TEST(73, print(" %-f ", 1.0 / 100000));
	TEST(74, print(" %-.f ", 1.0 / 100000));
	TEST(75, print(" %-.1f ", 1.0 / 100000));
	TEST(76, print(" %-.2f ", 1.0 / 100000));
	TEST(77, print(" %-.16f ", 1.0 / 100000));
	TEST(78, print("%.0f", 2.51));
	TEST(79, print("%.0f", 1.5));
	TEST(80, print("%.0f", 4.5));
	TEST(81, print("%.0f", -2.5));
	TEST(82, print("%.0f", -3.5));
	TEST(83, print("%.0f", 2.5));
	TEST(84, print("%.0f", 3.5));
	TEST(85, print("%.0f", 2.45));
	TEST(86, print("%.0f", 2.35));
	TEST(87, print("%.0f", -2.35));
	TEST(88, print("%.0f", 3.451));
	TEST(89, print("%.0f", 3.456));

	TEST(90, print("%3f", 0.0));
	TEST(91, print("%-3f", 0.0));
	TEST(92, print("%03f", 0.0));
	TEST(93, print("%0*f", -7, -54.0));
	cout << ENDL;
	return (0);
}
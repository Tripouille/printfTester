extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 108

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: e" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %e %e ", 42.0, -42.0));
	TEST(2, print(" %8e %9e %10e ", 42.0, -42.0, 42.0));
	TEST(3, print(" %7e %8e %9e ", 0.0, -1.0, 1.0));
	TEST(4, print(" %7.e %8.1e %9.2e ", 0.0, -1.0, 1.0));
	TEST(5, print(" %7.e %8.1e %9.2e ", 0.0, -1.0, 0.0));
	TEST(6, print(" %-7.e %-8.1e %-9.2e ", 0.0, -1.0, 0.0));
	TEST(7, print(" %-7.e %-8.1e %-9.2e ", 0.0, -1.0, 42.0));
	TEST(8, print(" %07.e %08.1e %09.2e ", 0.0, -1.0, 42.0));
	TEST(9, print(" %01.e %01.1e %01.2e ", 0.0, -1.0, 42.0));
	TEST(10, print(" %02.e %02.1e %02.2e ", 0.0, -1.0, 42.0));
	TEST(11, print(" %-02.e %-02.1e %-02.2e ", 0.0, -1.0, 42.0));
	TEST(12, print(" %-02.1e %-02.1e %-02.1e ", 0.0, -1.0, 42.0));
	TEST(13, print(" %-02.2e %-02.2e %-02.2e ", 0.0, -1.0, 42.0));
	TEST(14, print(" %-02.3e %-02.3e %-02.3e ", 0.0, -1.0, 42.0));
	TEST(15, print(" %-03.3e %-03.3e %-03.3e ", 0.0, -1.0, 42.0));
	TEST(16, print(" %-04.3e %-04.3e %-04.3e ", 0.0, -1.0, 42.0));
	TEST(17, print(" %-4.3e %-4.3e %-4.3e ", 0.0, -1.0, 42.0));
	TEST(18, print(" %-5.3e %-5.3e %-5.3e ", 0.0, -1.0, 42.0));
	TEST(19, print(" %-6.3e %-6.3e %-6.3e ", 0.0, -1.0, 42.0));
	TEST(20, print(" %-06.3e %-06.3e %-06.3e ", 0.0, -1.0, 42.0));
	TEST(21, print(" %06.3e %06.3e %06.3e ", 0.0, -1.0, 42.0));
	TEST(22, print(" %05.3e %05.3e %05.3e ", 0.0, -1.0, 42.0));
	TEST(23, print(" %05.3e %05.3e %05.3e ", 42.0, 420.0, -420.0));
	TEST(24, print(" %e %e ", LONG_MIN * 1.0, LONG_MAX * 1.0));
	TEST(25, print(" %.16e %.16e ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901));
	TEST(26, print(" %32.16e %32.16e ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901));
	TEST(27, print(" %33.16e %33.16e ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901));
	TEST(28, print(" %.e ", 42.101));
	TEST(29, print(" %e ", 0.101));
	TEST(30, print(" %10e ", 1.0 / 0));
	TEST(31, print(" %10.10e ", 1.0 / 0));
	TEST(32, print(" %0.20e ", 1.0 / 0));
	TEST(33, print(" %020.20e ", 1.0 / 0));
	TEST(34, print(" %-020.20e ", 1.0 / 0));
	TEST(35, print(" %-20.e ", 1.0 / 0));
	TEST(36, print(" %10e ", -1.0 / 0));
	TEST(37, print(" %10.10e ", -1.0 / 0));
	TEST(38, print(" %0.20e ", -1.0 / 0));
	TEST(39, print(" %020.20e ", -1.0 / 0));
	TEST(40, print(" %-020.20e ", -1.0 / 0));
	TEST(41, print(" %-20.e ", -1.0 / 0));
	TEST(42, print(" %10e ", 0.0 / 0));
	TEST(43, print(" %10.10e ", 0.0 / 0));
	TEST(44, print(" %0.20e ", 0.0 / 0));
	TEST(45, print(" %020.20e ", 0.0 / 0));
	TEST(46, print(" %-020.20e ", 0.0 / 0));
	TEST(47, print(" %-20.e ", 0.0 / 0));
	TEST(48, print(" %e ", 1.0 / 1000));
	TEST(49, print(" %.e ", 1.0 / 1000));
	TEST(50, print(" %.1e ", 1.0 / 1000));
	TEST(51, print(" %.2e ", 1.0 / 1000));
	TEST(52, print(" %.16e ", 1.0 / 1000));
	TEST(53, print(" %-e ", 1.0 / 1000));
	TEST(54, print(" %-.e ", 1.0 / 1000));
	TEST(55, print(" %-.1e ", 1.0 / 1000));
	TEST(56, print(" %-.2e ", 1.0 / 1000));
	TEST(57, print(" %-.16e ", 1.0 / 1000));
	TEST(58, print(" %e ", 1.0 / 10000));
	TEST(59, print(" %.e ", 1.0 / 10000));
	TEST(60, print(" %.1e ", 1.0 / 10000));
	TEST(61, print(" %.2e ", 1.0 / 10000));
	TEST(62, print(" %.16e ", 1.0 / 10000));
	TEST(63, print(" %-e ", 1.0 / 10000));
	TEST(64, print(" %-.e ", 1.0 / 10000));
	TEST(65, print(" %-.1e ", 1.0 / 10000));
	TEST(66, print(" %-.2e ", 1.0 / 10000));
	TEST(67, print(" %-.16e ", 1.0 / 10000));
	TEST(68, print(" %e ", 1.0 / 100000));
	TEST(69, print(" %.e ", 1.0 / 100000));
	TEST(70, print(" %.1e ", 1.0 / 100000));
	TEST(71, print(" %.2e ", 1.0 / 100000));
	TEST(72, print(" %.16e ", 1.0 / 100000));
	TEST(73, print(" %-e ", 1.0 / 100000));
	TEST(74, print(" %-.e ", 1.0 / 100000));
	TEST(75, print(" %-.1e ", 1.0 / 100000));
	TEST(76, print(" %-.2e ", 1.0 / 100000));
	TEST(77, print(" %-.16e ", 1.0 / 100000));
	TEST(78, print(" %-.4e ", 420.0));
	TEST(79, print(" %-.3e ", 420.0));
	TEST(80, print(" %-.2e ", 420.0));
	TEST(81, print(" %4.4e ", 420.0));
	TEST(82, print(" %5.3e ", 420.0));
	TEST(83, print(" %6.2e ", 420.0));
	TEST(84, print(" %7.2e ", 420.0));
	TEST(85, print(" %8.2e ", 420.0));
	TEST(86, print(" %08.2e ", 420.0));
	TEST(87, print(" %-09.2e ", 420.0));
	TEST(88, print(" %7.2e ", -420.0));
	TEST(89, print(" %8.2e ", -420.0));
	TEST(90, print(" %08.2e ", -420.0));
	TEST(91, print(" %-09.2e ", -420.0));
	TEST(92, print(" %09.2e ", -420.0));
	TEST(93, print("%.0e", 2.51));
	TEST(94, print("%.0e", 1.5));
	TEST(95, print("%.0e", 4.5));
	TEST(96, print("%.0e", -2.5));
	TEST(97, print("%.0e", -3.5));
	TEST(98, print("%.0e", 2.5));
	TEST(99, print("%.0e", 3.5));
	TEST(100, print("%.0e", 2.45));
	TEST(101, print("%.0e", 2.35));
	TEST(102, print("%.0e", -2.35));
	TEST(103, print("%.0e", 3.451));
	TEST(104, print("%.0e", 3.456));

	TEST(105, print("%3e", 0.0));
	TEST(106, print("%-3e", 0.0));
	TEST(107, print("%03e", 0.0));
	TEST(108, print("%0*e", -7, -54.0));
	cout << ENDL;
	return (0);
}
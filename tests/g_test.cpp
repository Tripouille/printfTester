extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 118

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: g" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %g %g ", 42.0, -42.0));
	TEST(2, print(" %8g %9g %10g ", 42.0, -42.0, 42.0));
	TEST(3, print(" %7g %8g %9g ", 0.0, -1.0, 1.0));
	TEST(4, print(" %7.g %8.1g %9.2g ", 0.0, -1.0, 1.0));
	TEST(5, print(" %7.g %8.1g %9.2g ", 0.0, -1.0, 0.0));
	TEST(6, print(" %-7.g %-8.1g %-9.2g ", 0.0, -1.0, 0.0));
	TEST(7, print(" %-7.g %-8.1g %-9.2g ", 0.0, -1.0, 42.0));
	TEST(8, print(" %07.g %08.1g %09.2g ", 0.0, -1.0, 42.0));
	TEST(9, print(" %01.g %01.1g %01.2g ", 0.0, -1.0, 42.0));
	TEST(10, print(" %02.g %02.1g %02.2g ", 0.0, -1.0, 42.0));
	TEST(11, print(" %-02.g %-02.1g %-02.2g ", 0.0, -1.0, 42.0));
	TEST(12, print(" %-02.1g %-02.1g %-02.1g ", 0.0, -1.0, 42.0));
	TEST(13, print(" %-02.2g %-02.2g %-02.2g ", 0.0, -1.0, 42.0));
	TEST(14, print(" %-02.3g %-02.3g %-02.3g ", 0.0, -1.0, 42.0));
	TEST(15, print(" %-03.3g %-03.3g %-03.3g ", 0.0, -1.0, 42.0));
	TEST(16, print(" %-04.3g %-04.3g %-04.3g ", 0.0, -1.0, 42.0));
	TEST(17, print(" %-4.3g %-4.3g %-4.3g ", 0.0, -1.0, 42.0));
	TEST(18, print(" %-5.3g %-5.3g %-5.3g ", 0.0, -1.0, 42.0));
	TEST(19, print(" %-6.3g %-6.3g %-6.3g ", 0.0, -1.0, 42.0));
	TEST(20, print(" %-06.3g %-06.3g %-06.3g ", 0.0, -1.0, 42.0));
	TEST(21, print(" %06.3g %06.3g %06.3g ", 0.0, -1.0, 42.0));
	TEST(22, print(" %05.3g %05.3g %05.3g ", 0.0, -1.0, 42.0));
	TEST(23, print(" %05.3g %05.3g %05.3g ", 42.0, 420.0, -420.0));
	TEST(24, print(" %g %g ", LONG_MIN * 1.0, LONG_MAX * 1.0));
	TEST(25, print(" %.16g %.16g ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901));
	TEST(26, print(" %32.16g %32.16g ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901));
	TEST(27, print(" %33.16g %33.16g ", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901));
	TEST(28, print(" %.g ", 42.101));
	TEST(29, print(" %g ", 0.101));
	TEST(30, print(" %10g ", 1.0 / 0));
	TEST(31, print(" %10.10g ", 1.0 / 0));
	TEST(32, print(" %0.20g ", 1.0 / 0));
	TEST(33, print(" %020.20g ", 1.0 / 0));
	TEST(34, print(" %-020.20g ", 1.0 / 0));
	TEST(35, print(" %-20.g ", 1.0 / 0));
	TEST(36, print(" %10g ", -1.0 / 0));
	TEST(37, print(" %10.10g ", -1.0 / 0));
	TEST(38, print(" %0.20g ", -1.0 / 0));
	TEST(39, print(" %020.20g ", -1.0 / 0));
	TEST(40, print(" %-020.20g ", -1.0 / 0));
	TEST(41, print(" %-20.g ", -1.0 / 0));
	TEST(42, print(" %10g ", 0.0 / 0));
	TEST(43, print(" %10.10g ", 0.0 / 0));
	TEST(44, print(" %0.20g ", 0.0 / 0));
	TEST(45, print(" %020.20g ", 0.0 / 0));
	TEST(46, print(" %-020.20g ", 0.0 / 0));
	TEST(47, print(" %-20.g ", 0.0 / 0));
	TEST(48, print(" %g ", 1.0 / 1000));
	TEST(49, print(" %.g ", 1.0 / 1000));
	TEST(50, print(" %.1g ", 1.0 / 1000));
	TEST(51, print(" %.2g ", 1.0 / 1000));
	TEST(52, print(" %.16g ", 1.0 / 1000));
	TEST(53, print(" %-g ", 1.0 / 1000));
	TEST(54, print(" %-.g ", 1.0 / 1000));
	TEST(55, print(" %-.1g ", 1.0 / 1000));
	TEST(56, print(" %-.2g ", 1.0 / 1000));
	TEST(57, print(" %-.16g ", 1.0 / 1000));
	TEST(58, print(" %g ", 1.0 / 10000));
	TEST(59, print(" %.g ", 1.0 / 10000));
	TEST(60, print(" %.1g ", 1.0 / 10000));
	TEST(61, print(" %.2g ", 1.0 / 10000));
	TEST(62, print(" %.16g ", 1.0 / 10000));
	TEST(63, print(" %-g ", 1.0 / 10000));
	TEST(64, print(" %-.g ", 1.0 / 10000));
	TEST(65, print(" %-.1g ", 1.0 / 10000));
	TEST(66, print(" %-.2g ", 1.0 / 10000));
	TEST(67, print(" %-.16g ", 1.0 / 10000));
	TEST(68, print(" %g ", 1.0 / 100000));
	TEST(69, print(" %.g ", 1.0 / 100000));
	TEST(70, print(" %.1g ", 1.0 / 100000));
	TEST(71, print(" %.2g ", 1.0 / 100000));
	TEST(72, print(" %.16g ", 1.0 / 100000));
	TEST(73, print(" %-g ", 1.0 / 100000));
	TEST(74, print(" %-.g ", 1.0 / 100000));
	TEST(75, print(" %-.1g ", 1.0 / 100000));
	TEST(76, print(" %-.2g ", 1.0 / 100000));
	TEST(77, print(" %-.16g ", 1.0 / 100000));
	TEST(78, print(" %-.4g ", 420.0));
	TEST(79, print(" %-.3g ", 420.0));
	TEST(80, print(" %-.2g ", 420.0));
	TEST(81, print(" %4.4g ", 420.0));
	TEST(82, print(" %5.3g ", 420.0));
	TEST(83, print(" %6.2g ", 420.0));
	TEST(84, print(" %7.2g ", 420.0));
	TEST(85, print(" %8.2g ", 420.0));
	TEST(86, print(" %08.2g ", 420.0));
	TEST(87, print(" %-09.2g ", 420.0));
	TEST(88, print(" %7.2g ", -420.0));
	TEST(89, print(" %8.2g ", -420.0));
	TEST(90, print(" %08.2g ", -420.0));
	TEST(91, print(" %-09.2g ", -420.0));
	TEST(92, print(" %09.2g ", -420.0));
	TEST(93, print("%.0g", 2.51));
	TEST(94, print("%.0g", 1.5));
	TEST(95, print("%.0g", 4.5));
	TEST(96, print("%.0g", -2.5));
	TEST(97, print("%.0g", -3.5));
	TEST(98, print("%.0g", 2.5));
	TEST(99, print("%.0g", 3.5));
	TEST(100, print("%.0g", 2.45));
	TEST(101, print("%.0g", 2.35));
	TEST(102, print("%.0g", -2.35));
	TEST(103, print("%.0g", 3.451));
	TEST(104, print("%.0g", 3.456));
	TEST(105, print("%.g", 42.42000000));
	TEST(106, print("%.1g", 42.42000000));
	TEST(107, print("%.2g", 42.42000000));
	TEST(108, print("%.3g", 42.42000000));
	TEST(109, print("%.4g", 42.42000000));
	TEST(110, print("%.5g", 42.42000000));
	TEST(111, print("%.13g", 42.420000000001699));
	TEST(112, print("%.14g", 42.420000000001699));
	TEST(113, print("%.15g", 42.420000000001699));
	TEST(114, print("%.16g", 42.420000000001699));

	TEST(115, print("%3g", 0.0));
	TEST(116, print("%-3g", 0.0));
	TEST(117, print("%03g", 0.0));
	TEST(118, print("%0*g", -7, -54.0));
	cout << ENDL;
	return (0);
}
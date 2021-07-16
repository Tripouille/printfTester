extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 154

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: ." << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	SUBCATEGORY(1, 9, cout << endl << FG_LGRAY << "subcategory: s" << RESET_ALL << endl;)
	TEST(1, print("%.s", ""));
	TEST(2, print(" %.1s", ""));
	TEST(3, print("%.1s ", ""));
	TEST(4, print(" %.s ", ""));
	TEST(5, print(" %.s ", "-"));
	TEST(6, print(" %.2s %.1s ", "", "-"));
	TEST(7, print(" %.3s %.2s ", " - ", ""));
	TEST(8, print(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""));
	TEST(9, print(" %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 "));
	SUBCATEGORY(10, 38, cout << endl << FG_LGRAY << "subcategory: d" << RESET_ALL << endl;)
	TEST(10, print(" %.1d ", 0));
	TEST(11, print(" %.2d ", -1));
	TEST(12, print(" %.2d ", 1));
	TEST(13, print(" %.1d ", 9));
	TEST(14, print(" %.2d ", 10));
	TEST(15, print(" %.3d ", 11));
	TEST(16, print(" %.4d ", 15));
	TEST(17, print(" %.5d ", 16));
	TEST(18, print(" %.6d ", 17));
	TEST(19, print(" %.1d ", 99));
	TEST(20, print(" %.2d ", 100));
	TEST(21, print(" %.3d ", 101));
	TEST(22, print(" %.1d ", -9));
	TEST(23, print(" %.2d ", -10));
	TEST(24, print(" %.3d ", -11));
	TEST(25, print(" %.4d ", -14));
	TEST(26, print(" %.1d ", -15));
	TEST(27, print(" %.2d ", -16));
	TEST(28, print(" %.3d ", -99));
	TEST(29, print(" %.3d ", -100));
	TEST(30, print(" %.4d ", -101));
	TEST(31, print(" %.8d ", INT_MAX));
	TEST(32, print(" %.9d ", INT_MIN));
	TEST(33, print(" %.10d ", LONG_MAX));
	TEST(34, print(" %.11d ", LONG_MIN));
	TEST(35, print(" %.12d ", UINT_MAX));
	TEST(36, print(" %.13d ", ULONG_MAX));
	TEST(37, print(" %.14d ", 9223372036854775807LL));
	TEST(38, print(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(39, 67, cout << endl << FG_LGRAY << "subcategory: i" << RESET_ALL << endl;)
	TEST(39, print(" %.1i ", 0));
	TEST(40, print(" %.2i ", -1));
	TEST(41, print(" %.2i ", 1));
	TEST(42, print(" %.1i ", 9));
	TEST(43, print(" %.2i ", 10));
	TEST(44, print(" %.3i ", 11));
	TEST(45, print(" %.4i ", 15));
	TEST(46, print(" %.5i ", 16));
	TEST(47, print(" %.6i ", 17));
	TEST(48, print(" %.1i ", 99));
	TEST(49, print(" %.2i ", 100));
	TEST(50, print(" %.3i ", 101));
	TEST(51, print(" %.1i ", -9));
	TEST(52, print(" %.2i ", -10));
	TEST(53, print(" %.3i ", -11));
	TEST(54, print(" %.4i ", -14));
	TEST(55, print(" %.1i ", -15));
	TEST(56, print(" %.2i ", -16));
	TEST(57, print(" %.3i ", -99));
	TEST(58, print(" %.3i ", -100));
	TEST(59, print(" %.4i ", -101));
	TEST(60, print(" %.8i ", INT_MAX));
	TEST(61, print(" %.9i ", INT_MIN));
	TEST(62, print(" %.10i ", LONG_MAX));
	TEST(63, print(" %.11i ", LONG_MIN));
	TEST(64, print(" %.12i ", UINT_MAX));
	TEST(65, print(" %.13i ", ULONG_MAX));
	TEST(66, print(" %.14i ", 9223372036854775807LL));
	TEST(67, print(" %.8i %.9i %.10i %.11i %.12i %.13i %.14i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(68, 96, cout << endl << FG_LGRAY << "subcategory: u" << RESET_ALL << endl;)
	TEST(68, print(" %.1u ", 0));
	TEST(69, print(" %.2u ", -1));
	TEST(70, print(" %.2u ", 1));
	TEST(71, print(" %.1u ", 9));
	TEST(72, print(" %.2u ", 10));
	TEST(73, print(" %.3u ", 11));
	TEST(74, print(" %.4u ", 15));
	TEST(75, print(" %.5u ", 16));
	TEST(76, print(" %.6u ", 17));
	TEST(77, print(" %.1u ", 99));
	TEST(78, print(" %.2u ", 100));
	TEST(79, print(" %.3u ", 101));
	TEST(80, print(" %.1u ", -9));
	TEST(81, print(" %.2u ", -10));
	TEST(82, print(" %.3u ", -11));
	TEST(83, print(" %.4u ", -14));
	TEST(84, print(" %.1u ", -15));
	TEST(85, print(" %.2u ", -16));
	TEST(86, print(" %.3u ", -99));
	TEST(87, print(" %.3u ", -100));
	TEST(88, print(" %.4u ", -101));
	TEST(89, print(" %.8u ", INT_MAX));
	TEST(90, print(" %.9u ", INT_MIN));
	TEST(91, print(" %.10u ", LONG_MAX));
	TEST(92, print(" %.11u ", LONG_MIN));
	TEST(93, print(" %.12u ", UINT_MAX));
	TEST(94, print(" %.13u ", ULONG_MAX));
	TEST(95, print(" %.14u ", 9223372036854775807LL));
	TEST(96, print(" %.8u %.9u %.10u %.11u %.12u %.13u %.14u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(97, 125, cout << endl << FG_LGRAY << "subcategory: x" << RESET_ALL << endl;)
	TEST(97, print(" %.1x ", 0));
	TEST(98, print(" %.2x ", -1));
	TEST(99, print(" %.2x ", 1));
	TEST(100, print(" %.1x ", 9));
	TEST(101, print(" %.2x ", 10));
	TEST(102, print(" %.3x ", 11));
	TEST(103, print(" %.4x ", 15));
	TEST(104, print(" %.5x ", 16));
	TEST(105, print(" %.6x ", 17));
	TEST(106, print(" %.1x ", 99));
	TEST(107, print(" %.2x ", 100));
	TEST(108, print(" %.3x ", 101));
	TEST(109, print(" %.1x ", -9));
	TEST(110, print(" %.2x ", -10));
	TEST(111, print(" %.3x ", -11));
	TEST(112, print(" %.4x ", -14));
	TEST(113, print(" %.1x ", -15));
	TEST(114, print(" %.2x ", -16));
	TEST(115, print(" %.3x ", -99));
	TEST(116, print(" %.3x ", -100));
	TEST(117, print(" %.4x ", -101));
	TEST(118, print(" %.8x ", INT_MAX));
	TEST(119, print(" %.9x ", INT_MIN));
	TEST(120, print(" %.10x ", LONG_MAX));
	TEST(121, print(" %.11x ", LONG_MIN));
	TEST(122, print(" %.12x ", UINT_MAX));
	TEST(123, print(" %.13x ", ULONG_MAX));
	TEST(124, print(" %.14x ", 9223372036854775807LL));
	TEST(125, print(" %.8x %.9x %.10x %.11x %.12x %.13x %.14x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(126, 154, cout << endl << FG_LGRAY << "subcategory: X" << RESET_ALL << endl;)
	TEST(126, print(" %.1X ", 0));
	TEST(127, print(" %.2X ", -1));
	TEST(128, print(" %.2X ", 1));
	TEST(129, print(" %.1X ", 9));
	TEST(130, print(" %.2X ", 10));
	TEST(131, print(" %.3X ", 11));
	TEST(132, print(" %.4X ", 15));
	TEST(133, print(" %.5X ", 16));
	TEST(134, print(" %.6X ", 17));
	TEST(135, print(" %.1X ", 99));
	TEST(136, print(" %.2X ", 100));
	TEST(137, print(" %.3X ", 101));
	TEST(138, print(" %.1X ", -9));
	TEST(139, print(" %.2X ", -10));
	TEST(140, print(" %.3X ", -11));
	TEST(141, print(" %.4X ", -14));
	TEST(142, print(" %.1X ", -15));
	TEST(143, print(" %.2X ", -16));
	TEST(144, print(" %.3X ", -99));
	TEST(145, print(" %.3X ", -100));
	TEST(146, print(" %.4X ", -101));
	TEST(147, print(" %.8X ", INT_MAX));
	TEST(148, print(" %.9X ", INT_MIN));
	TEST(149, print(" %.10X ", LONG_MAX));
	TEST(150, print(" %.11X ", LONG_MIN));
	TEST(151, print(" %.12X ", UINT_MAX));
	TEST(152, print(" %.13X ", ULONG_MAX));
	TEST(153, print(" %.14X ", 9223372036854775807LL));
	TEST(154, print(" %.8X %.9X %.10X %.11X %.12X %.13X %.14X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	cout << ENDL;
	return (0);
}
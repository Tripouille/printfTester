extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 173

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: -" << RESET_ALL;

	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	SUBCATEGORY(1, 9, cout << endl << FG_LGRAY << "subcategory: c" << RESET_ALL << endl;)
	TEST(1, print("%-1c", '0'));
	TEST(2, print(" %-2c ", '0'));
	TEST(3, print(" %-3c", '0' - 256));
	TEST(4, print("%-4c ", '0' + 256));
	TEST(5, print(" %-1c %-2c %-3c ", '0', 0, '1'));
	TEST(6, print(" %-1c %-2c %-3c ", ' ', ' ', ' '));
	TEST(7, print(" %-1c %-2c %-3c ", '1', '2', '3'));
	TEST(8, print(" %-1c %-2c %-3c ", '2', '1', 0));
	TEST(9, print(" %-1c %-2c %-3c ", 0, '1', '2'));
	SUBCATEGORY(10, 19, cout << endl << FG_LGRAY << "subcategory: s" << RESET_ALL << endl;)
	TEST(10, print("%1s", ""));
	TEST(11, print("%-1s", ""));
	TEST(12, print(" %-2s", ""));
	TEST(13, print("%-3s ", ""));
	TEST(14, print(" %-0s ", ""));
	TEST(15, print(" %-s ", "-"));
	TEST(16, print(" %-1s %-2s ", "", "-"));
	TEST(17, print(" %-3s %-4s ", " - ", ""));
	TEST(18, print(" %-2s %-3s %-4s %-5s ", " - ", "", "4", ""));
	TEST(19, print(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 "));
	SUBCATEGORY(20, 29, cout << endl << FG_LGRAY << "subcategory: p" << RESET_ALL << endl;)
	TEST(20, print(" %2p ", -1));
	TEST(21, print(" %-2p ", -1));
	TEST(22, print(" %-2p ", 1));
	TEST(23, print(" %-2p ", 15));
	TEST(24, print(" %-3p ", 16));
	TEST(25, print(" %-4p ", 17));
	TEST(26, print(" %-9p %-10p ", LONG_MIN, LONG_MAX));
	TEST(27, print(" %-11p %-12p ", INT_MIN, INT_MAX));
	TEST(28, print(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX));
	TEST(29, print(" %-1p %-2p ", 0, 0));
	SUBCATEGORY(30, 58, cout << endl << FG_LGRAY << "subcategory: d" << RESET_ALL << endl;)
	TEST(30, print(" %-1d ", 0));
	TEST(31, print(" %-2d ", -1));
	TEST(32, print(" %-3d ", 1));
	TEST(33, print(" %-4d ", 9));
	TEST(34, print(" %-1d ", 10));
	TEST(35, print(" %-2d ", 11));
	TEST(36, print(" %-3d ", 15));
	TEST(37, print(" %-4d ", 16));
	TEST(38, print(" %-5d ", 17));
	TEST(39, print(" %-1d ", 99));
	TEST(40, print(" %-2d ", 100));
	TEST(41, print(" %-3d ", 101));
	TEST(42, print(" %-1d ", -9));
	TEST(43, print(" %-2d ", -10));
	TEST(44, print(" %-3d ", -11));
	TEST(45, print(" %-4d ", -14));
	TEST(46, print(" %-5d ", -15));
	TEST(47, print(" %-6d ", -16));
	TEST(48, print(" %-1d ", -99));
	TEST(49, print(" %-2d ", -100));
	TEST(50, print(" %-3d ", -101));
	TEST(51, print(" %-9d ", INT_MAX));
	TEST(52, print(" %-10d ", INT_MIN));
	TEST(53, print(" %-11d ", LONG_MAX));
	TEST(54, print(" %-12d ", LONG_MIN));
	TEST(55, print(" %-13d ", UINT_MAX));
	TEST(56, print(" %-14d ", ULONG_MAX));
	TEST(57, print(" %-15d ", 9223372036854775807LL));
	TEST(58, print(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(59, 87, cout << endl << FG_LGRAY << "subcategory: i" << RESET_ALL << endl;)
	TEST(59, print(" %-1i ", 0));
	TEST(60, print(" %-2i ", -1));
	TEST(61, print(" %-3i ", 1));
	TEST(62, print(" %-4i ", 9));
	TEST(63, print(" %-1i ", 10));
	TEST(64, print(" %-2i ", 11));
	TEST(65, print(" %-3i ", 15));
	TEST(66, print(" %-4i ", 16));
	TEST(67, print(" %-5i ", 17));
	TEST(68, print(" %-1i ", 99));
	TEST(69, print(" %-2i ", 100));
	TEST(70, print(" %-3i ", 101));
	TEST(71, print(" %-1i ", -9));
	TEST(72, print(" %-2i ", -10));
	TEST(73, print(" %-3i ", -11));
	TEST(74, print(" %-4i ", -14));
	TEST(75, print(" %-5i ", -15));
	TEST(76, print(" %-6i ", -16));
	TEST(77, print(" %-1i ", -99));
	TEST(78, print(" %-2i ", -100));
	TEST(79, print(" %-3i ", -101));
	TEST(80, print(" %-9i ", INT_MAX));
	TEST(81, print(" %-10i ", INT_MIN));
	TEST(82, print(" %-11i ", LONG_MAX));
	TEST(83, print(" %-12i ", LONG_MIN));
	TEST(84, print(" %-13i ", UINT_MAX));
	TEST(85, print(" %-14i ", ULONG_MAX));
	TEST(86, print(" %-15i ", 9223372036854775807LL));
	TEST(87, print(" %-9i %-10i %-11i %-12i %-13i %-14i %-15i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(88, 116, cout << endl << FG_LGRAY << "subcategory: u" << RESET_ALL << endl;)
	TEST(88, print(" %-1u ", 0));
	TEST(89, print(" %-2u ", -1));
	TEST(90, print(" %-3u ", 1));
	TEST(91, print(" %-4u ", 9));
	TEST(92, print(" %-1u ", 10));
	TEST(93, print(" %-2u ", 11));
	TEST(94, print(" %-3u ", 15));
	TEST(95, print(" %-4u ", 16));
	TEST(96, print(" %-5u ", 17));
	TEST(97, print(" %-1u ", 99));
	TEST(98, print(" %-2u ", 100));
	TEST(99, print(" %-3u ", 101));
	TEST(100, print(" %-1u ", -9));
	TEST(101, print(" %-2u ", -10));
	TEST(102, print(" %-3u ", -11));
	TEST(103, print(" %-4u ", -14));
	TEST(104, print(" %-5u ", -15));
	TEST(105, print(" %-6u ", -16));
	TEST(106, print(" %-1u ", -99));
	TEST(107, print(" %-2u ", -100));
	TEST(108, print(" %-3u ", -101));
	TEST(109, print(" %-9u ", INT_MAX));
	TEST(110, print(" %-10u ", INT_MIN));
	TEST(111, print(" %-11u ", LONG_MAX));
	TEST(112, print(" %-12u ", LONG_MIN));
	TEST(113, print(" %-13u ", UINT_MAX));
	TEST(114, print(" %-14u ", ULONG_MAX));
	TEST(115, print(" %-15u ", 9223372036854775807LL));
	TEST(116, print(" %-9u %-10u %-11u %-12u %-13u %-14u %-15u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(117, 145, cout << endl << FG_LGRAY << "subcategory: x" << RESET_ALL << endl;)
	TEST(117, print(" %-1x ", 0));
	TEST(118, print(" %-2x ", -1));
	TEST(119, print(" %-3x ", 1));
	TEST(120, print(" %-4x ", 9));
	TEST(121, print(" %-1x ", 10));
	TEST(122, print(" %-2x ", 11));
	TEST(123, print(" %-3x ", 15));
	TEST(124, print(" %-4x ", 16));
	TEST(125, print(" %-5x ", 17));
	TEST(126, print(" %-1x ", 99));
	TEST(127, print(" %-2x ", 100));
	TEST(128, print(" %-3x ", 101));
	TEST(129, print(" %-1x ", -9));
	TEST(130, print(" %-2x ", -10));
	TEST(131, print(" %-3x ", -11));
	TEST(132, print(" %-4x ", -14));
	TEST(133, print(" %-5x ", -15));
	TEST(134, print(" %-6x ", -16));
	TEST(135, print(" %-1x ", -99));
	TEST(136, print(" %-2x ", -100));
	TEST(137, print(" %-3x ", -101));
	TEST(138, print(" %-9x ", INT_MAX));
	TEST(139, print(" %-10x ", INT_MIN));
	TEST(140, print(" %-11x ", LONG_MAX));
	TEST(141, print(" %-12x ", LONG_MIN));
	TEST(142, print(" %-13x ", UINT_MAX));
	TEST(143, print(" %-14x ", ULONG_MAX));
	TEST(144, print(" %-15x ", 9223372036854775807LL));
	TEST(145, print(" %-9x %-10x %-11x %-12x %-13x %-14x %-15x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(146, 174, cout << endl << FG_LGRAY << "subcategory: X" << RESET_ALL << endl;)
	TEST(146, print(" %-1X ", 0));
	TEST(147, print(" %-2X ", -1));
	TEST(148, print(" %-3X ", 1));
	TEST(149, print(" %-4X ", 9));
	TEST(150, print(" %-1X ", 10));
	TEST(151, print(" %-2X ", 11));
	TEST(152, print(" %-3X ", 15));
	TEST(153, print(" %-4X ", 16));
	TEST(154, print(" %-5X ", 17));
	TEST(155, print(" %-1X ", 99));
	TEST(156, print(" %-2X ", 100));
	TEST(157, print(" %-3X ", 101));
	TEST(158, print(" %-1X ", -9));
	TEST(159, print(" %-2X ", -10));
	TEST(160, print(" %-3X ", -11));
	TEST(161, print(" %-4X ", -14));
	TEST(162, print(" %-5X ", -15));
	TEST(163, print(" %-6X ", -16));
	TEST(164, print(" %-1X ", -99));
	TEST(165, print(" %-2X ", -100));
	TEST(166, print(" %-3X ", -101));
	TEST(167, print(" %-9X ", INT_MAX));
	TEST(168, print(" %-10X ", INT_MIN));
	TEST(169, print(" %-11X ", LONG_MAX));
	TEST(170, print(" %-12X ", LONG_MIN));
	TEST(171, print(" %-13X ", UINT_MAX));
	TEST(172, print(" %-14X ", ULONG_MAX));
	TEST(173, print(" %-15X ", 9223372036854775807LL));
	TEST(174, print(" %-9X %-10X %-11X %-12X %-13X %-14X %-15X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	cout << ENDL;
	return (0);
}

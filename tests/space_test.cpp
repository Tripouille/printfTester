extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 143

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: ' '" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	SUBCATEGORY(1, 23, cout << endl << FG_LGRAY << "subcategory: d" << RESET_ALL << endl;)
	TEST(1, print(" % d ", 0));
	TEST(2, print(" % 2d ", 0));
	TEST(3, print(" % 02d ", 0));
	TEST(4, print(" % -03d ", 0));
	TEST(5, print(" % -03.d ", 0));
	TEST(6, print(" % -03.1d ", 0));
	TEST(7, print(" % -03.2d ", 0));
	TEST(8, print(" % d ", -1));
	TEST(9, print(" % 2d ", -1));
	TEST(10, print(" % 02d ", -1));
	TEST(11, print(" % 03d ", -1));
	TEST(12, print(" % -03d ", -1));
	TEST(13, print(" % -03.d ", -1));
	TEST(14, print(" % -03.1d ", -1));
	TEST(15, print(" % -03.2d ", -1));
	TEST(16, print(" % -03.3d ", -1));
	TEST(17, print(" % 03.3d ", -1));
	TEST(18, print(" % 010.3d ", -1));
	TEST(19, print(" % -010.3d ", -1));
	TEST(20, print(" % -010.*d ", 42, -1));
	TEST(21, print(" % .d ", 0));
	TEST(22, print(" % .1d ", 0));
	TEST(23, print(" % .2d ", 0));
	SUBCATEGORY(24, 46, cout << endl << FG_LGRAY << "subcategory: i" << RESET_ALL << endl;)
	TEST(24, print(" % i ", 0));
	TEST(25, print(" % 2i ", 0));
	TEST(26, print(" % 02i ", 0));
	TEST(27, print(" % -03i ", 0));
	TEST(28, print(" % -03.i ", 0));
	TEST(29, print(" % -03.1i ", 0));
	TEST(30, print(" % -03.2i ", 0));
	TEST(31, print(" % i ", -1));
	TEST(32, print(" % 2i ", -1));
	TEST(33, print(" % 02i ", -1));
	TEST(34, print(" % 03i ", -1));
	TEST(35, print(" % -03i ", -1));
	TEST(36, print(" % -03.i ", -1));
	TEST(37, print(" % -03.1i ", -1));
	TEST(38, print(" % -03.2i ", -1));
	TEST(39, print(" % -03.3i ", -1));
	TEST(40, print(" % 03.3i ", -1));
	TEST(41, print(" % 010.3i ", -1));
	TEST(42, print(" % -010.3i ", -1));
	TEST(43, print(" % -010.*i ", 42, -1));
	TEST(44, print(" % .i ", 0));
	TEST(45, print(" % .1i ", 0));
	TEST(46, print(" % .2i ", 0));
	SUBCATEGORY(47, 76, cout << endl << FG_LGRAY << "subcategory: e" << RESET_ALL << endl;)
	TEST(47, print(" % e ", 0.));
	TEST(48, print(" % 2e ", 0.));
	TEST(49, print(" % 02e ", 0.));
	TEST(50, print(" % -03e ", 0.));
	TEST(51, print(" % -03.e ", 0.));
	TEST(52, print(" % -03.1e ", 0.));
	TEST(53, print(" % -03.2e ", 0.));
	TEST(54, print(" % e ", -1.));
	TEST(55, print(" % 2e ", -1.));
	TEST(56, print(" % 02e ", -1.));
	TEST(57, print(" % 03e ", -1.));
	TEST(58, print(" % -03e ", -1.));
	TEST(59, print(" % -03.e ", -1.));
	TEST(60, print(" % -03.1e ", -1.));
	TEST(61, print(" % -03.2e ", -1.));
	TEST(62, print(" % -03.3e ", -1.));
	TEST(63, print(" % 03.3e ", -1.));
	TEST(64, print(" % 010.3e ", -1.));
	TEST(65, print(" % -010.3e ", -1.));
	TEST(66, print(" % -010.*e ", 42, -1.));
	TEST(67, print(" % .e ", 0.));
	TEST(68, print(" % .1e ", 0.));
	TEST(69, print(" % .2e ", 0.));
	TEST(70, print(" % .*e ", 0, 0.1234567890));
	TEST(71, print(" % .*e ", 1, 0.1234567890));
	TEST(72, print(" % .*e ", 2, 0.1234567890));
	TEST(73, print(" % .*e ", 3, 0.1234567890));
	TEST(74, print(" % .*e ", 4, 0.1234567890));
	TEST(75, print(" % .*e ", 5, 0.1234567890));
	TEST(76, print(" % .*e ", 6, 0.1234567890));
	SUBCATEGORY(77, 106, cout << endl << FG_LGRAY << "subcategory: f" << RESET_ALL << endl;)
	TEST(77, print(" % f ", 0.));
	TEST(78, print(" % 2f ", 0.));
	TEST(79, print(" % 02f ", 0.));
	TEST(80, print(" % -03f ", 0.));
	TEST(81, print(" % -03.f ", 0.));
	TEST(82, print(" % -03.1f ", 0.));
	TEST(83, print(" % -03.2f ", 0.));
	TEST(84, print(" % f ", -1.));
	TEST(85, print(" % 2f ", -1.));
	TEST(86, print(" % 02f ", -1.));
	TEST(87, print(" % 03f ", -1.));
	TEST(88, print(" % -03f ", -1.));
	TEST(89, print(" % -03.f ", -1.));
	TEST(90, print(" % -03.1f ", -1.));
	TEST(91, print(" % -03.2f ", -1.));
	TEST(92, print(" % -03.3f ", -1.));
	TEST(93, print(" % 03.3f ", -1.));
	TEST(94, print(" % 010.3f ", -1.));
	TEST(95, print(" % -010.3f ", -1.));
	TEST(96, print(" % -010.*f ", 42, -1.));
	TEST(97, print(" % .f ", 0.));
	TEST(98, print(" % .1f ", 0.));
	TEST(99, print(" % .2f ", 0.));
	TEST(100, print(" % .*f ", 0, 0.1234567890));
	TEST(101, print(" % .*f ", 1, 0.1234567890));
	TEST(102, print(" % .*f ", 2, 0.1234567890));
	TEST(103, print(" % .*f ", 3, 0.1234567890));
	TEST(104, print(" % .*f ", 4, 0.1234567890));
	TEST(105, print(" % .*f ", 5, 0.1234567890));
	TEST(106, print(" % .*f ", 6, 0.1234567890));
	SUBCATEGORY(107, 143, cout << endl << FG_LGRAY << "subcategory: g" << RESET_ALL << endl;)
	TEST(107, print(" % g ", 0.));
	TEST(108, print(" % 2g ", 0.));
	TEST(109, print(" % 02g ", 0.));
	TEST(110, print(" % -03g ", 0.));
	TEST(111, print(" % -03.g ", 0.));
	TEST(112, print(" % -03.1g ", 0.));
	TEST(113, print(" % -03.2g ", 0.));
	TEST(114, print(" % g ", -1.));
	TEST(115, print(" % 2g ", -1.));
	TEST(116, print(" % 02g ", -1.));
	TEST(117, print(" % 03g ", -1.));
	TEST(118, print(" % -03g ", -1.));
	TEST(119, print(" % -03.g ", -1.));
	TEST(120, print(" % -03.1g ", -1.));
	TEST(121, print(" % -03.2g ", -1.));
	TEST(122, print(" % -03.3g ", -1.));
	TEST(123, print(" % 03.3g ", -1.));
	TEST(124, print(" % 010.3g ", -1.));
	TEST(125, print(" % -010.3g ", -1.));
	TEST(126, print(" % -010.*g ", 42, -1.));
	TEST(127, print(" % .g ", 0.));
	TEST(128, print(" % .1g ", 0.));
	TEST(129, print(" % .2g ", 0.));
	TEST(130, print(" % .*g ", 0, 0.1234567890));
	TEST(131, print(" % .*g ", 1, 0.1234567890));
	TEST(132, print(" % .*g ", 2, 0.1234567890));
	TEST(133, print(" % .*g ", 3, 0.1234567890));
	TEST(134, print(" % .*g ", 4, 0.1234567890));
	TEST(135, print(" % .*g ", 5, 0.1234567890));
	TEST(136, print(" % .*g ", 6, 0.1234567890));
	TEST(137, print(" % .*g ", 0, 1234567890.));
	TEST(138, print(" % .*g ", 1, 1234567890.));
	TEST(139, print(" % .*g ", 2, 1234567890.));
	TEST(140, print(" % .*g ", 3, 1234567890.));
	TEST(141, print(" % .*g ", 4, 1234567890.));
	TEST(142, print(" % .*g ", 5, 1234567890.));
	TEST(143, print(" % .*g ", 6, 1234567890.));
	cout << ENDL;
	return (0);
}
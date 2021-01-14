extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 80

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: #" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	SUBCATEGORY(1, 16, cout << endl << FG_LGRAY << "subcategory: x" << RESET_ALL << endl;)
	TEST(1, print(" %#x ", 0));
	TEST(2, print(" %#2x ", 0));
	TEST(3, print(" %#02x ", 0));
	TEST(4, print(" %#-03x ", 0));
	TEST(5, print(" %#-03.x ", 0));
	TEST(6, print(" %#-03.1x ", 0));
	TEST(7, print(" %#-03.2x ", 0));
	TEST(8, print(" %#-03.*x ", 2, 0));
	TEST(9, print(" %#x ", 1));
	TEST(10, print(" %#2x ", 1));
	TEST(11, print(" %#02x ", 1));
	TEST(12, print(" %#-03x ", 1));
	TEST(13, print(" %#-03.x ", 1));
	TEST(14, print(" %#-03.1x ", 1));
	TEST(15, print(" %#-03.2x ", 1));
	TEST(16, print(" %#-03.*x ", 2, 1));
	SUBCATEGORY(17, 32, cout << endl << FG_LGRAY << "subcategory: X" << RESET_ALL << endl;)
	TEST(17, print(" %#X ", 0));
	TEST(18, print(" %#2X ", 0));
	TEST(19, print(" %#02X ", 0));
	TEST(20, print(" %#-03X ", 0));
	TEST(21, print(" %#-03.X ", 0));
	TEST(22, print(" %#-03.1X ", 0));
	TEST(23, print(" %#-03.2X ", 0));
	TEST(24, print(" %#-03.*X ", 2, 0));
	TEST(25, print(" %#X ", 1));
	TEST(26, print(" %#2X ", 1));
	TEST(27, print(" %#02X ", 1));
	TEST(28, print(" %#-03X ", 1));
	TEST(29, print(" %#-03.X ", 1));
	TEST(30, print(" %#-03.1X ", 1));
	TEST(31, print(" %#-03.2X ", 1));
	TEST(32, print(" %#-03.*X ", 2, 1));
	SUBCATEGORY(33, 48, cout << endl << FG_LGRAY << "subcategory: e" << RESET_ALL << endl;)
	TEST(33, print(" %#e ", 0.1));
	TEST(34, print(" %#2e ", 0.1));
	TEST(35, print(" %#02e ", 0.1));
	TEST(36, print(" %#-03e ", 0.1));
	TEST(37, print(" %#-03.e ", 0.1));
	TEST(38, print(" %#-03.1e ", 0.1));
	TEST(39, print(" %#-03.2e ", 0.1));
	TEST(40, print(" %#-03.*e ", 2, 0.1));
	TEST(41, print(" %#e ", 1.0));
	TEST(42, print(" %#2e ", 1.0));
	TEST(43, print(" %#02e ", 1.0));
	TEST(44, print(" %#-03e ", 1.0));
	TEST(45, print(" %#-03.e ", 1.0));
	TEST(46, print(" %#-03.1e ", 1.0));
	TEST(47, print(" %#-03.2e ", 1.0));
	TEST(48, print(" %#-03.*e ", 2, 1.0));
	SUBCATEGORY(49, 64, cout << endl << FG_LGRAY << "subcategory: f" << RESET_ALL << endl;)
	TEST(49, print(" %#f ", 0.1));
	TEST(50, print(" %#2f ", 0.1));
	TEST(51, print(" %#02f ", 0.1));
	TEST(52, print(" %#-03f ", 0.1));
	TEST(53, print(" %#-03.f ", 0.1));
	TEST(54, print(" %#-03.1f ", 0.1));
	TEST(55, print(" %#-03.2f ", 0.1));
	TEST(56, print(" %#-03.*f ", 2, 0.1));
	TEST(57, print(" %#f ", 1.0));
	TEST(58, print(" %#2f ", 1.0));
	TEST(59, print(" %#02f ", 1.0));
	TEST(60, print(" %#-03f ", 1.0));
	TEST(61, print(" %#-03.f ", 1.0));
	TEST(62, print(" %#-03.1f ", 1.0));
	TEST(63, print(" %#-03.2f ", 1.0));
	TEST(64, print(" %#-03.*f ", 2, 1.0));
	SUBCATEGORY(65, 80, cout << endl << FG_LGRAY << "subcategory: g" << RESET_ALL << endl;)
	TEST(65, print(" %#g ", 0.1));
	TEST(66, print(" %#2g ", 0.1));
	TEST(67, print(" %#02g ", 0.1));
	TEST(68, print(" %#-03g ", 0.1));
	TEST(69, print(" %#-03.g ", 0.1));
	TEST(70, print(" %#-03.1g ", 0.1));
	TEST(71, print(" %#-03.2g ", 0.1));
	TEST(72, print(" %#-03.*g ", 2, 0.1));
	TEST(73, print(" %#g ", 1.0));
	TEST(74, print(" %#2g ", 1.0));
	TEST(75, print(" %#02g ", 1.0));
	TEST(76, print(" %#-03g ", 1.0));
	TEST(77, print(" %#-03.g ", 1.0));
	TEST(78, print(" %#-03.1g ", 1.0));
	TEST(79, print(" %#-03.2g ", 1.0));
	TEST(80, print(" %#-03.*g ", 2, 1.0));
	cout << ENDL;
	return (0);
}
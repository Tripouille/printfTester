extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 84

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: i" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %i ", 0));
	TEST(2, print(" %.i ", 0));
	TEST(3, print(" %-.2i ", 0));
	TEST(4, print(" %-2.2i ", 0));
	TEST(5, print(" %-3.2i ", 0));
	TEST(6, print(" %-3.2i %10.42i ", 0, 0));
	TEST(7, print(" %-3.2i %10.42i ", 1, -1));
	TEST(8, print(" %-3.2i %10.42i ", 10, -10));
	TEST(9, print(" *%-*.*i* *%*.*i* ", 4, 5, 10, 10, 21, -10));
	TEST(10, print(" *%-*.*i* *%*.*i* ", 6, 2, 102, 10, 21, -101));
	TEST(11, print(" *%*.*i* *%*.*i* ", -6, 2, 102, 10, 21, 101));
	TEST(12, print(" 0*%0-*.*i*0 0*%0*.*i*0 ", 6, 2, 102, 10, 21, -101));
	TEST(13, print(" 0*%0-*.*i*0 0*%0*.*i*0 ", 2, 6, 102, 21, 10, -101));
	TEST(14, print(" 0*%0-*i*0 0*%0*i*0 ", 21, 1021, 21, -1011));
	TEST(15, print(" 0*%-0*.10i*0 0*%-0*.0i*0 ", 21, 1021, 21, -1011));
	TEST(16, print(" --0*%0*.0i*0 0*%0*.10i*0-- ", -2, 0, 21, 1));
	TEST(17, print(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, INT_MAX, 21, INT_MIN));
	TEST(18, print(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, LONG_MAX, 21, LONG_MIN));
	TEST(19, print(" --0*%-0*.20i*0 0*%-0*.10i*0-- ", -21, CHAR_MAX, 21, CHAR_MIN));
	TEST(20, print(" --0*%-0*.2i*0 0*%-0*.2i*0-- ", -21, CHAR_MAX, 21, CHAR_MIN));
	TEST(21, print(" --0*%-0*.3i*0 0*%-0*.3i*0-- ", -21, CHAR_MAX, 21, CHAR_MIN));
	TEST(22, print(" --0*%-0*.4i*0 0*%-0*.4i*0-- ", -21, CHAR_MAX, 21, CHAR_MIN));
	TEST(23, print("%9.2i", UINT_MAX));
	TEST(24, print("%9.10i", UINT_MAX));
	TEST(25, print("%10.0i", UINT_MAX));
	TEST(26, print("%10.1i", UINT_MAX));
	TEST(27, print("%10.2i", UINT_MAX));
	TEST(28, print("%10.10i", UINT_MAX));
	TEST(29, print("%11.0i", UINT_MAX));
	TEST(30, print("%11.1i", UINT_MAX));
	TEST(31, print("%11.2i", UINT_MAX));
	TEST(32, print("%11.10i", UINT_MAX));
	TEST(33, print("%-9.0i", UINT_MAX));
	TEST(34, print("%-9.1i", UINT_MAX));
	TEST(35, print("%-9.2i", UINT_MAX));
	TEST(36, print("%-9.10i", UINT_MAX));
	TEST(37, print("%-10.0i", UINT_MAX));
	TEST(38, print("%-10.1i", UINT_MAX));
	TEST(39, print("%-10.2i", UINT_MAX));
	TEST(40, print("%-10.10i", UINT_MAX));
	TEST(41, print("%-11.0i", UINT_MAX));
	TEST(42, print("%-11.1i", UINT_MAX));
	TEST(43, print("%-11.2i", UINT_MAX));
	TEST(44, print("%-11.10i", UINT_MAX));
	TEST(45, print("%09.0i", UINT_MAX));
	TEST(46, print("%09.1i", UINT_MAX));
	TEST(47, print("%09.2i", UINT_MAX));
	TEST(48, print("%09.10i", UINT_MAX));
	TEST(49, print("%010.0i", UINT_MAX));
	TEST(50, print("%010.1i", UINT_MAX));
	TEST(51, print("%010.2i", UINT_MAX));
	TEST(52, print("%010.10i", UINT_MAX));
	TEST(53, print("%011.0i", UINT_MAX));
	TEST(54, print("%011.1i", UINT_MAX));
	TEST(55, print("%011.2i", UINT_MAX));
	TEST(56, print("%011.10i", UINT_MAX));
	TEST(57, print("%09.0i", UINT_MAX + 1));
	TEST(58, print("%09.1i", UINT_MAX + 1));
	TEST(59, print("%09.2i", UINT_MAX + 1));
	TEST(60, print("%09.10i", UINT_MAX + 1));
	TEST(61, print("%010.0i", UINT_MAX + 1));
	TEST(62, print("%010.1i", UINT_MAX + 1));
	TEST(63, print("%010.2i", UINT_MAX + 1));
	TEST(64, print("%010.10i", UINT_MAX + 1));
	TEST(65, print("%011.0i", UINT_MAX + 1));
	TEST(66, print("%011.1i", UINT_MAX + 1));
	TEST(67, print("%011.2i", UINT_MAX + 1));
	TEST(68, print("%011.10i", UINT_MAX + 1));
	TEST(69, print("%.0i", 0));
	TEST(70, print("%.0i", 5));
	TEST(71, print("%.0i", 10));

	TEST(72, print("%1.i", 0));
	TEST(73, print("%2.i", 0));
	TEST(74, print("%3.i", 0));
	TEST(75, print("%1.1i", 0));
	TEST(76, print("%1.2i", 0));
	TEST(77, print("%1.3i", 0));
	TEST(78, print("%1.1i", 0));
	TEST(79, print("%2.2i", 0));
	TEST(80, print("%3.3i", 0));

	TEST(81, print("%3i", 0));
	TEST(82, print("%-3i", 0));
	TEST(83, print("%03i", 0));
	TEST(84, print("%0*i", -7, -54));
	cout << ENDL;
	return (0);
}
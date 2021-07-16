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
	cout << FG_LYELLOW << "category: 0" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	SUBCATEGORY(1, 28, cout << endl << FG_LGRAY << "subcategory: d" << RESET_ALL << endl;)
	TEST(1, print(" %01d ", 0));
	TEST(2, print(" %02d ", -1));
	TEST(3, print(" %04d ", 9));
	TEST(4, print(" %01d ", 10));
	TEST(5, print(" %02d ", 11));
	TEST(6, print(" %03d ", 15));
	TEST(7, print(" %04d ", 16));
	TEST(8, print(" %05d ", 17));
	TEST(9, print(" %01d ", 99));
	TEST(10, print(" %02d ", 100));
	TEST(11, print(" %03d ", 101));
	TEST(12, print(" %01d ", -9));
	TEST(13, print(" %02d ", -10));
	TEST(14, print(" %03d ", -11));
	TEST(15, print(" %04d ", -14));
	TEST(16, print(" %05d ", -15));
	TEST(17, print(" %06d ", -16));
	TEST(18, print(" %01d ", -99));
	TEST(19, print(" %02d ", -100));
	TEST(20, print(" %03d ", -101));
	TEST(21, print(" %09d ", INT_MAX));
	TEST(22, print(" %010d ", INT_MIN));
	TEST(23, print(" %011d ", LONG_MAX));
	TEST(24, print(" %012d ", LONG_MIN));
	TEST(25, print(" %013d ", UINT_MAX));
	TEST(26, print(" %014d ", ULONG_MAX));
	TEST(27, print(" %015d ", 9223372036854775807LL));
	TEST(28, print(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(29, 56, cout << endl << FG_LGRAY << "subcategory: i" << RESET_ALL << endl;)
	TEST(29, print(" %01i ", 0));
	TEST(30, print(" %02i ", -1));
	TEST(31, print(" %03i ", 1));
	TEST(32, print(" %04i ", 9));
	TEST(33, print(" %01i ", 10));
	TEST(34, print(" %02i ", 11));
	TEST(35, print(" %03i ", 15));
	TEST(36, print(" %04i ", 16));
	TEST(37, print(" %05i ", 17));
	TEST(38, print(" %01i ", 99));
	TEST(39, print(" %02i ", 100));
	TEST(40, print(" %03i ", 101));
	TEST(41, print(" %01i ", -9));
	TEST(41, print(" %02i ", -10));
	TEST(42, print(" %03i ", -11));
	TEST(43, print(" %04i ", -14));
	TEST(44, print(" %05i ", -15));
	TEST(45, print(" %06i ", -16));
	TEST(46, print(" %01i ", -99));
	TEST(47, print(" %02i ", -100));
	TEST(48, print(" %03i ", -101));
	TEST(49, print(" %09i ", INT_MAX));
	TEST(50, print(" %010i ", INT_MIN));
	TEST(51, print(" %011i ", LONG_MAX));
	TEST(52, print(" %012i ", LONG_MIN));
	TEST(53, print(" %013i ", UINT_MAX));
	TEST(54, print(" %014i ", ULONG_MAX));
	TEST(55, print(" %015i ", 9223372036854775807LL));
	TEST(56, print(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(57, 85, cout << endl << FG_LGRAY << "subcategory: u" << RESET_ALL << endl;)
	TEST(57, print(" %01u ", 0));
	TEST(58, print(" %02u ", -1));
	TEST(59, print(" %03u ", 1));
	TEST(60, print(" %04u ", 9));
	TEST(61, print(" %01u ", 10));
	TEST(62, print(" %02u ", 11));
	TEST(63, print(" %03u ", 15));
	TEST(64, print(" %04u ", 16));
	TEST(65, print(" %05u ", 17));
	TEST(66, print(" %01u ", 99));
	TEST(67, print(" %02u ", 100));
	TEST(68, print(" %03u ", 101));
	TEST(69, print(" %01u ", -9));
	TEST(70, print(" %02u ", -10));
	TEST(71, print(" %03u ", -11));
	TEST(72, print(" %04u ", -14));
	TEST(73, print(" %05u ", -15));
	TEST(74, print(" %06u ", -16));
	TEST(75, print(" %01u ", -99));
	TEST(76, print(" %02u ", -100));
	TEST(77, print(" %03u ", -101));
	TEST(78, print(" %09u ", INT_MAX));
	TEST(79, print(" %010u ", INT_MIN));
	TEST(80, print(" %011u ", LONG_MAX));
	TEST(81, print(" %012u ", LONG_MIN));
	TEST(82, print(" %013u ", UINT_MAX));
	TEST(83, print(" %014u ", ULONG_MAX));
	TEST(84, print(" %015u ", 9223372036854775807LL));
	TEST(85, print(" %09u %010u %011u %012u %013u %014u %015u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(86, 114, cout << endl << FG_LGRAY << "subcategory: x" << RESET_ALL << endl;)
	TEST(86, print(" %01x ", 0));
	TEST(87, print(" %02x ", -1));
	TEST(88, print(" %03x ", 1));
	TEST(89, print(" %04x ", 9));
	TEST(90, print(" %01x ", 10));
	TEST(91, print(" %02x ", 11));
	TEST(92, print(" %03x ", 15));
	TEST(93, print(" %04x ", 16));
	TEST(94, print(" %05x ", 17));
	TEST(95, print(" %01x ", 99));
	TEST(96, print(" %02x ", 100));
	TEST(97, print(" %03x ", 101));
	TEST(98, print(" %01x ", -9));
	TEST(99, print(" %02x ", -10));
	TEST(100, print(" %03x ", -11));
	TEST(101, print(" %04x ", -14));
	TEST(102, print(" %05x ", -15));
	TEST(103, print(" %06x ", -16));
	TEST(104, print(" %01x ", -99));
	TEST(105, print(" %02x ", -100));
	TEST(106, print(" %03x ", -101));
	TEST(107, print(" %09x ", INT_MAX));
	TEST(108, print(" %010x ", INT_MIN));
	TEST(109, print(" %011x ", LONG_MAX));
	TEST(110, print(" %012x ", LONG_MIN));
	TEST(111, print(" %013x ", UINT_MAX));
	TEST(112, print(" %014x ", ULONG_MAX));
	TEST(113, print(" %015x ", 9223372036854775807LL));
	TEST(114, print(" %09x %010x %011x %012x %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	SUBCATEGORY(115, 143, cout << endl << FG_LGRAY << "subcategory: X" << RESET_ALL << endl;)
	TEST(115, print(" %01X ", 0));
	TEST(116, print(" %02X ", -1));
	TEST(117, print(" %03X ", 1));
	TEST(118, print(" %04X ", 9));
	TEST(119, print(" %01X ", 10));
	TEST(120, print(" %02X ", 11));
	TEST(121, print(" %03X ", 15));
	TEST(122, print(" %04X ", 16));
	TEST(123, print(" %05X ", 17));
	TEST(124, print(" %01X ", 99));
	TEST(125, print(" %02X ", 100));
	TEST(126, print(" %03X ", 101));
	TEST(127, print(" %01X ", -9));
	TEST(128, print(" %02X ", -10));
	TEST(129, print(" %03X ", -11));
	TEST(130, print(" %04X ", -14));
	TEST(131, print(" %05X ", -15));
	TEST(132, print(" %06X ", -16));
	TEST(133, print(" %01X ", -99));
	TEST(134, print(" %02X ", -100));
	TEST(135, print(" %03X ", -101));
	TEST(136, print(" %09X ", INT_MAX));
	TEST(137, print(" %010X ", INT_MIN));
	TEST(138, print(" %011X ", LONG_MAX));
	TEST(139, print(" %012X ", LONG_MIN));
	TEST(140, print(" %013X ", UINT_MAX));
	TEST(141, print(" %014X ", ULONG_MAX));
	TEST(142, print(" %015X ", 9223372036854775807LL));
	TEST(143, print(" %09X %010X %011X %012X %013X %014X %015X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	cout << ENDL;
	return (0);
}
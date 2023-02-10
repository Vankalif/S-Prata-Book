#include "listings.h"
#include "..\functions\functions.h"
#include <iostream>

void l8_1()
{
	using std::cout;

	double a, b;
	double c = 13.0;
	a = square(5.0);
	b = square(4.5 + 15.5);
	cout << "a = " << a << ", b = " << b << "\n";
	cout << "c = " << c;
	cout << ", c squared = " << square(c++ + c++) << "\n";
	cout << "now c = " << c << "\n";
}

void l8_2()
{
	using std::cout;
	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats << ", rodents = " << rodents << "\n";
	rodents++;
	cout << "rats = " << rats << ", rodents = " << rodents << "\n";
	cout << "rats addr= " << &rats << ", rodents addr = " << &rodents << "\n";
}

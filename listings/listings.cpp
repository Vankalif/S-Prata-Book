#include "listings.h"
#include "..\functions\functions.h"
#include <iostream>

// l8_1 -- встраивание функции
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

// l8_2 -- определение и использование ссылки
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

// l8_3 -- определение и использование ссылки
void l8_3()
{
	using std::cout;
	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats << ", rodents = " << rodents << "\n";
	rodents++;
	cout << "rats = " << rats << ", rodents = " << rodents << "\n";
	cout << "rats addr= " << &rats << ", rodents addr = " << &rodents << "\n";

	int bunnies = 50;
	rodents = bunnies;
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << "\n";
	cout << "bunnies addr = " << &bunnies;
	cout << ", rodents addr = " << &rodents << "\n";
}

// l8_4 -- обмен значениями с помощью ссылок и указателей
void l8_4()
{
	using std::cout;
	int wallet1 = 300;
	int wallet2 = 350;

	cout << "Wallet1 = $" << wallet1 << "\n";
	cout << "Wallet2 = $" << wallet2 << "\n";
	cout << "Using references to swap content:\n";

	swapr(wallet1, wallet2);

	cout << "Wallet1 = $" << wallet1 << "\n";
	cout << "Wallet2 = $" << wallet2 << "\n";
	cout << "Using pointers to swap content:\n";

	swapp(&wallet1, &wallet2);

	cout << "Wallet1 = $" << wallet1 << "\n";
	cout << "Wallet2 = $" << wallet2 << "\n";
	cout << "Trying to use passing by value:\n";

	swapv(wallet1, wallet2);
	cout << "Wallet1 = $" << wallet1 << "\n";
	cout << "Wallet2 = $" << wallet2 << "\n";

}

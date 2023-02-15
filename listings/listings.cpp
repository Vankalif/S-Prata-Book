#include "listings.h"
#include "..\functions\functions.h"
#include <iostream>
#include <string>

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

void l8_5()
{
	using namespace std;
	double x = 3.0;
	cout << cube(x);
	cout << " = cube of " << x << endl;
	cout << refcube(x);
	cout << " = cube of " << x << endl;
}

void l8_6()
{
	FreeThrows one = { "Ifelsa Branch", 13, 14 };
	FreeThrows two = { "Andor Knott", 10, 16 };
	FreeThrows three = { "Minnie Maximus", 7, 9 };
	FreeThrows four = { "Whily Looper", 5, 9 };
	FreeThrows five = { "Long Long", 6, 14 };
	FreeThrows team = { "Throwgoods", 0, 0 };
	FreeThrows dups;
	
	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);

	// использование возвращаемого значения в качестве аргумента
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);

	// использование возвращаемого значения в присваивании
	dups = accumulate(team, five);
	std::cout << "Displayng team:\n";
	display(team);

	// отображение dups после присваивания
	std::cout << "Displayng dups after assignment:\n";
	display(dups);
	set_pc(four);

	// неблагоразумное присваивание
	accumulate(dups, five) = four;

	// отображение dups после неблагоразумного присваивания
	std::cout << "Displaying dups after ill-adviced assignment:\n";
	display(dups);
}

void l8_7()
{
	using namespace std;
	
	string input;
	string copy;
	string result;

	cout << "Enter a string: ";
	getline(cin, input);
	copy = input;
	cout << "Your string as entered: " << input << endl;
	
	cout << "\nVersion 1 call\n";
	result = version1(input, "***");
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;

	cout << "\nVersion 2 call\n";
	result = version2(input, "###");
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;

	cout << "Resetting original string.\n";
	
	input = copy;
	cout << "\nVersion 3 call\n";
	result = version3(input, "@@@");
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;
}

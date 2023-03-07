#pragma once
#include "listings.h"
#include "..\functions\functions.h"


const int kLimit = 5;

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

	// использование функции clone
	const FreeThrows& cloned_obj = clone(one);
	std::cout << "One addr: " << &one << std::endl;
	std::cout << "cloned_obj addr: " << &cloned_obj << std::endl;

	FreeThrows cloned_obj2 = one;
	std::cout << "One addr: " << &one << std::endl;
	std::cout << "cloned_obj2 addr: " << &cloned_obj2 << std::endl;
	delete& cloned_obj;
	delete& cloned_obj2;

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

void l8_8()
{
	using namespace std;
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "Can't open " << fn << ". Bye!\n";
		exit(EXIT_FAILURE);
	}

	double objective;
	cout << "Enter the focal length "
		"of your telescope objective in mm: ";
	cin >> objective;
	double eps[kLimit];

	cout << "Enter the focal lengths, in mm, of " << kLimit << " eyepieces:\n";

	for (size_t i = 0; i < kLimit; i++)
	{
		cout << "Eyepiece #" << i + 1 << ": ";
		cin >> eps[i];
	}

	file_it(fout, objective, eps, kLimit);
	file_it(cout, objective, eps, kLimit);

	cout << "Done!\n";
}

void l8_9()
{
	using namespace std;
	const int kArrSize = 80;
	char sample[kArrSize];

	cout << "Enter a string:\n";
	cin.get(sample, kArrSize);

	char* ps = left(sample, 4);
	cout << ps << endl;
	delete[] ps;

	ps = left(sample);
	cout << ps << endl;
	delete[] ps;
}

void l8_10()
{
	using namespace std;

	const char* trip = "Hawaii!";
	unsigned long postal_code = 12345678;
	int i;
	char* temp;

	for (i = 1; i < 10; i++)
	{
		cout << left(postal_code, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;
	}

}

void l8_11()
{
	using namespace std;
	int j = 14;
	int d = 22;

	cout << "j = " << j << " d = " << d << endl;
	swap_t(j, d);
	cout << "Now j = " << j << " d = " << d << endl;

	double k = 1.123;
	double g = 9.4;

	cout << "k = " << k << " g = " << g << endl;
	swap_t(k, g);
	cout << "Now k = " << k << " g = " << g << endl;
}

void l8_12()
{
	using namespace std;
	int j = 14, d = 22;

	cout << "j = " << j << " d = " << d << endl;
	swap_t(j, d);
	cout << "Now j = " << j << " d = " << d << endl;

	int s1[kLimit] = { 0, 2, 4, 5, 6};
	int s2[kLimit] = { 1, 7, 1, 15, 24 };

	cout << "Original arrays:\n";
	show(s1, kLimit);
	show(s2, kLimit);
	swap_t(s1, s2, kLimit);
	cout << "Swapped arrays:\n";
	show(s1, kLimit);
	show(s2, kLimit);

}

void l8_13()
{
	using namespace std;
	cout.precision(3);
	cout.setf(ios::fixed, ios::floatfield);

	int j = 14, d = 22;
	cout << "j = " << j << " d = " << d << endl;
	swap_t(j, d);
	cout << "Now j = " << j << " d = " << d << endl;

	Job Sue = { "Susan Yaffee", 73000.6312, 7 };
	Job Sidney = { "Sidney Grodick", 68000.1725, 4 };

	cout << "Before job swapping:\n";
	show(Sue);
	show(Sidney);
	swap_t(Sue, Sidney);
	cout << "After job swapping:\n";
	show(Sue);
	show(Sidney);

}
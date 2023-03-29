#include "listings.h"
#include "../homework/homework.h"

constexpr int k_limit = 5;

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
	free_throws one = { "Ifelsa Branch", 13, 14 };
	free_throws two = { "Andor Knott", 10, 16 };
	free_throws three = { "Minnie Maximus", 7, 9 };
	free_throws four = { "Whily Looper", 5, 9 };
	free_throws five = { "Long Long", 6, 14 };
	free_throws team = { "Throwgoods", 0, 0 };
	free_throws dups;

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
	const free_throws& cloned_obj = clone(one);
	std::cout << "One addr: " << &one << std::endl;
	std::cout << "cloned_obj addr: " << &cloned_obj << std::endl;

	free_throws cloned_obj2 = one;
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
	double eps[k_limit];

	cout << "Enter the focal lengths, in mm, of " << k_limit << " eyepieces:\n";

	for (size_t i = 0; i < k_limit; i++)
	{
		cout << "Eyepiece #" << i + 1 << ": ";
		cin >> eps[i];
	}

	file_it(fout, objective, eps, k_limit);
	file_it(cout, objective, eps, k_limit);

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

	int s1[k_limit] = { 0, 2, 4, 5, 6 };
	int s2[k_limit] = { 1, 7, 1, 15, 24 };

	cout << "Original arrays:\n";
	show(s1, k_limit);
	show(s2, k_limit);
	swap_t(s1, s2, k_limit);
	cout << "Swapped arrays:\n";
	show(s1, k_limit);
	show(s2, k_limit);

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

	job Sue = { "Susan Yaffee", 73000.6312, 7 };
	job Sidney = { "Sidney Grodick", 68000.1725, 4 };

	cout << "Before job swapping:\n";
	show(Sue);
	show(Sidney);
	swap_t(Sue, Sidney);
	cout << "After job swapping:\n";
	show(Sue);
	show(Sidney);

}

void l8_14()
{
	using namespace std;
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_e[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0},
	};
	double* pd[3];

	for (size_t i = 0; i < 3; i++)
	{
		pd[i] = &mr_e[i].amount;
	}

	cout << "Listing Mr.E's counts of things:\n";
	show_array(things, 6);
	cout << "Listing Mr.E's debts:\n";
	show_array(pd, 3);
}

void l8_15()
{
	using namespace std;
	const int m = 20;
	const int n = -30;
	const double x = 15.5;
	const double y = 25.9;

	cout << lesser(m, n) << endl;
	cout << lesser(y, x) << endl;
	cout << lesser<>(m, n) << endl;
	cout << lesser<int>(x, y) << endl;
}

void sol_8_1()
{
	char st[20] = "hello world!";
	print_str(st);
	print_str(st);
	print_str(st);
	print_str(st, 1);

}

void sol_8_2()
{
	candy_bar bar;
	set_candy_bar(bar);
	print_candy_bar(bar);

	candy_bar cbar;
	set_candy_bar(cbar, "My Candy", 2.05, 800);
	print_candy_bar(cbar);
}

void sol_8_3()
{
	using namespace std;

	string stop = "stop";
	string input{};

	cout << "Enter a string (type \"q\" to exit): " << endl;

	while (getline(cin, input))
	{
		if (input == "q")
		{
			cout << "Bye!" << endl;
			break;
		}
		cout << str_to_upper(input) << '\n';
	}
}

void sol_8_4()
{
	stringy stringy;
	char testing[] = "Reality isnt what it used to be.";
	set(stringy, testing);
	show(stringy);
	show(stringy, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
}

void sol_8_5()
{
	using namespace std;

	int test_int[] = { 1, 7, 2, 6, 9 };
	double test_double[] = { 16.5, 1.4, 8.9, 16.6, 15.2 };
	int temp_int = max5(test_int);
	double temp_d = max5(test_double);

	cout << temp_int << ' ' << temp_d;
}

void sol_8_6()
{
	using namespace std;

	int test_int[] = {1, 7, 2, 6, 9, 25};
	double test_double[] = { 16.5, 1.4, 8.9, 15.2 };
	const int temp_int = maxn(test_int, 6);
	const double temp_d = maxn(test_double, 4);

	cout << temp_int << ' ' << temp_d;

	const char* test_chr[5] = { "asdasd", "Lada", "Trisha", "Marina", "Nikolay" };
	const char* result = maxn(test_chr, 5);
	cout << '\n' << result;
}

void sol_8_7() 
{
	using namespace std;
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_e[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0},
	};
	double* pd[3];

	for (size_t i = 0; i < 3; i++)
	{
		pd[i] = &mr_e[i].amount;
	}

	cout << "Listing Mr.E's counts of things:\n";
	show_total(things, 6);
	cout << "Listing Mr.E's debts:\n";
	show_total(pd, 3);
}

void l9_1()
{
	using namespace std;
	rect rplace{};
	polar pplace{};

	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "\nNext two numbs (q to quit): ";
	}
	cout << "Bye!\n";
}
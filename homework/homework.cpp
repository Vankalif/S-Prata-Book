#include "homework.h"


///////////////////////////////////////////////////
// ==================> hw-8-1 <================== /
///////////////////////////////////////////////////

void print_str(const char* str, int n)
{
	using namespace std;
	static int count = 0;
	++count;

	if (!n)
	{
		cout << str << '\n';
	}
	else
	{
		for (size_t i = 0; i < count; i++)
		{
			cout << str << '\n';
		}
	}
}


///////////////////////////////////////////////////
// ==================> hw-8-2 <================== /
///////////////////////////////////////////////////

void set_candy_bar(candy_bar& bar, const char* name, double weight, int kcal)
{
	bar.name = name;
	bar.weight = weight;
	bar.kсal = kcal;
}

void print_candy_bar(const candy_bar& bar)
{
	using namespace std;
	cout << bar.name << ' ';
	cout << bar.weight << ' ';
	cout << bar.kсal << endl;
}


///////////////////////////////////////////////////
// ==================> hw-8-3 <================== /
///////////////////////////////////////////////////

std::string str_to_upper(std::string str)
{
	std::string temp;
	for (size_t i = 0; i < str.size(); i++)
	{
		temp += toupper(str[i]);
	}
	return temp;
}


///////////////////////////////////////////////////
// ==================> hw-8-4 <================== /
///////////////////////////////////////////////////

void set(stringy& ref, const char* str)
{
	ref.ct = strlen(str);
	ref.str = new char[ref.ct + 1];
	strcpy_s(ref.str, ref.ct + 1, str);

	std::cout << "Previous str address: " << &str << '\n';
	std::cout << "New str address: " << &(ref.str) << '\n';
}

void show(const stringy& ref, int n)
{
	using namespace std;
	for (size_t i = 0; i < n; i++)
	{
		cout << ref.str << '\n';
	}
}

void show(const char* str, int n)
{
	using namespace std;
	for (size_t i = 0; i < n; i++)
	{
		cout << str << '\n';
	}
}


///////////////////////////////////////////////////
// ==================> hw-8-5 <================== /
///////////////////////////////////////////////////

// решение в homework.h


///////////////////////////////////////////////////
// ==================> hw-8-6 <================== /
///////////////////////////////////////////////////

template <>
const char* maxn(const char* arr[], int n)
{
	const char* longest = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (strlen(arr[i]) > strlen(longest))
			longest = arr[i];
	}

	return longest;
}


///////////////////////////////////////////////////
// ==================> hw-8-7 <================== /
///////////////////////////////////////////////////

// решение в homework.h
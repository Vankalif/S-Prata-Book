#pragma once
#include <iostream>
#include "../types/my_types.h"


///////////////////////////////////////////////////
// ==================> hw-8-1 <================== /
///////////////////////////////////////////////////

void print_str(const char*, int n = 0);


///////////////////////////////////////////////////
// ==================> hw-8-2 <================== /
///////////////////////////////////////////////////

void set_candy_bar(candy_bar& bar, const char* name = "Millenium Much", double weight = 2.85, int kcal = 350);
void print_candy_bar(const candy_bar& bar);


///////////////////////////////////////////////////
// ==================> hw-8-3 <================== /
///////////////////////////////////////////////////

std::string str_to_upper(std::string);


///////////////////////////////////////////////////
// ==================> hw-8-4 <================== /
///////////////////////////////////////////////////

void set(stringy& ref, const char* str);
void show(const stringy& ref, int n = 1);
void show(const char* str, int n = 1);


///////////////////////////////////////////////////
// ==================> hw-8-5 <================== /
///////////////////////////////////////////////////

template <typename T>
T max5(const T arr[])
{
	T temp = 0;
	for (size_t i = 0; i < 5; i++)
	{
		if (arr[i] > temp)
		{
			temp = arr[i];
		}
	}
	return temp;
}


///////////////////////////////////////////////////
// ==================> hw-8-6 <================== /
///////////////////////////////////////////////////

template <typename T1>
T1 maxn(T1 arr[], int n)
{
	T1 temp = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] > temp) temp = arr[i];
	}
	return temp;
}

template <>
const char* maxn(const char* arr[], int n);


///////////////////////////////////////////////////
// ==================> hw-8-7 <================== /
///////////////////////////////////////////////////

template <typename T>
void show_total(T arr[], int n)
{
	using namespace std;
	T total = 0;
	cout << "Total things: ";
	for (size_t i = 0; i < n; i++)
	{
		total += arr[i];
	}
	cout << total;
	cout << endl;
}

template <typename T>
void show_total(T* arr[], int n)
{
	using namespace std;
	cout << "Total debts: ";
	T total = 0;
	for (size_t i = 0; i < n; i++)
	{
		total += *arr[i];
	}
	cout << total;
	cout << endl;
}
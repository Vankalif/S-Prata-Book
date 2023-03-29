#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "../types/my_types.h"

inline double square(double x) { return x * x; }

// Обмен значениями по ссылке
void swapr(int& a, int& b);

// Обмен значениями через указатель
void swapp(int* a, int* b);

// Обмен значениями по значению для наглядности
void swapv(int a, int b);


///////////////////////////////////////////////////
// ==================> l8-5 <================== ///
///////////////////////////////////////////////////

// обычные переменные
double cube(double a);

// ссылочные переменные
double refcube(double& ra);


///////////////////////////////////////////////////
// ==================> l8-6 <================== ///
///////////////////////////////////////////////////

// печать структуры
void display(const free_throws& ft);

// задать процент
void set_pc(free_throws& ft);

// добавить значение к структуре из другой структуры
free_throws& accumulate(free_throws& target, const free_throws& source);

// клонирование объекта
const free_throws& clone(free_throws& target);


///////////////////////////////////////////////////
// ==================> l8-7 <================== ///
///////////////////////////////////////////////////


// версия 1 для изменения строки
std::string version1(const std::string& s1, const std::string& s2);

// версия 2 для изменения строки
const std::string& version2(std::string& s1, const std::string& s2);

// версия 3 для изменения строки
const std::string& version3(std::string& s1, const std::string& s2);


///////////////////////////////////////////////////
// ==================> l8-8 <================== ///
///////////////////////////////////////////////////

void file_it(std::ostream& os, double fo, const double fe[], int n);


///////////////////////////////////////////////////
// ==================> l8-9 <================== ///
///////////////////////////////////////////////////

char* left(const char* str, int n = 1);


///////////////////////////////////////////////////
// ==================> l8-10 <================== //
///////////////////////////////////////////////////

// возвращает первых ct цифр из числа num
unsigned long left(unsigned long num, unsigned ct);


///////////////////////////////////////////////////
// ==================> l8-11 <================== //
///////////////////////////////////////////////////
 
// Шаблонная функция
template <typename T> void swap_t(T& a, T& b);

// явное создание экземпляра
template void swap_t<int>(int& a, int& b);
template void swap_t<double>(double& a, double& b);


///////////////////////////////////////////////////
// ==================> l8-12 <================== //
///////////////////////////////////////////////////

// Перегруженный шаблон
template <typename T>
void swap_t(T* a, T* b, int n)
{
	T temp;
	for (size_t i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

// Отобразить массив int
void show(int* arr, int limit);


///////////////////////////////////////////////////
// ==================> l8-13 <================== //
///////////////////////////////////////////////////

// Явная специализация шаблона для типа Job
template <> void swap_t<job>(job& a, job& b);

// Отображение Job
void show(job& j);


///////////////////////////////////////////////////
// ==================> l8-14 <================== //
///////////////////////////////////////////////////

template <typename T>
void show_array(T arr[], int n)
{
	using namespace std;
	cout << "Template A\n";
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	cout << endl;
}

template <typename T>
void show_array(T * arr[], int n)
{
	using namespace std;
	cout << "Template B\n";
	for (size_t i = 0; i < n; i++)
	{
		cout << *arr[i] << ' ';
	}

	cout << endl;
}


///////////////////////////////////////////////////
// ==================> l8-15 <================== //
///////////////////////////////////////////////////

// Возвращает большее из a и b
template <typename T>
T lesser(T a, T b)
{
	return a < b ? a : b;
}

// меньшее по модулю
int lesser(int a, int b);


///////////////////////////////////////////////////
// ==================> l9-1 <================== ///
///////////////////////////////////////////////////

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
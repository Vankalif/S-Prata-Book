#include "functions.h"
#include <iostream>

void swapr(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swapp(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swapv(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

double cube(double a)
{	
	a *= a * a;
	return a;
}

double refcube(double& ra)
{
	ra *= ra * ra;
	return ra;
}

// ==================> l8-6 <==================

void display(const FreeThrows& ft)
{
	using std::cout;
	cout << "Name: " << ft.name << '\n';
	cout << " Made: " << ft.made << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Percent: " << ft.percent << '\n';
}

void set_pc(FreeThrows& ft)
{
	if (ft.attempts != 0)
	{
		ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
	}
	else
	{
		ft.percent = 0;
	}
}

FreeThrows& accumulate(FreeThrows& target, const FreeThrows& source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);

	return target;
}

// ==================> l8-7 <==================

std::string version1(const std::string& s1, const std::string& s2)
{
	/* 
	  в данной функции происходим скрытое копирование в
	  операторе return по причине того, что переменная temp
	  является локальной для фун-ии version1. В операторе 
	  return создается анонимная переменная, ссылка на которую
	  возвращается в вызывающий код.
	*/
	using namespace std;

	string temp;
	temp = s2 + s1 + s2;

	return temp;
}

// Обладает побочным эффектом
const std::string& version2(std::string& s1, const std::string& s2)
{
	/*
	  Здесь ничего удивительного, побочный эффект
	  вызван изменениями в данных, переданных по ссылке,
	  на то она и ссылка.
	*/
	s1 = s2 + s1 + s2;

	// безопасно возвращать ссылку, которая была передана в функию
	return s1;
}

// Плохой дизайн функции
const std::string& version3(std::string& s1, const std::string& s2)
{
	/*
	  из-за того, что в возвращаемом типе функции
	  указан квалификатор const, мы говорим, что
	  возвращаемое значение должно существовать после
	  заврешения работы функции, но temp удалется из стека.
	*/
	using namespace std;

	string temp;
	temp = s2 + s1 + s2;

	return temp;
}

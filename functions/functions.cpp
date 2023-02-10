#include "functions.h"

// Обмен значениями по ссылке
void swapr(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

// Обмен значениями через указатель
void swapp(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// Обмен значениями по значению для наглядности
void swapv(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

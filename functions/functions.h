#pragma once

inline double square(double x) { return x * x; }

// Обмен значениями по ссылке
void swapr(int& a, int& b);

// Обмен значениями через указатель
void swapp(int* a, int* b);

// Обмен значениями по значению для наглядности
void swapv(int a, int b);
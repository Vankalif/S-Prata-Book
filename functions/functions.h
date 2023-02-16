#pragma once
#include "my_types.h"

inline double square(double x) { return x * x; }

// ќбмен значени€ми по ссылке
void swapr(int& a, int& b);

// ќбмен значени€ми через указатель
void swapp(int* a, int* b);

// ќбмен значени€ми по значению дл€ нагл€дности
void swapv(int a, int b);


// ==================> l8-5 <==================

// обычные переменные
double cube(double a);

// ссылочные переменные
double refcube(double& ra);


// ==================> l8-6 <==================

// печать структуры
void display(const FreeThrows & ft);

// задать процент
void set_pc(FreeThrows & ft);

// добавить значение к структуре из другой структуры
FreeThrows& accumulate(FreeThrows & target, const FreeThrows & source);


// ==================> l8-7 <==================

// верси€ 1 дл€ изменени€ строки
std::string version1(const std::string & s1, const std::string & s2);

// верси€ 2 дл€ изменени€ строки
const std::string& version2(std::string & s1, const std::string & s2);

// верси€ 3 дл€ изменени€ строки
const std::string& version3(std::string & s1, const std::string & s2);


// ==================> l8-8 <==================

void file_it(std::ostream& os, double fo, const double fe[], int n);
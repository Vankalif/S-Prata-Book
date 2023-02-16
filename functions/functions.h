#pragma once
#include "my_types.h"

inline double square(double x) { return x * x; }

// ����� ���������� �� ������
void swapr(int& a, int& b);

// ����� ���������� ����� ���������
void swapp(int* a, int* b);

// ����� ���������� �� �������� ��� �����������
void swapv(int a, int b);


// ==================> l8-5 <==================

// ������� ����������
double cube(double a);

// ��������� ����������
double refcube(double& ra);


// ==================> l8-6 <==================

// ������ ���������
void display(const FreeThrows & ft);

// ������ �������
void set_pc(FreeThrows & ft);

// �������� �������� � ��������� �� ������ ���������
FreeThrows& accumulate(FreeThrows & target, const FreeThrows & source);


// ==================> l8-7 <==================

// ������ 1 ��� ��������� ������
std::string version1(const std::string & s1, const std::string & s2);

// ������ 2 ��� ��������� ������
const std::string& version2(std::string & s1, const std::string & s2);

// ������ 3 ��� ��������� ������
const std::string& version3(std::string & s1, const std::string & s2);


// ==================> l8-8 <==================

void file_it(std::ostream& os, double fo, const double fe[], int n);
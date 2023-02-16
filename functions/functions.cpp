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

void display(const FreeThrows & ft)
{
	using std::cout;
	cout << "Name: " << ft.name << '\n';
	cout << " Made: " << ft.made << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Percent: " << ft.percent << '\n';
}

void set_pc(FreeThrows & ft)
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

FreeThrows& accumulate(FreeThrows & target, const FreeThrows & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);

	return target;
}


// ==================> l8-7 <==================

std::string version1(const std::string & s1, const std::string & s2)
{
	/*
		� ������ ������� ���������� ������� ����������� �
		��������� return �� ������� ����, ��� ���������� temp
		�������� ��������� ��� ���-�� version1. � ���������
		return ��������� ��������� ����������, ������ �� �������
		������������ � ���������� ���.
	*/
	using namespace std;

	string temp;
	temp = s2 + s1 + s2;

	return temp;
}

// �������� �������� ��������
const std::string& version2(std::string & s1, const std::string & s2)
{
	/*
		����� ������ �������������, �������� ������
		������ ����������� � ������, ���������� �� ������,
		�� �� ��� � ������.
	*/
	s1 = s2 + s1 + s2;

	// ��������� ���������� ������, ������� ���� �������� � ������
	return s1;
}

// ������ ������ �������
const std::string& version3(std::string & s1, const std::string & s2)
	{
		/*
		  � ����������� ������� �� ������� �����������,
		  ��� ���������� ������, �� ���������� ���������,
		  ������� ������ ����� ������. �������� ������������
		  ������ �� ��������� ���������� - �����������!
		*/
		using namespace std;

		string temp;
		temp = s2 + s1 + s2;

		return temp;
	}


// ==================> l8-8 <==================

void file_it(std::ostream& os, double fo, const double fe[], int n)
{
	using namespace std;
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);
	os.precision(0);
	os << "Focal length of objective " << fo << "mm.\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(12);
	os << "f.1. eyepiece";
	os.width(15);
	os << "magnification" << endl;
	
	for (size_t i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);
}
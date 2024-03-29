#include "functions.h"

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


///////////////////////////////////////////////////
// ==================> l8-6 <================== ///
///////////////////////////////////////////////////

void display(const free_throws& ft)
{
	using std::cout;
	cout << "Name: " << ft.name << '\n';
	cout << " Made: " << ft.made << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws& ft)
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

free_throws& accumulate(free_throws& target, const free_throws& source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);

	return target;
}

const free_throws& clone(free_throws& target)
{
	free_throws* pft = new free_throws;
	*pft = target;
	return *pft;
}

///////////////////////////////////////////////////
// ==================> l8-7 <================== ///
///////////////////////////////////////////////////

std::string version1(const std::string& s1, const std::string& s2)
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
const std::string& version2(std::string& s1, const std::string& s2)
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
const std::string& version3(std::string& s1, const std::string& s2)
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


///////////////////////////////////////////////////
// ==================> l8-8 <================== ///
///////////////////////////////////////////////////

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


///////////////////////////////////////////////////
// ==================> l8-9 <================== ///
///////////////////////////////////////////////////

char* left(const char* str, int n)
{
	if (n < 0)
	{
		n = 0;
	}
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; i++)
	{
		p[i] = str[i];
	}
	while (i <= n)
	{
		p[i++] = '\0';
	}
	return p;
}


///////////////////////////////////////////////////
// ==================> l8-10 <================== //
///////////////////////////////////////////////////

unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;

	if (num == 0 || ct == 0)
	{
		return 0;
	}

	while (n /= 10)
	{
		digits++;
	}

	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
		{
			num /= 10;
		}
		return num;
	}
	else
	{
		return num;
	}

}


///////////////////////////////////////////////////
// ==================> l8-11 <================== //
///////////////////////////////////////////////////

template <typename T>
void swap_t(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}


///////////////////////////////////////////////////
// ==================> l8-12 <================== //
///////////////////////////////////////////////////

void show(int* arr, int limit)
{
	std::cout << std::endl;
	for (size_t i = 0; i < limit; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

}


///////////////////////////////////////////////////
// ==================> l8-13 <================== //
///////////////////////////////////////////////////

template <> void swap_t<job>(job& a, job& b)
{
	std::cout << "\nExplict specification used\n";
	double tempd;
	int tempi;

	tempd = a.salary;
	a.salary = b.salary;
	b.salary = tempd;

	tempi = b.floor;
	b.floor = a.floor;
	a.floor = tempi;
}

void show(job& j)
{
	using namespace std;
	cout << j.name << ": $" << j.salary
		<< " on floor " << j.floor << endl;
}


///////////////////////////////////////////////////
// ==================> l8-15 <================== //
///////////////////////////////////////////////////

int lesser(int a, int b)
{
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	return a < b ? a : b;
}


///////////////////////////////////////////////////
// ==================> l9-1 <================== ///
///////////////////////////////////////////////////

polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer{};

	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);

	return answer;
}

void show_polar(polar dapos)
{
	using namespace std;
	const double k_rad_to_deg = 57.29577951;

	cout << "distanse " << dapos.distance;
	cout << " angle " << dapos.angle * k_rad_to_deg;
}
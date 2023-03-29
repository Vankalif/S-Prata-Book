#include "questions.h"

///////////////////////////////////////////////////
// ==================> q-8-2 <================== //
///////////////////////////////////////////////////

void song(char* name, int times)
{
}


///////////////////////////////////////////////////
// ==================> q-8-3 <================== //
///////////////////////////////////////////////////

void iquote(int target)
{
	using namespace std;
	cout << "\'" << target << "\'";
}

void iquote(double target)
{
	using namespace std;
	cout << "\'" << target << "\'";
}

void iquote(std::string target)
{
	using namespace std;
	cout << "\'" << target << "\'";
}


///////////////////////////////////////////////////
// ==================> q-8-4 <================== //
///////////////////////////////////////////////////

void boxPrinter(const box& box)
{
	using namespace std;
	cout << box.marker << ' ';
	cout << box.height << ' ';
	cout << box.length << ' ';
	cout << box.volume << ' ';
	cout << box.width;
}

box& boxVolume(box& box)
{
	box.volume = box.height * box.length * box.width;
	return box;
}
#pragma once

#include <string>

struct FreeThrows
{
	std::string name;
	int made;
	int attempts;
	float percent;
};

struct Job
{
	char name[40];
	double salary;
	int floor;
};
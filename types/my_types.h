#pragma once
#ifndef MY_TYPES_H
#define MY_TYPES_H


#include <string>
#include <cstring>

struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};

struct job
{
	char name[40];
	double salary;
	int floor;
};

struct debts
{
	char name[50];
	double amount;
};

struct box
{
	char marker[40];
	float height;
	float width;
	float length;
	float volume;
};

struct candy_bar
{
	std::string name;
	double weight;
	unsigned kñal;
};

struct stringy
{
	char* str;
	int ct;
};

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};

#endif
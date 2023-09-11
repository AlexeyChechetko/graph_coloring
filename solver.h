#pragma once

#include "conditions.h"

class solver
{
public:
	solver(const char name[]);
	~solver();
	void solve();
	void print_solution();
private:
	conditions C;
	int* color_of_vertexes;
	int count_of_colors;
	int** A;
};


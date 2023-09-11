#pragma once

#include <iostream>
#include <fstream>

class conditions
{
public:
	explicit conditions(const char name[]);
	~conditions();
	void print();
	int return_c_ver();
	int return_c_edg();
	int** return_a_mat();
private:
	int count_vertexes;
	int count_edges;
	int** adjacency_matrix;
};


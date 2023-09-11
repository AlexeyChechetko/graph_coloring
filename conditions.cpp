#include "conditions.h"

conditions::conditions(const char name[])
{
	std::ifstream data(name); // write relative path from folder where main.cpp exist

	if (data)
	{
		int i, j;
		data >> count_vertexes;
		data >> count_edges;
		adjacency_matrix = new int* [count_vertexes];
		for (i = 0; i < count_vertexes; ++i)
		{
			adjacency_matrix[i] = new int[count_vertexes];
		}
		for (i = 0; i < count_vertexes; ++i)
		{
			for (j = 0; j < count_vertexes; ++j)
			{
				if (j == i)
				{
					adjacency_matrix[i][j] = 1;
					continue;
				}
				adjacency_matrix[i][j] = 0;
			}
		}
		while (data >> i >> j)
		{
			adjacency_matrix[i][j] = 1;
			adjacency_matrix[j][i] = 1;
		}
	}
	else
	{
		std::cout << "adjacency_matrixmth is wrong" << std::endl;
	}
}

conditions::~conditions()
{
	for (int i = 0; i < count_vertexes; ++i)
	{
		delete[] adjacency_matrix[i];
	}
	delete[] adjacency_matrix;
}

void conditions::print()
{
	std::cout << "Count of vertexes: " << count_vertexes << std::endl;
	std::cout << "Count of edges: " << count_edges << std::endl;

	std::cout << "Adjacency matrix: " << std::endl;
	for (int i = 0; i < count_vertexes; ++i)
	{
		for (int j = 0; j < count_vertexes; ++j)
		{
			std::cout << adjacency_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int conditions::return_c_ver()
{
	return count_vertexes;
}

int conditions::return_c_edg()
{
	return count_edges;
}

int** conditions::return_a_mat()
{
	return adjacency_matrix;
}



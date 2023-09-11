#include "solver.h"

solver::solver(const char name[]) : C(name), color_of_vertexes(new int[C.return_c_ver()]),
									count_of_colors(0)
{
	int i{0}, j{0};
	// C.print();
	for (i = 0; i < C.return_c_ver(); ++i)
	{
		*(color_of_vertexes + i) = 0;
	}
	A = new int* [C.return_c_ver()];
	for (i = 0; i < C.return_c_ver(); ++i)
	{
		*(A + i) = new int[C.return_c_ver()];
	}
	for (i = 0; i < C.return_c_ver(); ++i)
	{
		for (j = 0; j < C.return_c_ver(); ++j)
		{
			A[i][j] = C.return_a_mat()[i][j];
		}
	}
}

solver::~solver()
{
	delete[] color_of_vertexes;
}

void solver::solve()
{
	int i{0}, j{0};

	count_of_colors = 1;
	for (i = 0; i < C.return_c_ver(); ++i)
	{
		if (color_of_vertexes[i] != 0)
		{
			continue;
		}
		else
		{
			color_of_vertexes[i] = count_of_colors;
			while (true)
			{
				for (j = i + 1; j < C.return_c_ver(); ++j)
				{
					if (A[i][j] == 0 && color_of_vertexes[j] == 0)
					{
						break;
					}
				}
				if (j == C.return_c_ver())
				{
					break;
				}
				color_of_vertexes[j] = count_of_colors;
				for (int l = 0; l < C.return_c_ver(); ++l)
				{
					A[i][l] += A[j][l];
				}
			}
			++count_of_colors;
		}
	}
	--count_of_colors;
}

void solver::print_solution()
{
	std::cout << "Count of colors: " << count_of_colors << std::endl;
	std::cout << "Colors of vertexes:" << std::endl;
	for (int i = 0; i < C.return_c_ver(); ++i)
	{
		std::cout << i << " vertex: " << color_of_vertexes[i] << std::endl;
	}
}

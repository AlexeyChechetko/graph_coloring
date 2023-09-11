#include "solver.h"

int main(void)
{
	solver S("../data/gc_70_9");
	S.solve();
	S.print_solution();

	return 0;
}
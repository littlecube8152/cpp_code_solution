#include "Bruno.h"
#include <vector>

namespace {

int variable_example = 0;

int FunctionExample(int P) { return 1 - P; }

}  // namespace

void Bruno(int N, int L, std::vector<int> A) {
  	int i = 0, j = 0, x = 0, y = 0, z = 0;
	for(; i < N; i++)
		if(A[i] == 1)
		{
			x = i;
			for(; j < i; j++)
				Remove(j);
			j = x + 1;
			i = x + 1;
			break;
		}
	for(; i < N; i++)
	{
		if(y == 0 && A[i])
		   	y = i;
		else if(y && A[i])
		{
			z = i;
			for(; j < y; j++)
				Remove(j);
			j++;
			for(; j < z; j++)
				Remove(j);
			Remove(y);
			Remove(z);
			j = z + 1;
			y = 0;
		}	
	}
	for(; j < N; j++)
		Remove(j);
	Remove(x);
}

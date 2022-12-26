#include "Anna.h"
#include <vector>

namespace {

int variable_example = 0;

}

void Anna(int N, std::vector<char> S) {
	int i = 0;
	while(i < N && S[i] != 'X')
	{
		Send(0);
		i++;
	}
	if(i == N)
		return;
	Send(1);
	i++;
	char tar = 'Y';
	while(i < N)
	{
		if(S[i] == tar)
		{
			Send(1);
			tar = (tar == 'Y' ? 'Z' : 'Y');
		}
		else 
			Send(0);
		i++;
	}
}

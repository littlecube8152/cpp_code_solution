#include "Bruno.h"
#include <bits/stdc++.h>
using namespace std;

string Bruno(int N, vector<std::vector<int>> T) {
	int sum = 0;
	for (auto S : T)
		for (auto c : S)
			sum += (c == 1);
	return (sum <= 15 ? "B" : "A");
}

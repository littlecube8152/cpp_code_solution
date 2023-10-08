#include "plants.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define ll long long
using namespace std;

int n;
vector<int> last;

void init(int k, vector<int> r)
{
	n = r.size();
	last.resize(2 * n);
	for (int i = 0; i < n; i++)
		r.emplace_back(r[i]);
	for (int i = 1; i < 2 * n; i++)
		r[i] += r[i - 1];
	last = r;
	return;
}

int compare_plants(int x, int y)
{
	int sum = last[y - 1] - (x ? last[x - 1] : 0);
	if (sum == y - x || last[n - 1] - sum == 0)
		return -1;
	if (sum == 0 || last[n - 1] - sum == n - (y - x))
		return 1;
	return 0;
}

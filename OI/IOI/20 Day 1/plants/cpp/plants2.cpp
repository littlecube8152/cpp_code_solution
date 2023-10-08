#include "plants.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define ll long long
using namespace std;

int n;
vector<int> a;

void init(int k, vector<int> r)
{
	n = r.size();
	a.resize(n);
	for (int i = 0; i < n; i++)
		r[i] = k - 1 - r[i];
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		for (;; j++)
			if (r[j] == 0)
				break;
		int cnt = 1, cur = (j - 1 + n) % n;
		while (cnt < k)
		{
			if (r[cur] == 0)
			{
				j = cur;
				cur = (j - 1 + n) % n;
				cnt = 1;
			}
			else
				cur = (cur - 1 + n) % n, cnt++;
		}
		a[j] = i;
		r[j] = 1e9;
		for (int t = 0; t < k; t++, j = (j - 1 + n) % n)
			r[j]--;
	}
	return;
}

int compare_plants(int x, int y)
{

	if (a[x] < a[y])
		return -1;
	return 1;
	return 0;
}

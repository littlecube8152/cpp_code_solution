#include "biscuits.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans[400000];

long long count_tastiness(ll x, vector<ll> a)
{
	a.resize(60);
	int k = 60;
	vector<ll> sum(k), fold(k);
	sum[0] = a[0];
	for (int i = 1; i < k; i++)
		sum[i] = sum[i - 1] + (a[i] << i);
	for (int i = 0; i < k; i++)
		if (sum[i] / x / (1LL << i) == 0)
			fold[i] = -1;
		else
			fold[i] = min((1LL << i) - 1, (sum[i] - x * (1LL << i)) / x);
	int sz = 1;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < sz; j++)
			if(ans[j] <= fold[i])
				ans[sz++] = (1LL << i) + ans[j];
			else break;
	}
	return sz;
}

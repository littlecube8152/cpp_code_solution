#include "biscuits.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
	map<ll, ll> mp;
	mp[1LL << 62]++;
	for (int i = k - 1; i >= 0; i--)
	{
		map<ll, ll> nxt;
		for (auto [p, v] : mp)
			if (p >= (1LL << i))
			{
				nxt[(1LL << i) - 1] += v;
				if (fold[i] >= 0)
					nxt[min(p - (1LL << i), fold[i])] += v;
			}
			else
				nxt[p] += v;
		nxt.swap(mp);
	}
	return mp[0];
}

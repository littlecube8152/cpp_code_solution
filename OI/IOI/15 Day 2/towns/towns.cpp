#include "towns.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int hubDistance(int N, int sub)
{
	vector<int> disU(N, 0), disV(N, 0), disD(N, 0);
	map<pii, int> mp;
	int u = 0, v = 0, mx = 0, uv, R = 1e9;
	for (int i = 1; i < N; i++)
	{
		int cur = getDistance(0, i);
		if (cur > mx)
			u = i, mx = cur;
	}
	for (int i = 0; i < N; i++)
		disU[i] = getDistance(u, i);
	mx = 0;
	for (int i = 0; i < N; i++)
		if (disU[i] > mx)
			v = i, mx = disU[i];
	for (int i = 0; i < N; i++)
		disV[i] = getDistance(v, i);
	uv = getDistance(u, v);
	for (int i = 0; i < N; i++)
	{
		int d = (disU[i] + disV[i] - uv) / 2;
		disD[i] = d;
		R = min(R, max(disU[i] - d, disV[i] - d));
		mp[pii(disU[i] - d, disV[i] - d)]++;
	}
	int cnt = 0;
	pii check = pii(0, 0);
	for (auto [p, k] : mp)
	{
		if (p.F == R || p.S == R)
		{
			if (cnt <= N / 2 && k <= N / 2 && (N - cnt - k) <= N / 2)
				return R;
			if (cnt <= N / 2 && (N - cnt - k) <= N / 2)
				check = p;
		}
		cnt += k;
	}
	if (check.F != 0 && sub != 2 && sub != 4)
	{
		vector<int> v;
		for (int i = 0; i < N; i++)
			if (check == pii(disU[i] - disD[i], disV[i] - disD[i]))
				v.emplace_back(i);
		int cur = 0, health = 0;
		for (auto i : v)
			if (health == 0)
				cur = i, health = 1;
			else
			{
				int d = getDistance(cur, i);
				if (d == disD[cur] + disD[i])
					health--;
				else
					health++;
			}
		health = 0;
		for (auto i : v)
			if(i == cur || getDistance(cur, i) < disD[cur] + disD[i])
				health++;
		if(health <= N / 2)
			return R;
	}

	return -R;
}

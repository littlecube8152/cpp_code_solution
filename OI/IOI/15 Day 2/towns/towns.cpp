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
	vector<int> dis0(N, 0), disU(N, 0), disD(N, 0);
	map<pii, int> mp;
	int u = 0, v = 0, mx = 0, uv, u0, v0, luv, R = 1e9;
	for (int i = 1; i < N; i++)
	{
		dis0[i] = getDistance(0, i);
		if (dis0[i] > mx)
			u = i, mx = dis0[i];
	}
	for (int i = 0; i < N; i++)
		disU[i] = getDistance(u, i);
	mx = 0;
	for (int i = 0; i < N; i++)
		if (disU[i] > mx)
			v = i, mx = disU[i];

	uv = disU[v];
	u0 = dis0[u];
	v0 = dis0[v];
	luv = (uv + u0 - v0) / 2;
	for (int i = 0; i < N; i++)
	{
		disD[i] = (disU[i] + dis0[i] - u0) / 2;
		if (disU[i] - disD[i] > luv)
			disD[i] = disU[i] - luv;

		R = min(R, max(disU[i] - disD[i], uv - (disU[i] - disD[i])));
		mp[pii(disU[i] - disD[i], uv - (disU[i] - disD[i]))]++;
	}
	vector<int> c;

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
	if (check.F != 0)
	{
		vector<int> v;
		vector<int> power(N);
		for (int i = 0; i < N; i++)
			if (check == pii(disU[i] - disD[i], uv - (disU[i] - disD[i])))
				v.emplace_back(i);
		int cur = 0, health = 0;
		for (auto i : v)
			if (health == 0)
			{
				power[i]++;
				cur = i, health = 1;
			}
			else
			{
				int d = getDistance(cur, i);
				if (d == disD[cur] + disD[i])
				{
					power[i]++;
					health--;
				}
				else
				{
					power[cur]++;
					health++;
				}
			}
		health = 0;
		for (int i = 0; i < N; i++)
			if (power[i] && (i == cur || getDistance(cur, i) < disD[cur] + disD[i]))
				health += power[i];
		if (health <= N / 2)
			return R;
	}

	return -R;
}

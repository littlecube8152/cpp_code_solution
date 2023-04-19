#pragma GCC optimize("Ofast")
#include "walk.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, K, S, T;
multiset<pll> st;
vector<int> in[100005], out[100005];

ll min_distance(vector<int> x, vector<int> h, vector<int> l, vector<int> r, vector<int> y, int s, int g)
{
	N = x.size(), M = l.size();
	for (int i = 0; i < M; i++)
	{
		in[l[i]].emplace_back(y[i]);
		if (r[i] < N - 1)
			out[r[i]].emplace_back(y[i]);
	}
	out[0].emplace_back(0);
	st.insert(pll(0, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j : in[i])
		{
			ll dis = 1e18;
			auto iter = st.lower_bound(pll(j, 0));
			if (iter != st.end())
				dis = min(dis, iter->S + abs(j - iter->F));
			if (iter != st.begin())
			{
				--iter;
				dis = min(dis, iter->S + abs(j - iter->F));
			}
			st.insert(pll(j, dis));
		}
		for (int j : out[i])
			st.erase(st.lower_bound(pll(j, 0)));
	}
	if(st.empty())
		return -1;
	ll ans = st.begin()->F + st.begin()->S + x[N - 1] - x[0];
	return (ans >= 1e18 ? -1 : ans);
}

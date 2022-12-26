#include "sorting.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

// 0 1 2    0 1 2
//          0   2
// 0 1      0 1
//   1 2
// 1 2 0    1 2 0

vector<pii> ans;

void dfs(int u, vector<int> &p, vector<int> &vis)
{
	vis[u] = 1;
	if (!vis[p[u]])
	{
		ans.emplace_back(pii(u, p[u]));
		dfs(p[u], p, vis);
	}
}

int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[])
{
	auto check = [&](int K)
	{
		vector<int> v(N), vis(N, 0), pos(N);
		ans.clear();
		for (int i = 0; i < N; i++)
			v[i] = S[i];
		for (int i = 0; i < K; i++)
			swap(v[X[i]], v[Y[i]]);
		for (int i = 0; i < N; i++)
			if (!vis[i])
				dfs(i, v, vis);
		if(ans.size() <= K)
		{
			reverse(ans.begin(), ans.end());
			while(ans.size() <= K)
				ans.emplace_back(pii(0, 0));
			for(int i = 0; i < N; i++)
				pos[i] = i, v[i] = i;
			for(int i = K - 1; i >= 0; i--)
			{
				P[i] = pos[ans[i].F];
				Q[i] = pos[ans[i].S];
				tie(v[X[i]], v[Y[i]], pos[v[X[i]]], pos[v[Y[i]]]) = make_tuple(v[Y[i]], v[X[i]], pos[v[Y[i]]], pos[v[X[i]]]);
			}
			return true;
		}
		else 
			return false;
	};
	int L = 0, R = M;
	while(L < R)
	{
		int mid = (L + R) / 2;
		if(check(mid))
			R = mid;
		else 
			L = mid + 1;
	}
	check(L);
	return L;
}

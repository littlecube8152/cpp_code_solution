#include "Ali.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, pre[10005], dis[10005];

pii decode(ll p, int N)
{
	ll acc = 0;
	for(int i = 0; i < N; i++)
		if(acc <= p && p < acc + N - i - 1)
			return pii(i, i + 1 + p - acc);
		else 
			acc += N - i - 1;
	assert(0);
}

vector<int> E[10005];

void dfs(int u)
{
	for(int v : E[u])
		if(pre[u] != v)
		{
			pre[v] = u;
			dis[v] = dis[u] + 1;
			dfs(v);
		}
}



void Init(int n, vector<int> U, vector<int> V) 
{
	N = n;
	for(int i = 0; i < N; i++)
		E[i].clear();
	for(int i = 0; i < N - 1; i++)
	{
		E[U[i]].emplace_back(V[i]);
		E[V[i]].emplace_back(U[i]);
	}
	for(int i = 0; i < N; i++)
		SetID(i, i);
	
	dfs(0);
	cerr << "Init\n";
}

int dist(int x, int y)
{
	int ans = 0;
	for(;x != y; ans++)
	{
		if(dis[x] < dis[y])
			swap(x, y);
		x = pre[x];
	}
	return ans;
}

string SendA(string S) 
{
	ll r = 0;
	for(char c : S)
		r = (r << 1) + (c == '1');

	string res;

	for(int q = 0; (q << 20) + r <= N * (N - 1) / 2; q++)
	{
		cerr << "Sending " << q << " with remainder " << r;
		auto [x, y] = decode((q << 20) + r, N);
		cerr << ", which is vertex " << x << ", " << y << '\n';
		int d = dist(x, y);
		for(int p = 13; p >= 0; p--)
			res.push_back(((d >> p) & 1) ? '1' : '0');
	}	
	cerr << "Ali: Sent\n";
	return res;
}

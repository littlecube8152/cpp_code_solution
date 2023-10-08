#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define NOT 1 ^
using namespace std;

int n, x[55][3], vis[105], target[105], E[105][105];
bitset<105> reach[105], good[105];

int id(int x)
{
	return 2 * x;
}

void ban(int u, int v)
{
	E[u][NOT v] = 1;
	E[v][NOT u] = 1;
}

void reset(int* p)
{
	fill(p, p + 2 * n, 0);
}

bool dfs(int u)
{
	vis[u] = 1;
	for (int v = 0; v < 2 * n; v++)
		if (E[u][v] && !vis[v])
			if (dfs(v))
				return true;
	return target[u];
}

void why(int u)
{
	reach[u] = 0;
	reach[u][u] = 1;
	vis[u] = 1;
	for (int v = 0; v < 2 * n; v++)
		if (E[u][v])
		{
			if (!vis[v])
				why(v);
			reach[u] |= reach[v];
		}
}

void owo(int u, int t)
{
	vis[u] = 1;
	if (!target[NOT u])
		target[NOT u] = t;
	for (int v = 0; v < 2 * n; v++)
		if (E[u][v] && vis[v])
			owo(v, t);		
}

int bad[55][2];

int fuck(int i)
{

	int res = 0;

	if (i >= n)
	{
		return 1;
	}
	if (target[id(i)] || target[NOT id(i)])
		return fuck(i + 1);

	reset(vis);
	if (!dfs(id(i)))
	{
		reset(vis);
		owo(id(i), i + 1);
		res += fuck(i + 1);
		for (int j = 0; j < 2 * n; j++)
			if (target[j] == i + 1)
				target[j] = 0;
	}	
	if (res >= 4)
		return 4;

	reset(vis);
	if (!dfs(NOT id(i)))
	{
		reset(vis);
		owo(NOT id(i), i + 1);
		res += fuck(i + 1);
		for (int j = 0; j < 2 * n; j++)
			if (target[j] == i + 1)
				target[j] = 0;
	}
	return res;
}

void build()
{
	reset(target);
	for (int i = 0; i < n; i++)
	{
		if (target[id(i)] || target[NOT id(i)])
			continue;

		reset(vis);
		target[NOT id(i)] = -2;
		bool flag = dfs(id(i));
		target[NOT id(i)] = 0;

		if (flag)
		{
			reset(vis);
			owo(NOT id(i), -1);
			continue;
		}

		reset(vis);
		target[id(i)] = -2;
		flag = dfs(NOT id(i));
		target[id(i)] = 0;
		if (flag)
		{
			reset(vis);	
			owo(id(i), -1);
		}
	}
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int t = 0; t < 3; t++)
		for (int i = 0; i < n; i++)
			cin >> x[i][t];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int d[4] = {};
			for (int t = 0; t <= 2; t++)
				d[x[i][t] + 2 * x[j][t]]++;
			if (!d[0])
				ban(NOT id(i), NOT id(j));
			if (!d[1])
				ban(    id(i), NOT id(j));
			if (!d[2])
				ban(NOT id(i),     id(j));
			if (!d[3])
				ban(    id(i),     id(j));
		}
	
	build();
	if (fuck(0) != 3)
		cout << -1 << '\n';
	else 
	{
		reset(vis);
		for (int i = 0; i < 2 * n; i++)
			if (!vis[i])
				why(i);
		for (int i = 0; i < 2 * n; i++)
			good[i] = reach[i];

		vector<pii> e;
		for (int i = 0; i < 2 * n; i++)
		{	
			for (int j = 0; j < 2 * n; j++)
				if (E[i][j] && i / 2 < j / 2)
					e.emplace_back(i, j);
		}
		// what the fuck?
		mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
		shuffle(e.begin(), e.end(), rd);
		for (int i = 0; i < e.size(); i++)
		{
		
			auto [u, v] = e[i];
			E[u][v] = E[NOT v][NOT u] = 0;

			reset(vis);
			for (int j = 0; j < 2 * n; j++)
				if (!vis[j])
					why(j);
			bool flag = 1;
			for (int j = 0; j < 2 * n; j++)
				if (good[j] != reach[j])
					flag = 0;

			if (!flag)
				E[u][v] = E[NOT v][NOT u] = 1;
			else 
				e.erase(e.begin() + i), i--;
		}

		cout << e.size() << '\n';
		for (auto [i, j] : e)
		{
			if (i % 2 == 1)
				cout << '!';
			cout << 'x' << i / 2 + 1 << " -> ";
			if (j % 2 == 1)
				cout << '!';
			cout << 'x' << j / 2 + 1 << '\n';
		}
	}
}

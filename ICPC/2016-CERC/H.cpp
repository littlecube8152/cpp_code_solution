#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, t, q, g[1005][1005], vis[1005][1005], dsu[1000006], val[1000006], pre[1000006][21];
vector<int> E[1000006];
pii io[1000006];

vector<pii> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

bool btw(int l, int mid, int r)
{
	return l <= mid && mid <= r;
}

int id(int i, int j)
{
	return (i - 1) * n + j;
}

int find(int k)
{
	return dsu[k] == k ? k : dsu[k] = find(dsu[k]);
}

void dfs(int u)
{
	io[u].F = ++t;
	for (int v : E[u])
	{
		pre[v][0] = u;
		dfs(v);
	}
	io[u].S = t;
}

bool ischild(int r, int c)
{
	return io[r].F <= io[c].F && io[c].S <= io[r].S;
}

int lca(int u, int v)
{
	for (int p = 20; p >= 0; p--)
		if (!ischild(pre[u][p], v))
			u = pre[u][p];
	if (!ischild(u, v))
		u = pre[u][0];
	return u;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = 1e9;
	
	{
		queue<pii> q;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				char c;
				cin >> c;
				if (c == '#')
					g[i][j] = 0, q.emplace(pii(i, j));
			}
		for (int i = 1; i <= n; i++)
			q.emplace(0, i), q.emplace(i, 0), q.emplace(n + 1, i), q.emplace(i, n + 1);
		while (!q.empty())
		{
			auto [i, j] = q.front();
			q.pop();
			for (auto [x, y] : d)
				if (btw(1, i + x, n) && btw(1, j + y, n) && g[i + x][j + y] >= 1e8)
					g[i + x][j + y] = g[i][j] + 1, q.emplace(pii(i + x, j + y));
		}
	}

	d.resize(4);

	vector<pii> v;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			v.emplace_back(i, j), val[id(i, j)] = g[i][j];
	sort(v.begin(), v.end(), [&](pii p, pii q) { return g[p.F][p.S] > g[q.F][q.S]; });	
	
	for (int i = 1; i <= n * n; i++)
		dsu[i] = i;
	for (auto [i, j] : v)
	{
		if (g[i][j] == 0)
			break;
		vis[i][j] = 1;
		for (auto [x, y] : d)
			if (vis[i + x][j + y])
			{
				int f = find(id(i + x, j + y));
				if (f == id(i, j))
					continue;
				E[id(i, j)].emplace_back(f);
				dsu[f] = id(i, j);
			}
	}
	
	for (int i = 1; i <= n * n; i++)
		if (dsu[i] == i)
			dfs(i);
	io[0] = pii(-1, 1e9);

	for (int p = 0; p + 1 <= 20; p++)
		for (int i = 1; i <= n * n; i++)
			pre[i][p + 1] = pre[pre[i][p]][p];

	
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int u = id(x1, y1), v = id(x2, y2);
		int r = val[lca(u, v)];
		cout << max(0, 2 * r - 1) << '\n';
	}
}

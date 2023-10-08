#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, Q, K, t, ans[100005], pre[100005], C[100005], dep[100005], head[100005], sz[100005], tableE[200005][20], bit[200005];
pii io[100005], tableD[100005][20];
vector<int> E[100005], euler = {-1};
vector<pii> qu[100005];
vector<pii> chain[100005];

void modify(int pos, int val)
{
	if(pos == 0)
		return;
	for (int i = pos; i <= M; i += (i & -i))
		bit[i] += val;
}

int query(int pos)
{
	int val = 0;
	for (int i = pos; i > 0; i -= (i & -i))
		val += bit[i];
	return val;
}


void dfs(int u)
{
	euler.emplace_back(u);
	io[u].F = ++t;
	for (auto v : E[u])
		if(v != pre[u])
		{
			pre[v] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
			sz[u] += sz[v];
			++t;
			euler.emplace_back(u);
		}
	sz[u]++;
	io[u].S = t;
}

void hld(int u, int r)
{
	head[u] = r;
	int mxz = 0, mi = 0;
	for (auto v : E[u])
		if(v != pre[u])
			if(sz[v] > mxz)
				mi = v, mxz = sz[v];
	for (auto v : E[u])
		if(v != pre[u])
			hld(v, (v == mi ? r : v));
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M >> Q;
	E[0].emplace_back(1);
	for (int i = 1; i < N; i++)
	{
		int u, v;
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	for (int i = 1; i <= M; i++)
		cin >> C[i];
	pre[0] = -1;
	dfs(0);
	hld(0, 0);
	K = euler.size() - 1;
	for (int i = 1; i <= K; i++)
		tableE[i][0] = dep[euler[i]];
	for (int p = 0; p + 1 < 20; p++)
		for (int i = 1; i + (1 << p) <= K; i++)
			tableE[i][p + 1] = min(tableE[i][p], tableE[i + (1 << p)][p]);
	for (int i = 1; i <= M; i++)
		tableD[i][0] = io[C[i]];
	for (int p = 0; p + 1 < 20; p++)
		for (int i = 1; i + (1 << p) <= M; i++)
			tableD[i][p + 1].F = min(tableD[i][p].F, tableD[i + (1 << p)][p].F),
			tableD[i][p + 1].S = max(tableD[i][p].S, tableD[i + (1 << p)][p].S);
	for (int i = 1; i <= Q; i++)
	{
		int L, R;
		cin >> L >> R;
		qu[R].emplace_back(pii(L, i));
	}
	for (int r = 1; r <= M; r++)
	{
		int u = C[r], h;
		while (u != -1)
		{
			h = head[u];
			while (!chain[h].empty() && dep[chain[h].back().F] <= dep[u])
			{
				auto [v, j] = chain[h].back();
				int val = dep[v] - dep[h] + 1;
				modify(j, -val);
				chain[h].pop_back();
				if (!chain[h].empty())
				{
					j = chain[h].back().S;
					modify(j, val);
				}			
			}
			int val = dep[u] - dep[h] + 1;
			modify(r, val);
			if (!chain[h].empty())
			{
				int j = chain[h].back().S;
				modify(j, -val);
			}
			chain[h].emplace_back(pii(u, r));
			u = pre[h];
		}
		for (auto [l, idx] : qu[r])
		{
			int lg = __lg(r - l + 1);
			pii iot = pii(min(tableD[l][lg].F, tableD[r - (1 << lg) + 1][lg].F),
						  max(tableD[l][lg].S, tableD[r - (1 << lg) + 1][lg].S));
			lg = __lg(iot.S - iot.F + 1);
			int lca = min(tableE[iot.F][lg], tableE[iot.S - (1 << lg) + 1][lg]);
			ans[idx] = query(r) - query(l - 1) - lca;
		}
	}
	for (int i = 1; i <= Q; i++)
		cout << ans[i] << '\n';

}

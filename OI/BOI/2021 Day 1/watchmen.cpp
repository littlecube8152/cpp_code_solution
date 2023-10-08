#include <bits/stdc++.h>
#define ll long long
#define state tuple<int, int, int>
#define F first
#define S second
using namespace std;

int N, M, K, L, l[2500005], r[2500005], nxt[2500005], mp[2000];
ll cnt = 0;
vector<int> v[2000];
vector<ll> dis[2500005];
vector<bitset<128>> vis[2500005];
vector<int> E[2500005];
vector<state> pq[1000006];

bool good(int u, ll t)
{
	return l[u] == 1 || t % l[u] != r[u];
}

bool goodmove(int u, int v, ll t)
{
	if (u == nxt[v])
		return good(u, t) && good(v, t);
	else
		return good(v, t);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	for (int i = 1; i <= N; i++)
		l[i] = 1;
	cin >> K;
	for (int i = 1; i <= K; i++)
	{
		int k;
		cin >> k;
		if (mp[k] == 0)
			mp[k] = ++L;
		v[i].resize(k);
		for (int j = 0; j < k; j++)
		{
			cin >> v[i][j];
			l[v[i][j]] = k;
			r[v[i][j]] = j;
			vis[v[i][j]].resize(k);
		}
		for (int j = 0; j < k; j++)
			nxt[v[i][j]] = v[i][(j + 1) % k];
	}
	assert(L < 80);
	for (int i = 1; i <= N; i++)
		dis[i].resize(l[i], (ll)1e18);
	dis[1][0] = 0;

	pq[0].emplace_back(state{1, 0, 0});

	auto cycle = [&](int d, int u, int b)
	{
		cnt++;
		// u -> b
		assert(cnt <= 2 * 350 * 350 * max(20, L));
		int rem = (d + 1) % l[b];
		if (vis[b][rem][mp[l[u]]])
			return;
		if (goodmove(u, b, d + 1))
			if (dis[b][rem] > d + 1)
			{
				dis[b][rem] = d + 1;
				pq[d + 1].emplace_back(state{b, rem, 0});
			}

		vis[b][rem][mp[l[u]]] = 1;

		if (d + l[u] <= 4 * N)
			pq[d + l[u]].emplace_back(state{u, 0, b});
	};

	auto normal = [&](int d, int u, int k)
	{
		for (auto v : E[u])
			if (l[v] == 1 && d + 1 < dis[v][0])
			{
				dis[v][0] = d + 1;
				pq[d + 1].emplace_back(state{v, 0, 0});
			}
			else if (l[v] > 1)
			{
				if (!goodmove(u, v, d + 1) && l[u] % l[v] == 0)
					continue;
				cycle(d, u, v);
			}

		int rem = (d + 1) % l[u];
		if (good(u, d + 1) && dis[u][rem] > d + 1)
		{
			dis[u][rem] = d + 1;
			pq[d + 1].emplace_back(state{u, rem, 0});
		}
	};

	for (int d = 0; d <= 4 * N; d++)
		for (auto [u, k, b] : pq[d])
		{
			if (!b && d > dis[u][k])
				continue;
			if (!b)
				normal(d, u, k);
			else
				cycle(d, u, b);
		}
	// for (int i = 1; i <= N; i++)
	// {
	// 	cout << i << ":";
	// 	for (auto j : dis[i])
	// 		cout << ' ' << j;
	// 	cout << '\n';
	// }
	cerr << "update counter " << cnt << '\n';
	if (dis[N][0] >= 1e18)
		cout << "impossible\n";
	else
	{
		assert(dis[N][0] <= N * 5);
		cout << dis[N][0] << '\n';
	}
}

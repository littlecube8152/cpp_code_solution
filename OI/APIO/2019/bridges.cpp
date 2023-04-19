#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

namespace
{

	const int B = 1200;
	int N, M, Q, u[100005], v[100005], d[100005], nd[100005], ans[100005], dsu[50005], rk[50005], vis[100005];
	vector<pii> ops;

	int find(int k)
	{
		return k == dsu[k] ? k : find(dsu[k]);
	}

	void merge(int x, int y)
	{
		x = find(x), y = find(y);
		if (x == y)
			return;
		if (rk[x] < rk[y])
			merge(y, x);
		else
		{
			dsu[y] = x;
			rk[x] += rk[y];
			ops.emplace_back(pii(x, y));
		}
	}

	void undo(int t)
	{
		while ((int)ops.size() > t)
		{
			auto [x, y] = ops.back();
			ops.pop_back();
			dsu[y] = y, rk[x] -= rk[y];
		}
	}

	void init()
	{
		ops.clear();
		ops.reserve(6 * M);
		for (int i = 1; i <= N; i++)
			dsu[i] = i, rk[i] = 1;
	}

	void mangorz()
	{
		ios::sync_with_stdio(0);
		cin.tie(0), cout.tie(0);
		cin >> N >> M;
		for (int i = 1; i <= M; i++)
			cin >> u[i] >> v[i] >> d[i];
		cin >> Q;
		for (int i = 1; i <= Q; i += B)
		{

			init();
			for (int j = 1; j <= M; j++)
				vis[j] = 0;
			// solve Q = [i, i + B - 1]
			vector<tuple<int, int, int>> change;
			vector<int> out;
			// d, i, 0: addedge
			// d, i, q: query i (ans[q])
			vector<tuple<int, int, int>> event;
			event.reserve(M + B);
			for (int j = i; j <= min(Q, i + B - 1); j++)
			{
				int t, a, b;
				cin >> t >> a >> b;
				if (t == 1)
				{
					change.emplace_back(make_tuple(j, a, b));
					vis[a] = 1;
				}
				else
					event.emplace_back(make_tuple(-b, j, a));
			}
			for (int j = 1; j <= M; j++)
				if (!vis[j])
					event.emplace_back(make_tuple(-d[j], 0, j));
				else
				{
					change.emplace_back(make_tuple(i - 1, j, d[j]));
					out.emplace_back(j);
				}
			sort(event.begin(), event.end());
			sort(change.begin(), change.end());
			for (auto [d, q, j] : event)
			{
				// cerr << "event " << d << ' ' << t << ' ' << j << ' ' << q << '\n';

				if (q == 0)
				{
					// cerr << "include " << j << '\n';
					merge(u[j], v[j]);
				}
				else
				{
					int T = ops.size();
					for (auto [tt, k, dd] : change)
						if (tt <= q)
							nd[k] = dd;
						else
							break;
					for (auto k : out)
						if (nd[k] >= -d)
						{
							// cerr << "tmp include " << k << '\n';
							merge(u[k], v[k]);
						}
					ans[q] = rk[find(j)];
					undo(T);
				}
			}
			for (auto [t, j, dd] : change)
				d[j] = dd;
		}
		for (int i = 1; i <= Q; i++)
		{
			if (ans[i] > 0)
				cout << ans[i] << '\n';
		}
	}
}

signed main()
{
	mangorz();
}
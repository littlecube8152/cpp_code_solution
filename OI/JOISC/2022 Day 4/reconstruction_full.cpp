#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, Q, dsu[505], rk[505];
pll bit[100005];
pair<pii, ll> E[100005];
vector<int> w = {0};

pll operator+(pll p1, pll p2)
{
	return pll(p1.F + p2.F, p1.S + p2.S);
}

void modify(int pos, pll val)
{
	for (int i = pos; i <= M; i += (i & -i))
		bit[i] = bit[i] + val;
}

pll query(int pos)
{
	pll ans = pll(0, 0);
	for (int i = pos; i > 0; i -= (i & -i))
		ans = ans + bit[i];
	return ans;
}

inline int find(int k)
{
	return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
}

bool merge(int u, int v)
{
	int ru = find(u), rv = find(v);
	if (ru == rv)
		return 0;
	if (rk[ru] < rk[rv])
		swap(ru, rv);
	dsu[rv] = ru;
	rk[ru] += rk[rv];
	return 1;
}

auto wsort = [](pair<pii, ll> p1, pair<pii, ll> p2)
{ return p1.S < p2.S; };

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<tuple<ll, int, ll>> event;

	cin >> N >> M;
	for (int i = 1; i <= M; i++)
		cin >> E[i].F.F >> E[i].F.S >> E[i].S;
	sort(E + 1, E + 1 + M, wsort);
	E[0].S = -1e9, E[M + 1].S = 2e9;
	for (int i = 1; i <= M; i++)
	{
		w.emplace_back(E[i].S);
		for (int j = 1; j <= N; j++)
			dsu[j] = j, rk[j] = 1;
		int l = i - 1, r = i + 1;
		for (; l >= 1; l--)
		{
			merge(E[l].F.F, E[l].F.S);
			if (find(E[i].F.F) == find(E[i].F.S))
				break;
		}

		for (int j = 1; j <= N; j++)
			dsu[j] = j, rk[j] = 1;
		for (; r <= M; r++)
		{
			merge(E[r].F.F, E[r].F.S);
			if (find(E[i].F.F) == find(E[i].F.S))
				break;
		}
		event.emplace_back(make_tuple(E[i].S + E[l].S, 1, E[i].S));
 		event.emplace_back(make_tuple(E[i].S + E[r].S, 0, E[i].S));
	}

	cin >> Q;
	for (int i = 1; i <= Q; i++)
	{
		int q;
		cin >> q;
		event.emplace_back(make_tuple(q + q, 2, q));
	}
	sort(event.begin(), event.end());
	sort(w.begin(), w.end());
	w.resize(unique(w.begin(), w.end()) - w.begin());
	pll sum = pll(0, 0);
	for (auto [x, t, ww] : event)
	{
		// cerr << x << ' ' << t << ' ' << ww << '\n';
		if (t == 0)
		{
			sum = sum + pll(-1, -ww);
			modify(lower_bound(w.begin(), w.end(), ww) - w.begin(), pll(-1, -ww));
		}
		else if (t == 1)
		{
			sum = sum + pll(1, ww);
			modify(lower_bound(w.begin(), w.end(), ww) - w.begin(), pll(1, ww));
		}
		else 
		{
			pll L = query(upper_bound(w.begin(), w.end(), ww) - w.begin() - 1), R = pll(sum.F - L.F, sum.S - L.S);
			cout << ww * L.F - L.S + R.S - ww * R.F << '\n';
		}
	}
}

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

#define N 505

struct KM
{
	const ll INF = (ll)1e9;

	ll w[N][N], hl[N], hr[N], slk[N];
	int fl[N], fr[N], pre[N], qu[N], ql, qr, n;
	bool vl[N], vr[N];
	void init(int _n)
	{
		n = _n;
		for (int i = 0; i < n; i++)
			fill(w[i], w[i] + n, -INF);
	}

	void add_edge(int a, int b, ll ww)
	{
		w[a][b] = ww;
	}

	bool check(int x)
	{
		if(vl[x] = 1, ~fl[x])
			return vr[qu[qr++] = fl[x]] = 1;
		while (~x)
			swap(x, fr[fl[x] = pre[x]]);
		return 0;
	}
	void bfs(int s)
	{
		fill(slk, slk + n, INF);
		fill(vl, vl + n, 0);
		fill(vr, vr + n, 0);
		ql = qr = 0;
		qu[qr++] = s;
		vr[s] = 1;
		for (ll d;;)
		{
			while(ql < qr)
				for (int x = 0, y = qu[ql++]; x < n; x++)
					if(!vl[x] && slk[x] >= (d = hl[x] + hr[y] - w[x][y]))
					{	
						if (pre[x] = y, d) slk[x] = d;
						else if(!check(x)) return;
			
					}
			d = INF;
			for (int x = 0; x < n; ++x)
				if (!vl[x] && d > slk[x]) d = slk[x];
			for (int x = 0; x < n; x++)
			{	
				if (vl[x]) hl[x] += d;
				else slk[x] -= d;
			   	if (vr[x]) hr[x] -= d;
			}
			for (int x = 0; x < n; x++)
				if(!vl[x] && !slk[x] && !check(x)) return;	
		}
	}

	ll solve()
	{
		fill(fl, fl + n, -1);
		fill(fr, fr + n, -1);
		fill(hr, hr + n, 0);
		for (int i = 0; i < n; i++)
			hl[i] = *max_element(w[i], w[i] + n);
		for (int i = 0; i < n; i++)
			bfs(i);
		ll res = 0;
		for (int i = 0; i < n; i++)
			res += w[i][fl[i]];
		return res;
	}
} km;

#undef N

int N, M, adj[505][505];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N;
	M = (N + 1) / 2;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> adj[i][j];
	km.init(M);
	for (int i = 1; i <= N; i += 2)
		for (int j = 1; j <= N; j += 2)
			km.add_edge(i / 2, j / 2, -(adj[i][j + 1] + adj[i][j - 1]));
	cout << -km.solve() << '\n';
}

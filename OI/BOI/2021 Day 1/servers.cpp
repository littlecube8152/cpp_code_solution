#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define piii tuple<int, int, int>
#define F first
#define S second
using namespace std;

int N, K, pre[120005][20], vis[120005], sz[120005], head[120005][20], ts;
pii io[120005], bin[120005][20], e[120005];
piii Q[120005];
vector<piii> update[120005];
vector<pii> E[120005];

struct BIT
{
	vector<int> bit;
	vector<int> vals;
	int id(int i, int p = 0)
	{
		return max(0, (int)(lower_bound(vals.begin(), vals.end(), i, greater<>()) - vals.begin()) + p);
	}
	void init(vector<int> val)
	{
		val.emplace_back(N + 8);
		val.emplace_back(N);
		val.emplace_back(-7);
		val.emplace_back(-8);
		sort(val.begin(), val.end(), greater<>());
		vals = val;
		bit.resize(vals.size(), 0);
	}
	int query(int k, int p)
	{
		int ans = 0;
		for (int i = id(k, p); i; i -= (i & -i))
			ans += bit[i];
		return ans;
	}
	void modify(int k)
	{
		for (int i = id(k); i < (int)bit.size(); i += (i & -i))
			bit[i]++;
	}
} bit[120005];

void calcsz(int u)
{
	vis[u] = sz[u] = 1;
	for (auto [v, w] : E[u])
		if (!vis[v])
		{
			calcsz(v);
			sz[u] += sz[v];
		}
	vis[u] = 0;
}

void init(int u, int p, int t, int c, int l)
{
	head[u][l] = c;
	if (p < N)
		update[p].emplace_back(piii(c, l, t));
	vis[u] = 1;
	for (auto [v, w] : E[u])
		if (!vis[v])
			init(v, (p < w ? w : N), t, c, l);
	vis[u] = 0;
}

void cdec(int r, int l)
{
	int c = r;
	calcsz(r);
	{
		int u = r;
		do
		{
			c = u;
			for (auto [v, _] : E[u])
				if (sz[u] > sz[v] && sz[v] > sz[r] / 2)
				{
					u = v;
					break;
				}
		} while (u != c);
	}
	vector<int> v;
	head[c][l] = c;
	vis[c] = 1;
	for (auto [u, w] : E[c])
		if (!vis[u])
		{
			v.emplace_back(w);
			init(u, w, w, c, l);
		}
	bit[c].init(v);
	bit[c].modify(N);
	for (auto [u, w] : E[c])
		if (!vis[u])
			cdec(u, l + 1);
}

const pii no = {-8, -8},
		  bad = {-2, -2};
pii merge(pii p, pii q)
{
	if (p == no)
		return q;
	if (q == no)
		return p;
	if (p == bad || q == bad)
		return bad;
	if (p.F <= p.S && p.S <= q.F && q.F <= q.S)
		return pii(p.F, q.S);
	if (p.F >= p.S && p.S >= q.F && q.F >= q.S)
		return pii(p.F, q.S);
	return bad;
}

void dfs(int u)
{
	io[u].F = ++ts;
	for (auto [v, w] : E[u])
		if (v != pre[u][0])
		{
			pre[v][0] = u;
			bin[v][0] = pii(w, w);
			for (int p = 0; p + 1 < 20; p++)
				pre[v][p + 1] = pre[pre[v][p]][p],
						   bin[v][p + 1] = merge(bin[v][p], bin[pre[v][p]][p]);
			dfs(v);
		}
	io[u].S = ts;
}

bool ischild(int r, int c)
{
	return io[r].F <= io[c].F && io[c].S <= io[r].S;
}

pii getpath(int u, int v)
{
	pii l = no, r = no;

	for (int p = 19; p >= 0; p--)
		if (!ischild(pre[u][p], v))
			l = merge(l, bin[u][p]), u = pre[u][p];
	if (!ischild(u, v))
		l = merge(l, bin[u][0]), u = pre[u][0];

	for (int p = 19; p >= 0; p--)
		if (!ischild(pre[v][p], u))
			r = merge(r, bin[v][p]), v = pre[v][p];
	if (!ischild(v, u))
		r = merge(r, bin[v][0]), v = pre[v][0];

	swap(r.F, r.S);

	return merge(l, r);
}

signed main()
{
	cin >> N >> K;
	for (int i = 0, j = 0; i + j < K + N - 1;)
	{
		char c;
		int a, b = 0;
		cin >> c >> a;
		if (c != 'C')
			cin >> b;

		if (c == 'S')
		{
			j++;
			e[j] = pii(a, b);
			E[a].emplace_back(pii(b, j));
			E[b].emplace_back(pii(a, j));
		}
		else
		{
			i++;
			Q[i] = piii(j, a, b);
		}
	}
	for (int p = 0; p < 20; p++)
		pre[1][p] = 1, bin[1][p] = no;
	dfs(1);
	cdec(1, 1);
	for (int i = 1, j = 0; i <= K; i++)
	{
		auto [t, a, b] = Q[i];
		while (j < t)
		{
			j++;
			for (auto [c, l, w] : update[j])
			{
				// cerr << "update " << j << ' ' << c << ' ' << w << '\n';
				bit[c].modify(w);
			}
		}
		if (b > 0)
		{
			int u = a, v = b;
			pii l = no, r = no;

			// cerr << merge(l, r).F << ' ' << merge(l, r).S << '\n';
			l = merge(merge(pii(t, t), getpath(a, b)), pii(0, 0));
			cout << (l != bad ? "yes\n" : "no\n");
		}
		else
		{
			int ans = 0;
			for (int p = 1; head[a][p]; p++)
			{
				int c = head[a][p];
				pii path = getpath(a, c);
				// cerr << a << ' ' << c << ' ' << path.F << ' ' << path.S << '\n';
				if (path == bad || path.F > path.S || path.S > t)
					continue;
				int k = path.S;
				// cerr << '+' << bit[c].query(k, -1) << '\n';
				ans += bit[c].query(k, -1);
			}
			cout << ans << '\n';
		}
	}
}

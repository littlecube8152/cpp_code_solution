#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll n, a[2000006], ans[1000006], l[2000006], r[2000006], root, over[2000006], sum[2000006];
vector<int> child[2000006];

bool pre(int i)
{
	if (1 <= i && i <= 2 * n && child[i].empty())
		sum[i] = a[i];

	for (int j : child[i])
	{
		over[i] |= pre(j);
		sum[i] += sum[j];
	}

	if (i == 0 || i == 2 * n + 2)
		over[i] = 1;
	return over[i];
}

ll wall(int i)
{
	if (i % 2 == 0)
		return 0;
	else
		return a[i];
}

pll merge(pll p, ll k)
{
	if (k > 0)
		p.S += k;
	else if (k < 0)
	{
		if (p.S + k <= 0)
			p = pll(p.F + p.S + k, 0);
		else
			p = pll(p.F, p.S + k);
	}
	return p;
}


pll zero = pll(0, 0);


void dfs(int i, pll &pre)
{
	if (child[i].empty())
	{
		pll cur = merge(merge(pll(0, a[i]), pre.F), pre.S);
		ans[i / 2] = -cur.F;
	}
	else
	{
		for (int j = 0; j <= 1; j++)
			if (!over[child[i][j]])
			{
				pll cur = merge(merge(pll(0, sum[child[i][j ^ 1]]), pre.F), pre.S);
				cur = merge(merge(pll(-max(0LL, wall(i) - wall(child[i][j])), 0), cur.F), cur.S);
				dfs(child[i][j], cur);
			}
			else
				dfs(child[i][j], zero);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[2 * i];
	for (int i = 0; i <= n; i++)
		cin >> a[2 * i + 1];
	vector<pll> v;
	a[0] = a[2 * n + 2] = 1e12;
	for (int i = 1; i <= 2 * n + 2; i++)
	{
		if (i & 1)
		{
			while (!v.empty() && v.back().F < a[i])
				v.pop_back();
			if (!v.empty())
				l[i] = v.back().S;
			v.push_back(pii(a[i], i));
		}
		else
			l[i] = v.back().S;
	}
	v.clear();
	for (int i = 2 * n + 1; i >= 0; i--)
	{
		if (i & 1)
		{
			while (!v.empty() && v.back().F <= a[i])
				v.pop_back();
			if (!v.empty())
				r[i] = v.back().S;
			v.push_back(pii(a[i], i));
		}
		else
			r[i] = v.back().S;
	}
	for (int i = 0; i <= 2 * n + 2; i++)
	{
		if (l[i] == 0 && r[i] == 0)
			root = i;
		else if (a[l[i]] < a[r[i]])
			child[l[i]].emplace_back(i);
		else
			child[r[i]].emplace_back(i);
	}
	pre(root);
	dfs(root, zero);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i == n];
}

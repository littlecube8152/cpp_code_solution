#include "wiring.h"
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

ll cost(ll x, ll y)
{
	return abs(x - y);
}

vector<ll> trans(vector<ll> l, vector<ll> ldp, vector<ll> r)
{
	// cerr << ' ';
	// for (ll i : l)
	// 	cerr << i << ' ';
	// cerr << "->";
	// for (ll i : r)
	// 	cerr << ' ' << i;
	// cerr << '\n';

	// for (ll i : ldp)
	// 	cerr << i << ' ';
	// cerr << '\n';

	int n = l.size(), m = r.size();
	ll small = r[0], large = l.back();
	vector<ll> rdp(m + 1, 1e18);
	reverse(ldp.begin(), ldp.end());
	reverse(l.begin(), l.end());
	l.insert(l.begin(), 0);
	r.insert(r.begin(), 0);
	{
		ll sum = 0;
		for (auto &i : l)
			i = (sum += i);
	}
	{
		ll sum = 0;
		for (auto &i : r)
			i = (sum += i);
	}
	{
		vector<ll> tmp(max(m, n) + 1, 1e18);
		for (int i = 0; i <= n; i++)
			tmp[i] = -l[i] + large * i + ldp[i];
		ll pref = 1e18;
		for (int j = 0; j <= m; j++)
		{
			pref = min(pref, tmp[j]);
			rdp[j] = min(rdp[j], r[j] - large * j + pref);
		}
	}
	{
		vector<ll> tmp(max(m, n) + 1, 1e18);
		for (int i = 0; i <= n; i++)
			tmp[i] = small * i - l[i] + ldp[i];
		ll suf = 1e18;
		for (int j = n; j > m; j--)
			suf = min(suf, tmp[j]);
		for (int j = m; j >= 0; j--)
		{
			suf = min(suf, tmp[j]);
			rdp[j] = min(rdp[j], r[j] - small * j + suf);
		}
	}
	// for (ll i : rdp)
	// 	cerr << i << ' ';
	// cerr << '\n';
	return rdp;
}

long long min_total_length(vector<int> r, vector<int> b)
{
	if (r[0] > b[0])
		r.swap(b);
	vector<pii> l;
	for (auto i : r)
		l.emplace_back(pii(i, 1));
	for (auto i : b)
		l.emplace_back(pii(i, 2));
	sort(l.begin(), l.end());
	vector<ll> pre, pdp;
	pdp.emplace_back(0);
	int last = 1, i = 0;
	while (i < l.size() && l[i].S == last)
	{
		pre.emplace_back(l[i].F);
		pdp.emplace_back(1e18);
		i++;
	}
	while (i < l.size())
	{
		last ^= 3;
		vector<ll> cur;
		while (i < l.size() && l[i].S == last)
		{
			cur.emplace_back(l[i].F);
			i++;
		}
		pdp = trans(pre, pdp, cur);
		pre = cur;
	}
	return pdp.back();
}

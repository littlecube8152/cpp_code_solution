#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pdd pair<long double, long double>
#define F first
#define S second
using namespace std;

#define sz(x) int(x.size())
pdd operator-(pdd p, pdd q)
{
	return pdd(p.F - q.F, p.S - q.S);
}
int sign(long double x)
{
	return (abs(x) < 1e-10 ? 0 : (x < 0 ? -1 : 1));
}
long double cross(pdd a, pdd b)
{
	return a.F * b.S - a.S * b.F;
}
int ori(pdd a, pdd b, pdd c)
{
	return sign(cross(b - a, c - a));
}

vector<pdd> hull(vector<pdd> dots)
{
	sort(dots.begin(), dots.end());
	vector<pdd> ans(1, dots[0]);
	for (int ct = 0; ct < 2; ++ct, reverse(dots.begin(), dots.end()))
		for (int i = 1, t = sz(ans); i < sz(dots); ans.emplace_back(dots[i++]))
			while(sz(ans) > t && ori(ans.end()[-2], ans.back(), dots[i]) <= 0)
				ans.pop_back();
	return ans;
}
long double dis(pdd a, pdd b)
{
	return sqrtl((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}

int n;
string s;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> s;
	int l = n + 1, r = -1;
	for (int i = 0; i < n; i++)
		if (s[i] == 'C')
			l = min(i, l), r = max(i, r);
	vector<pdd> v;
	for (int i = 0; i < n; i++)
		if (s[i] == 'S')
		{
			v.emplace_back(pdd(i, 0));
			v.emplace_back(pdd(i, 1));
			v.emplace_back(pdd(i + 1, 0));
			v.emplace_back(pdd(i + 1, 1));
		}
		else if (s[i] == 'T')
		{
			v.emplace_back(pdd(i, 0));
			v.emplace_back(pdd(i + 1, 0));
			v.emplace_back(pdd(i + 0.5, sqrt(3) / 2.0));
		}
		else if (s[i] == 'C' && (i == l || i == r))
		{
			const int C = 50000;
			const double pi = acos(-1);
			for (int j = 0; j < C; j++)
				v.emplace_back(pdd(i + 0.5 + 0.5 * cos(2.0 * pi / double(C) * j), 0.5 + 0.5 * sin(2.0 * pi / double(C) * j)));
		}
	v = hull(v);
	long double ans = 0;
	for (int i = 0; i < sz(v); i++)
	{
		ans += dis(v[i], v[(i + 1) % sz(v)]);
	}
	cout << fixed << setprecision(10) << ans << '\n';
}

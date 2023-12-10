#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int n, w, h, s, t;
char opt;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> w >> h >> s;
	t = 1e9;
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		int mx = 0;
		for (int j = 1; j <= h; j++)
		{
			string s;
			int cnt = 0;
			cin >> s;
			s = "." + s + ".";
			for (int k = 0; k <= w; k++)
				cnt += s[k] != s[k + 1];
			mx = max(mx, cnt);
		}
		int ops = (s - 1) / mx + 1;
		if (ops < t)
			opt = c, t = ops;
	}
	cout << string(t, opt) << '\n';
}

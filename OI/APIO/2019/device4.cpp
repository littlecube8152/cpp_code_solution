#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, A, B;
map<ll, int> mp;

ll safe_mul(ll a, ll b)
{
	if(b >= 2e18 / a)
		return 2e18;
	return a * b;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> A >> B;
	ll g = __gcd(A, B + 1);
	A /= g;
	A = safe_mul(A, B);
	for (int i = 1; i <= N; i++)
	{
		ll l, r;
		cin >> l >> r;
		if(r - l + 1 >= A)
		{
			cout << A << '\n';
			return 0;
		}
		l %= A, r %= A;
		if(r < l)
		{
			mp[l]++;
			mp[A]--;
			mp[0]++;
			mp[r + 1]--;
		}
		else
		{
			mp[l]++;
			mp[r + 1]--;
		}
	}
	ll last = 0, cnt = 0, ans = 0;
	for (auto [p, v] : mp)
	{
		if(cnt > 0)
			ans += p - last;
		last = p;
		cnt += v;
	}
	cout << ans << '\n';
}

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll n, v, t[200005], a[200005];
vector<pll> p;
vector<ll> lis;

signed main()
{
	cin >> n >> v;
	for(int i = 1; i <= n; i++)
		cin >> t[i];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		p.emplace_back(pll(a[i] + t[i] * v,  t[i] * v - a[i]));
	sort(p.begin(), p.end(), greater<>());
	for(auto [x, y] : p)
	{
		if(x < 0)
			break;
		auto iter = upper_bound(lis.begin(), lis.end(), y, greater<>());
		if(iter == lis.end())
			lis.emplace_back(y);
		else lis[iter - lis.begin()] = y;
	}
	cout << upper_bound(lis.begin(), lis.end(), 0, greater<>()) - lis.begin() << '\n';
}

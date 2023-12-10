#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;


const ll C = 2e9;
int W, H, N;
vector<pll> v;

ll id(ll x, ll y)
{
	if (y == 0)
		return x;
	else if (x == W)
		return C + y;
	else if (y == H)
		return 3 * C - x;
	else if (x == 0) 
		return 5 * C - y;
	else 
		return -C;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> W >> H >> N;
	for (int i = 1; i <= N; i++)
	{
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll id1 = id(x1, y1), id2 = id(x2, y2);

		if(id1 >= 0 && id2 >= 0)
			v.emplace_back(pll(id1, i)),
			v.emplace_back(pll(id2, i));
	}
	sort(v.begin(), v.end());
	vector<int> s;
	for (auto [_, i] : v)
	{
		if(!s.empty() && s.back() == i)
			s.pop_back();
		else 
			s.emplace_back(i);
	}
	cout << (s.empty() ? "Y\n" : "N\n");
}

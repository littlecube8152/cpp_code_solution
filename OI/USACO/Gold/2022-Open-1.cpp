#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct query
{
	int x, y, q, n;
	bool operator<(query q1)
	{
		return make_tuple(x, -y, q, n) < make_tuple(q1.x, -q1.y, q1.q, q1.n);
	}	
};

int N, ans;
vector<query> v;
map<int, int> mp;

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		int q, t, x, n;
		cin >> q >> t >> x >> n;
		v.emplace_back(query{x + t, x - t, q, n});
	}
	sort(v.begin(), v.end());
	for(auto [x, y, q, n] : v)
	{
		if(q == 1)
			mp[y] += n;
		else
		{
			auto iter = mp.lower_bound(y);
			while(iter != mp.end())
			{
				if(iter->S >= n)
				{
					ans += n;
					iter->S -= n;
					break;
				}
				else
				{
					ans += iter->S;
					n -= iter->S;
					mp.erase(iter);
				}
				iter = mp.lower_bound(y);
			}
		}
	}
	cout << ans << '\n';
}

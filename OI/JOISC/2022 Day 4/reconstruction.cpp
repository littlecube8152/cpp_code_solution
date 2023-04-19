#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, Q, dsu[1005];

int find(int k)
{
	return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	vector<pair<int, pii>> v(M);
	for(int i = 0; i < M; i++)
		cin >> v[i].S.F >> v[i].S.S >> v[i].F;
	cin >> Q;
	for(int t = 1; t <= Q; t++)
	{
		int i;
		cin >> i;
		cout << "Query " << i << '\n';
		for(int i = 1; i <= N; i++)
			dsu[i] = i;
		sort(v.begin(), v.end(), [&](pair<int, pii> p1, pair<int, pii> p2){ return abs(p1.F - i) < abs(p2.F - i); });
		vector<pair<int, pii>> ans;
		for(auto [w, e] : v)
		{
			auto [u, v] = e;
			if(find(u) != find(v))
			{
				dsu[find(u)] = find(v);
				ans.emplace_back(make_pair(w, e));
			}
		}
		sort(ans.begin(), ans.end());
		for(auto [w, e] : ans)
			cout << "(" << e.F << ", " << e.S << ")-" << w << " ";
		cout << '\n';
	}
	
}

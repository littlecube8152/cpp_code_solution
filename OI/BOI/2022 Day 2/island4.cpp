#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, s[200005], vis[200005], ans[200005];
ll sum[200005];
vector<int> E[200005], val, cur;

ll dfs(int u, int &c)
{
	ll res = 1e18;
	cur.emplace_back(u);
	vis[u] = 1;
	sum[u] += s[u];
	for(int v : E[u])
		if(!vis[v] && s[v] <= c)
		{	
			res = min(res, dfs(v, c));
			sum[u] += sum[v];
		}
		else if(s[v] > c && ans[v] == 1)
			res = min(res, s[v]);
	return res;
}

signed main()
{
	cin >> N >> M;
		
	for(int i = 1; i <= N; i++)
	{	
		cin >> s[i];
		val.emplace_back(s[i]);
	}

	sort(val.begin(), val.end(), greater<int>());
	val.resize(unique(val.begin(), val.end()) - val.begin());

	for(int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		E[v].emplace_back(u);
		E[u].emplace_back(v);
	}	
	
	for(int k : val)
	{
		for(int i = 1; i <= N; i++)
			vis[i] = sum[i] = 0;
		if(k == val.front())
		{
			for(int i = 1; i <= N; i++)
				if(s[i] == k)
					ans[i] = 1;
		}
		else
		{
			for(int i = 1; i <= N; i++)
				if(s[i] == k && !vis[i])
				{
					cur.clear();
					// cout << "dfs " << i << " " << k << '\n';
					ll the = dfs(i, k);
					// for(int j : cur)
					// 	cout << j << " ";
					// cout << '\n';
					if(sum[i] >= the)
					{
						for(int j : cur)
							if(s[j] == k)
								ans[j] = 1;
					}
				}
		}
	}

	for(int i = 1; i <= N; i++)
		cout << ans[i];
	cout << '\n';
}

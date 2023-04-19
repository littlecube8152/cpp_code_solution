#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, Q, L, pre[200050], h[200055], mul[200055][41];
vector<int> E[200050];

void dfs(int u)
{
	for(int v : E[u])
		if(pre[u] != v)
		{
			pre[v] = u;
			dfs(v);
		}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> L;
	for(int i = 1; i <= N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	for(int i = 1; i <= 40; i++)
		E[N + i].emplace_back(N + i - 1);
	dfs(N + 40);
	for(int i = 1; i <= N; i++)
		cin >> h[i];
	for(int i = 1; i <= N + 40; i++)
		for(int j = 0; j <= 40; j++)
			mul[i][j] = 1;
	cin >> Q;
	while(Q--)
	{
		ll T, X, D, W;
		cin >> T;
		if(T == 1)
		{
			cin >> X >> D >> W;
			for(int i = D; i >= 0; i--)
			{
				mul[X][i] = mul[X][i] * W % L;
				if(i)
					mul[X][i - 1] = mul[X][i - 1] * W % L;
				X = pre[X];
			}
		}
		else
		{
			cin >> X;
			ll ans = h[X];
			for(int i = 0; i <= 40; i++)
			{
				ans = ans * mul[X][i] % L;
				X = pre[X];
			}
			cout << ans << '\n';
		}
	}

}

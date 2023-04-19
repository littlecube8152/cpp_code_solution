#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, K, p[250005], r[250005];
vector<int> dis[250005];
vector<int> E[250005];
vector<pii> dv[500005];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	for(int i = 1; i <= N; i++)
		dis[i].emplace_back((int)1e9);
	cin >> K;
	for(int i = 1; i <= K; i++)
	{
		int P, u;
		cin >> P;
		for(int j = 0; j < P; j++)
		{
			cin >> u;
			dis[u] = vector<int>(P, (int)1e9);
			p[u] = P, r[u] = j;
		}
	}
	dis[1][0] = 0;
	dv[0].emplace_back(pii(1, 0));
	for(int d = 0; d <= 2 * N; d++)
	{
		while(!dv[d].empty())
		{
			auto [u, s] = dv[d].back();
			dv[d].pop_back();
			if(dis[u][s] < d)
				continue;
			for(auto v : E[u])
			{
				if(!p[v])
					if(dis[v][0] > dis[u][s] + 1)
					{
						dis[v][0] = dis[u][s] + 1;
						dv[d + 1].emplace_back(pii(v, 0));
					}
				if(p[v] && !p[u])
				{
					

				}
					if(dis[v][tt <= 2] > dis[u][s] + 1)
					{
						dis[v][tt <= 2] = dis[u][s] + 1;
						dv[d + 1].emplace_back(pii(v, tt <= 2));
					}
				if(p[v] && !p[u] && t <= 1)
					if(dis[v][p[v] == 3] > dis[u][s] + 1 + t)
					{
						dis[v][p[v] == 3] = dis[u][s] + 1 + t;
						dv[d + 1 + t].emplace_back(pii(v, p[v] == 3));
					}
				if(p[v] && p
			}
		}
	}
	//for(int i = 1; i <= N; i++)
	//	cout << dis[i][0] << " " << dis[i][1] << '\n';
	if(dis[N][0] >= 1e9)
		cout << "impossible\n";
	else cout << dis[N][0];
}

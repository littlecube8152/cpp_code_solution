#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, s[2005], vis[2005];
vector<int> E[2005];


signed main()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		cin >> s[i];
	for(int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}	
	for(int i = 1; i <= N; i++)
	{
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		ll sum = 0, acc = 0;
		for(int i = 1; i <= N; i++)
			vis[i] = 0;
		vis[i] = 1;
		pq.push(pii(s[i], i));
		while(!pq.empty())
		{
			auto [d, u] = pq.top();
			pq.pop();
			if(sum >= d || u == i)
			{
				acc++;
				sum += d;
			}
			for(int v : E[u])
				if(!vis[v])
				{	
					vis[v] = 1;
					pq.push(pii(s[v], v));
				}
		}
		cout << (acc == N ? 1 : 0);
	}
	cout << '\n';
}

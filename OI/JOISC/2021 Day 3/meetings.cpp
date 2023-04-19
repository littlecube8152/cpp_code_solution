#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, ans[200005], sz[200005], dis[200005], vis[2000005], pre[200005];
vector<int> E[200005], cur;
pii res[200005][2];

void update(int i, pii p)
{
	if(p.S == res[i][0].S)
		res[i][0].F = max(res[i][0].F, p.F);
	else if(p.S == res[i][1].S)
		res[i][1].F = max(res[i][1].F, p.F);
	else if(p.F >= res[i][0].F)
	{
		res[i][1] = res[i][0];
		res[i][0] = p;
	}
	else if(p.F >= res[i][1].F)
		res[i][1] = p;
	if(res[i][0].F < res[i][1].F)
		swap(res[i][0], res[i][1]);
}

void dfs(int k, int r)
{
	cur.emplace_back(k);
	vis[k] = 1;
	sz[k] = 1;
	for(int i : E[k])
		if(!vis[i])
		{
			pre[i] = k;
			dis[i] = dis[k] + 1;
			dfs(i, r);
			sz[k] += sz[i];
		}
	vis[k] = 0;
	update(sz[k], {dis[k], r});
}

void cdec(int k)
{
	cur.clear();
	pre[k] = 0;
	dfs(k, k);
	int c = 0, ccnt = 0, M = sz[k];
	for(int i : cur)
	{
		bool valid = (M - sz[i] <= M / 2);
		for(int j : E[i])
			if(j != pre[i] && !vis[j])
				valid &= (sz[j] <= M / 2);
			
		if(valid)
			c = i, ccnt++;
	}
	if(ccnt == 2)
		ans[M] = max(2, ans[M]);

	assert(ccnt <= 2);

	cur.clear();
	for(int i = 1; i <= M / 2; i++)
		res[i][0] = res[i][1] = {0, c};

	vis[c] = 1;
	for(int i : E[c]) 
		if(!vis[i])
		{
			dis[i] = 1;
			dfs(i, i);
		}

	for(int i = M / 2; i >= 1; i--)
	{
		ans[i * 2] = max(ans[i * 2], res[i][0].F + res[i][1].F + 1);
		update(i - 1, res[i][0]);
		update(i - 1, res[i][1]);
	}

	for(int i : E[c])
		if(!vis[i])
			cdec(i);
}



signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N;
	for(int i = 1; i < N; i++)
	{
		int u, v;
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	cdec(1);
	for(int i = 1; i <= N; i++)
		cout << max(1, ans[i]) << '\n';
}

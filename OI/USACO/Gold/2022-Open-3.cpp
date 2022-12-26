#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int T, N, B, p[100005], l[100005], r[100005], ans[100005], pre[100005];
pii res[100005], range[100005];
vector<int> E[100005];

void dfs(int k, int C)
{
	range[k] = {0, 1e9};
	for(int i : E[k])
	   	if(i != p[k])
		{
			dfs(i, C);
			range[k].F = max(range[k].F, range[i].F), range[k].S = min(range[k].S, range[i].S);
			range[k].F = max(range[k].F, l[i] - C), range[k].S = min(range[k].S, r[i] + C);
		}
	res[k] = pii{max(range[k].F, l[k]), min(range[k].S, r[k])};
}


signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> T >> B;
	while(T--)
	{
		cin >> N;
		for(int i = 1; i <= N; i++)
			E[i].clear();
		for(int i = 2; i <= N; i++)
		{
			cin >> p[i];
			E[p[i]].emplace_back(i);
		}
		for(int i = 1; i <= N; i++)
			cin >> l[i] >> r[i];
		int L = 0, R = 1000'000'000;
		while(L < R)
		{
			int mid = (L + R) / 2;
			dfs(1, mid);
			bool valid = 1;
			for(int i = 1; i <= N; i++)
				if(res[i].F > res[i].S)
					valid = 0;
			if(valid)
				R = mid;
			else 
				L = mid + 1;
		}	
		cout << L << '\n';
		if(B)
		{
			dfs(1, L);
			pre[1] = 0;
			for(int i = 1; i <= N; i++)
			{
				pre[i] = max(res[p[i]].F - L, pre[p[i]]);
				cout << max(pre[i], res[i].F) << " \n"[i == N];	
			}	
	
		}
	}
}


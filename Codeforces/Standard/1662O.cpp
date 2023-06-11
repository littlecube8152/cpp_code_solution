#include <bits/stdc++.h>

using namespace std;

vector<int> E[10004];
bool vis[10004];
bool wl[30][360], wu[30][360];

int idx(int r, int t)
{
	return r * 360 + t;
}

bool dfs(int u)
{
	bool r = (u < 360);
	vis[u] = 1;
	for(int v : E[u])
		if(!vis[v])
			r |= dfs(v);
	return r;
}


void solve()
{
	for(int i = 0; i <= 10000; i++)
	{
		E[i].clear();
		vis[i] = 0;
	}
	for(int i = 0; i <= 20; i++)
		for(int j = 0; j < 360; j++)
			wl[i][j] = wu[i][j] = 0;
	int n;
	cin >> n;
	while(n--)
	{
		char c;
		int t1, t2, r1, r2;
		cin >> c;
		if(c == 'S')
		{
			cin >> r1 >> r2 >> t1;
			for(int i = r1; i < r2; i++)
				wl[i][t1] = 1;
		}
		else
		{
			cin >> r1 >> t1 >> t2;
			for(int i = t1; i != t2; i = (i + 1) % 360)
				wu[r1][i] = 1;
			
		}
	}
	for(int i = 1; i <= 20; i++)
		for(int j = 0; j < 360; j++)
			if(!wu[i][j])
			{
				E[idx(i, j)].emplace_back(idx(i - 1, j));
				E[idx(i - 1, j)].emplace_back(idx(i, j));
			}
	for(int i = 1; i <= 20; i++)
		for(int j = 0; j < 360; j++)
		{
			int k = (j + 1) % 360;
			if(!wl[i][k])
			{
				E[idx(i, j)].emplace_back(idx(i, k));
				E[idx(i, k)].emplace_back(idx(i, j));
			}	
		}	
	for(int j = 0; j < 360; j++)
		if(!vis[idx(20, j)] && dfs(idx(20, j)))
		{
			cout << "YES\n";
			return; 
		}
	cout << "NO\n";
}	

signed main()
{
	int t;
	cin >> t;
	while(t--)
		solve();	
}

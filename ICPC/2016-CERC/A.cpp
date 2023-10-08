#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

string s[200];
int n, m, ans, vis[200][200];
char w[200][200];

set<string> st;

void dfs(int i, int j, int ri, int rj)
{
	vis[i][j] = 1;
	w[i - ri][j - rj] = s[i][j];
	for (auto [dx, dy] : vector<pii>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
		if (!vis[i + dx][j + dy])
			dfs(i + dx, j + dy, ri, rj);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '#')
				vis[i][j] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!vis[i][j])
			{
				int old = st.size();	
				dfs(i, j, i, j);
				string t;
				int r = 0, c = 0;
				for (int x = 0; w[x][0]; r = ++x)
				{   
					for (int y = 0; w[x][y]; c = ++y)
						t.push_back(w[x][y]);
				 	t.push_back('|');	
				}
				st.insert(t);

				t = "";
				for (int y = c - 1; y >= 0; y--)
				{			
					for (int x = 0; x < r; x++)
						t.push_back(w[x][y]);
					t.push_back('|');
				}
				st.insert(t);
				
				t = "";
				for (int x = r - 1; x >= 0; x--)
				{			
					for (int y = c - 1; y >= 0; y--)
						t.push_back(w[x][y]);
					t.push_back('|');
				}
				st.insert(t);

				t = "";
				for (int y = 0; y < c; y++)
				{			
					for (int x = r - 1; x >= 0; x--)
						t.push_back(w[x][y]);
					t.push_back('|');
				}
				st.insert(t);
				
				if (old != st.size())
					ans++;
			}
	cout << ans << '\n';

}

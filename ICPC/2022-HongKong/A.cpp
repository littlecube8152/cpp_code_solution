#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;


vector<int> E[200005];

int dfs(int u)
{
	vector<int> ch;
	for (auto v : E[u])
		ch.emplace_back(dfs(v));
	if (ch.empty())
		return 1;
	sort(all(ch));
	ch.back()--;
	return *max_element(all(ch)) + 1;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T, N, p;
	cin >> T;
	while(T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
			E[i].clear();
		for (int i = 1; i <= N; i++)	
		{
			cin >> p;
			E[p].emplace_back(i);
		}
		cout << dfs(1) << '\n';
	}
}





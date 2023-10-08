#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, p[100005], pin[100005], q[100005], qin[100005], same[100005];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{	
		cin >> p[i];
		pin[p[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{	
		cin >> q[i];
		qin[q[i]] = i;
	}
	queue<int> qu;
	for (int i = 1; i <= n; i++)
		if (pin[i] == 0)
			qu.emplace(i);
	same[0] = 1;
	while(!qu.empty())
	{
		int i = qu.front();
		qu.pop();
		if (pin[i] == qin[i] && same[pin[i]])
			same[i] = 1;
		if (p[i])
			qu.emplace(p[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!same[i] && pin[i])
			ans++;
		if (!same[i] && qin[i])
			ans++;
	}
	cout << ans << '\n';
}

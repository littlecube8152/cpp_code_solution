#include <bits/stdc++.h>

using namespace std;



void solve()
{
	int n, m, mr = 0, mw = 0;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int r, w;
		cin >> r >> w;
		mr = max(mr, r);
		mw = max(mw, w);
	}
	if(mr + mw > n)
		cout << "IMPOSSIBLE\n";
	else
	{
		cout << string(mw, 'W') << string(n - mw, 'R') << '\n';
	} 
}

signed main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
}

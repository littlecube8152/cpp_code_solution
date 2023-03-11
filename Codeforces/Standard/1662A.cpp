#include <bits/stdc++.h>

using namespace std;



void solve()
{
	int n, diff[11] = {}, sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int b, d;
		cin >> b >> d;
		diff[d] = max(diff[d], b);
	}
	for(int i = 1; i <= 10; i++)
		if(diff[i] == 0)
		{
			cout << "MOREPROBLEMS\n";
			return;
		}
		else
			sum += diff[i];
	cout << sum << '\n';
}

signed main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
}

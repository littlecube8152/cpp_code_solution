#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int s;
	cin >> s;
	for (int i = 0; i <= s; i++)
		for (int j = 0; j <= s; j++)
			if (i * i + j * j == s)
			{
				cout << i << ' ' << j << '\n';
				cout << i - j << ' ' << j + i << '\n';
				cout << -j << ' ' << i << '\n';
				cout << 0 << ' ' << 0 << '\n';
				return 0;
			}
	cout << "Impossible\n";

}


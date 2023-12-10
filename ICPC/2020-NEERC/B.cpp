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

	int a, x, b, y, T;
	cin >> a >> x >> b >> y >> T;
	cout << a + 21 * max(0, T - 30) * x << ' ' << b + 21 * max(0, T - 45) * y << '\n';
}


#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

ll l, r, b, k;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> l >> r >> b >> k;
	cout << (l + b - 1) / b * b * k << '\n';

}





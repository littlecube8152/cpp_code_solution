#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int n, a[100005];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int d = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 0; i < n; i++)
		d = max(d, a[i + 1] - a[i]);
	bool valid = true;
	for (int i = 0; i + 2 <= n; i++)
		if (a[i] + d >= a[i + 2])
			valid = false;
	cout << (valid ? d : 0) << '\n';
}


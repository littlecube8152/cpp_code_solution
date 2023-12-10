#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int N, a[100005], ans = 1;


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + N);
	ans = max(ans, a[1] / 2);
	bool flag = 1;
	for (int i = 2; i <= N; i++)
		if (a[i] / 2 >= a[1] || a[i] == a[1]);
		else
			flag = 0;
	if (flag)
		ans = a[1];
	cout << ans << '\n';
}





#include <bits/stdc++.h>
#define int long long
#define ll long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int k;

int solve(int b, int c)
{
	int d = b * b - 4 * c;
	int sd = round(sqrt(d));
	if (sd * sd != d)
		return 0;
	int p = -b + sd;
	if (p % 2 != 0)
		return 0;
	return p / 2;
}

int find(int a, int b)
{
	return solve(-k * (a + b), a * a + b * b - k * a * b - 1);
}


signed main()
{
	_BitInt(256) a = 100;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> k;
	int a = 0, b = 1, c = k;
	for (int t = 0; t <= 5; t++)
	{
		if (find(b, c) > a)
			a = find(b, c);
		else if (find(a, c) > b)
			b = find(a, c);
		else if (find(a, b) > c)
			c = find(a, b);
		else assert(false);
		cout << a << ' ' << b << ' ' << c << '\n';
	}
}

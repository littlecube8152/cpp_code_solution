#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

void query(int x, int y)
{
	cout << x << ' ' << y << endl;
	string s;
	cin >> s;
	if (s[0] == 'W')
		exit(0);
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	for (int i = N; i >= 1; i--)
	{
		for (int j = N; j - 1 >= i; j--)
			query(j - 1, j);
		for (int j = i; j + 1 <= N; j++)
			query(j, j + 1);
		for (int j = 1; j + 1 <= i; j++)
			query(j, j + 1);
		for (int j = 1; j + 1 <= i; j++)
			query(j, j + 1);
		query(1, 2);
		query(1, 2);
		cerr << "owo\n";
	}
}

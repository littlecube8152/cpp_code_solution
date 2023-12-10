#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, nxt[5] = {2, 3, 4, 0, 0}, add[5] = {0, 0, 0, 2, 1}, ans = 60;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> s >> N;
	int w;
	if (s == "Mon")
		w = 0;
	if (s == "Tue")
		w = 1;
	if (s == "Wed")
		w = 2;
	if (s == "Thu")
		w = 3;
	if (s == "Fri")
		w = 4;
	if (s == "Sat")
		w = 5;
 	if (s == "Sun")
		w = 6;
	for (int i = 1; i <= N; i++)
	{
		int D;
		cin >> D;
		D = -D;
		int k = ((w + D) % 7 + 7) % 7;
		
		auto jump = [&]()
		{
			D += 30 + add[k];
			k = nxt[k];
		};

		if (D == 0)
			jump();

		if (D <= -300)
		{
			jump();
			jump();
			D %= 91;
		}
		while (D < 0)
			jump();
		ans = min(ans, D);
	}
	cout << ans << '\n';
}

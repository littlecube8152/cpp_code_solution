#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int N, M;
	cin >> N >> M;
	cout << N << ' ' << M << '\n';
	for(int i = 1; i <= N; i++)
		cout << rd() % 1000'000'000 + 1 << ' ' << rd() % 1000'000'000 + 1 << '\n';
}

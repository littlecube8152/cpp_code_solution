#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll square(ll n)
{
	return n * (n + 1) * (2 * n + 1) / 6;
}

ll linear(ll n)
{
	return n * (n + 1) / 2;
}

signed main()
{
	ll N, M;
	while(cin >> N >> M)
	{
		if(N == 0 && M == 0)
		{
			cout << '\n';
			return 0;
		}
		cout << M * N * (N - 1) + N * M * (M - 1) + 2 * (2 * square(min(N, M)) - 2 * linear(min(N, M)) + (abs(N - M) - 1) * min(N, M) * (min(N, M) - 1)) << '\n';
	}
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T, N;
bitset<900005> b[3][2];

signed main()
{
	cin >> T;
	while(T--)
	{
		cin >> N;
		int a, sum = 0, mi = 45000000;
		b[0][0] = 0;
		b[1][0] = 0;
		b[2][0] = 0;
		b[1][0][450000] = 1;
		for(int i = 1; i <= N; i++)
		{
			cin >> a;
			sum += a;
			b[0][i & 1] = b[1][(i & 1) ^ 1];
			b[1][i & 1] = (b[2][(i & 1) ^ 1]) | (b[0][(i & 1) ^ 1] >> a);
			b[2][i & 1] = b[1][(i & 1) ^ 1] >> a;
		}
		for(int i = (sum + 1) / 2; i <= 450000; i++)
			if(b[0][N & 1][450000 + i] || b[1][N & 1][450000 + i] || b[2][N & 1][450000 + i])
				mi = min(mi, i);
		cout << sum << " " << sum - mi << '\n';
	}
}

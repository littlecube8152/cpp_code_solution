#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int N, ans[2];
ll c[3005];
double P;


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> P;
	P -= 1e-10;
	for (int i = 1; i <= N; i++)
		cin >> c[i];
	for (int i = 1; i < N; i++)
	{	
		ll sum = 0;
		for (int j = i + 1; j <= N; j++)
		{	
			int K = j - i;
			sum += (c[j] - c[j - 1]) * (c[j] - c[j - 1]);
			if (K == 1) continue;
			ll A = c[j] - c[i];
			if (A)
			{
				ll D = sum * K - A * A; 
				double T = A / sqrt(D);
				if (T <= -P)
					ans[0]++;
				else if(T >= P)
					ans[1]++;
			}
		}
	}
	cout << ans[1] << ' ' << ans[0] << '\n';
}


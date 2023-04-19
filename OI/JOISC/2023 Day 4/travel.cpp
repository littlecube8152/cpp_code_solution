#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q;
ll X[200005];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> X[i];
	X[0] = -1e18;
	X[N + 1] = 1e18;
	cin >> Q;
	for (int i = 1; i <= Q; i++)
	{
		ll ans = 0, S, L, R, cur;
		cin >> S;
		cur = L = R = S;
		while(L > X[1] || R < X[N])
		{
			//cerr << L << ' ' << R << '\n';
			int ldx = lower_bound(X + 1, X + 1 + N, L) - X - 1,
				rdx = upper_bound(X + 1, X + 1 + N, R) - X;
			if(cur - X[ldx] <= X[rdx] - cur)
			{
				// keep jump left
				int fL = max(1, (int)(lower_bound(X + 1, X + 1 + N, cur - (X[rdx] - cur)) - X));
				if (fL != 1 && X[fL] - X[fL - 1] <= X[rdx] - X[fL])	
					fL--;
				ans += cur - X[fL];
				cur = L = X[fL]; 
			}
			else
			{
				// keep jump right
				int fR = min(N, (int)(upper_bound(X + 1, X + 1 + N, cur + (cur - X[ldx])) - X - 1));
				if(fR != N && X[fR + 1] - X[fR] < X[fR] - X[ldx])
					fR++;
				ans += X[fR] - cur;
				cur = R = X[fR];
			}
		}
		cout << ans << '\n';
	}	
}

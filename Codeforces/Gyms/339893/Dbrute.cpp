#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
using namespace std;

long long dp[1 << 18], wdp[1 << 18], N, ans[18];

signed main()
{
    cin >> N;
    N--;
    wdp[0] = 1;
    for (int i = 0; i < (1 << N); i++)
        for (int bit = 0; bit < N; bit++)
            if ((i & (1 << bit)) == 0)
            {
                int ubit = bit + 1, dbit = bit - 1;
                for (; ubit <= N; ubit++)
                    if (ubit == N)
                        break;
                    else if (i & (1 << ubit))
                        break;
                for (; dbit >= -1; dbit--)
                    if (dbit == -1)
                        break;
                    else if (i & (1 << dbit))
                        break;
                wdp[i | (1 << bit)] = (wdp[i | (1 << bit)] + wdp[i]) % MOD;
                dp[i | (1 << bit)] = (dp[i | (1 << bit)] + (dp[i] + (ubit - bit) * (bit - dbit) * wdp[i])) % MOD;
            }
    // for (int i = 0; i < (1 << N); i++)
    //  cout << i << ' ' << dp[i] << '\n';
    for (int i = 0; i < (1 << N); i++)
        ans[__builtin_popcount(i)] = (ans[__builtin_popcount(i)] + dp[i]) % MOD;
    for (int i = 0; i <= N; i++)
        cout << ans[i] << '\n';
}
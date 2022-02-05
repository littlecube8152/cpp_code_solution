#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

long long N, dp[1000][1000], arr[1000], ans = 10000000000000000, ansi = 0;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (long long i = max(0LL, (long long)cbrt(N ) - 1000000LL); i <= cbrt(N) + 1000000; i++)
    {
        long long size = 1 + i * (i + 1) / 2;
        if (i + (N + size - 1) / size < ans)
        {
            ans = min(ans, i + (N + size - 1) / size);
            ansi = i;
        }
    }
    cout << ans << '\n';
    cerr << ansi << '\n';
}

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

// dp[i][bit][ono][toggle]
// let every character works like A --on/off/none-> A' --toggle-> B
// for on and off, none spilts them and each connected size S needs (S + 1) / 2 (where every neighbor is different)
// for toggle, each connected size S also needs (S + 1) / 2 (where every neighbor is different)
// bit: last one (off: 0, on: 1, none: 2)
// ono: current on/off is odd
// toggle: current toggle is odd
int N, dp[1000006][3][2][2], A[1000006], B[1000006];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        A[i] = c - '0';
    }
    for (int i = 1; i <= N; i++)
    {
        char c;
        cin >> c;
        B[i] = c - '0';
    }
    for (int i = 0; i <= N; i++)
        for (int bit = 0; bit <= 2; bit++)
            for (int ono = 0; ono <= 1; ono++)
                for (int toggle = 0; toggle <= 1; toggle++)
                    dp[i][bit][ono][toggle] = 10 * N;
    dp[0][2][1][0] = 0;
    for (int i = 0; i < N; i++)
        for (int bit = 0; bit <= 2; bit++)
            for (int ono = 0; ono <= 1; ono++)
                for (int toggle = 0; toggle <= 1; toggle++)
                {
                    for (int nb = 0; nb <= 2; nb++)
                    {
                        bool sw = (bit != nb),
                             to = (((bit == 2 ? A[i] : bit) ^ B[i]) != ((nb == 2 ? A[i + 1] : nb) ^ B[i + 1]));
                        if (nb == 2)
                        {
                            dp[i + 1][nb][1][toggle ^ to] = min(dp[i + 1][nb][1][toggle ^ to],
                                                                 dp[i][bit][ono][toggle] + (ono & sw) + (toggle & to));
                        }
                        else
                        {
                            dp[i + 1][nb][ono ^ sw][toggle ^ to] = min(dp[i + 1][nb][ono ^ sw][toggle ^ to],
                                                                       dp[i][bit][ono][toggle] + (ono & sw) + (toggle & to));
                        }
                    }
                }
    // for (int i = 1; i <= N; i++)
    //     for (int bit = 0; bit <= 2; bit++)
    //         for (int ono = 0; ono <= 1; ono++)
    //             for (int toggle = 0; toggle <= 1; toggle++)
    //                 cout << i << ' ' << bit << ' ' << ono << ' ' << toggle << "  " << dp[i][bit][ono][toggle] << '\n';

    int ans = 10 * N;
    for (int bit = 0; bit <= 2; bit++)
        for (int ono = 0; ono <= 1; ono++)
            for (int toggle = 0; toggle <= 1; toggle++)
                ans = min(ans, dp[N][bit][ono][toggle] + (ono & (bit <= 1)) + toggle);
    cout << ans << '\n';
}
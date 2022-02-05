#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string A, B;
const ll mod = 998244353;
ll dp[10005][105][2], pre[10005][105][26][2], N, M;

int main()
{
    // dp[i][j][k] => the count of the string that we have matched:
    // - the current string is an substring of B[1..i], and the last character is matched
    // - A[1..j] is an substring of the current string
    // we greedily match so the transform is
    // for i' in (last time B[i] appears in B) to i - 1
    //     dp[i][j] += dp[i'][j - (A[i] == c)];
    cin >> A >> B;
    N = B.size(), M = A.size();
    A = '$' + A;
    B = '$' + B;
    for (int c = 0; c < 26; c++)
        pre[0][0][c][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= M; j++)
            for (int k = 0; k <= 1; k++)
            {
                // to expand the dp a bit to ensure we remove even character in B
                // when we match the character, the transform is
                // for i' in (last time B[i] appears in B) to i - 1
                //     dp[i][j][k] += dp[i'][j - (A[i] == c)][k ^ (i - i' - 1)];
                // therefore when we update prefix sum, we wont change even-odd and the next time we swap first and add
                dp[i][j][k] = pre[i - 1][j - (A[j] == B[i])][B[i] - 'a'][k];
                for (int c = 0; c < 26; c++)
                {
                    if (c == B[i] - 'a')
                        pre[i][j][c][k] = dp[i][j][k];
                    else
                        pre[i][j][c][k] = (pre[i - 1][j][c][k ^ 1] + dp[i][j][k]) % mod;
                }
            }
    /*for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
            printf("dp[%d][%d] = (%lld, %lld) ", i, j, dp[i][j][0], dp[i][j][1]);
        cout << '\n';
    }*/
    ll ans = 0;
    for (int i = 1; i <= N; i++)
        ans = (ans + dp[i][M][(N - i) & 1]) % mod;
    cout << ans << '\n';
}
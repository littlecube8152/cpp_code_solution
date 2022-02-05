#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int flip[2005][2005], n, board[2005][2005], ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (board[i][j] != board[j][i])
            {
                cout << -1 << '\n';
                return 0;
            }
    for (int i = n - 1; i >= 0; i--)
        for (int j = 1; j <= n - i; j++)
        {
                flip[j][i + j] = flip[j][i + j + 1] + flip[j - 1][i + j] - flip[j - 1][i + j + 1];
            if ((board[j][i + j] + flip[j][i + j]) % 2)
                ans++, flip[j][i + j]++;
        }
    cout << ans << '\n';
}
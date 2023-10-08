#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, K, dp[105][4][4][4];
string s[3];
vector<int> masks[6] = {{},
                        {1, 2, 3, 4, 5, 6, 7},
                        {1, 2, 4, 5},
                        {1, 2, 4, 5},
                        {1, 2, 4, 5},
                        {1, 2, 4}};

void chmax(int &a, int b)
{
    a = max(a, b);
}

int check(int d)
{
    int res = 0;
    for (int i = 1; i <= N; i++)
        for (int a : {0, 1, 2, 3})
            for (int b : {0, 1, 2, 3})
                for (int c : {0, 1, 2, 3})
                    dp[i][a][b][c] = 0;

    for (int i = 1; i <= N; i++)
        for (int mask : masks[min(5, d)])
            for (int j = 0; j < i; j++)
            {
                bitset<3> t = mask;
                if((t[0] && s[0][i - 1] == '#') || (t[1] && s[1][i - 1] == '#') || (t[2] && s[2][i - 1] == '#'))
                    continue;
                if (!j)
                    chmax(dp[i][t[0] ? 0 : 3][t[1] ? 0 : 3][t[2] ? 0 : 3], __builtin_popcount(mask));
                
                for (int a : {0, 1, 2, 3})
                    for (int b : {0, 1, 2, 3})
                        for (int c : {0, 1, 2, 3})
                        {
                            vector<pii> u = {pii(0, j - a), pii(1, j - b), pii(2, j - c)};
                            bool flag = 1;
                            for (int k = 0; k < 3; k++)
                                if (t[k])
                                    for (auto [x, y] : u)
                                        if ((x - k) * (x - k) + (y - i) * (y - i) < d)
                                            flag = 0;
                                
                            if (flag)
                                chmax(dp[i][t[0] ? 0 : min(3, a + i - j)][t[1] ? 0 : min(3, b + i - j)][t[2] ? 0 : min(3, c + i - j)], dp[j][a][b][c] + __builtin_popcount(mask));
                        }
            }
    for (int i = 1; i <= N; i++)
        for (int a : {0, 1, 2, 3})
            for (int b : {0, 1, 2, 3})
                for (int c : {0, 1, 2, 3})
                    res = max(res, dp[i][a][b][c]);
    return res;
}

signed main()
{
    cin >> N >> K;
    for (int i = 0; i < 3; i++)
        cin >> s[i];
    int l = 0, r = 100 * 100 + 4;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid) >= K)
            l = mid;
        else
            r = mid - 1;
    }
    if (r == 0)
        cout << -1 << '\n';
    else
        cout << fixed << setprecision(10) << sqrtl(l) << '\n';
}
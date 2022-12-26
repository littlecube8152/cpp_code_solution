#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N;
string b[4], t;
vector<string> dp[16];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < 4; i++)
        cin >> b[i];
    dp[0].emplace_back("");
    for (int mask = 1; mask < (1 << 4); mask++)
    {
        for (int i = 0; i < 4; i++)
            if ((mask >> i) & 1)
            {
                for (string s : dp[mask ^ (1 << i)])
                    for (int j = 0; j < 6; j++)
                        dp[mask].emplace_back(s + b[i][j]);
            }
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> t;
        bool find = 0;
        for (int mask = 1; mask < (1 << 4); mask++)
            for (string s : dp[mask])
                if (s == t)
                    find = 1;
        if (find)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
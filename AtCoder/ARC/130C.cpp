/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

ll N, cnt[10][2], mx = 0;
string s[2], ans[2];

signed main()
{
    fast;
    cin >> s[0] >> s[1];
    ans[0] = s[0];
    ans[1] = s[1];

    for (int sw = 0; sw <= 1; sw++)
    {
        for (int t = 1; t <= 9; t++)
        {
            string res[2];
            int inc = 0;

            for (int i = 0; i <= 9; i++)
                cnt[i][0] = cnt[i][1] = 0;
            for (char c : s[0])
                cnt[c - '0'][0]++;
            for (char c : s[1])
                cnt[c - '0'][1]++;
            if (!cnt[t][0])
                continue;
            cnt[t][0]--;
            for (int i = 10 - t; i <= 9; i++)
                if (cnt[i][1])
                {
                    cnt[i][1]--;
                    res[0].push_back(char('0' + t));
                    res[1].push_back(char('0' + i));
                    break;
                }
            if (res[0].empty())
                continue;
            //cout << sw << " " << t << " ";
            for (int i = 1; i <= 9; i++)
            {
                for (int j = 9 - i; j <= 9; j++)
                {
                    int add = min(cnt[i][0], cnt[j][1]);
                    cnt[i][0] -= add;
                    cnt[j][1] -= add;
                    for (int k = 1; k <= add; k++)
                    {
                        res[0].push_back(char('0' + i));
                        res[1].push_back(char('0' + j));
                    }
                }
            }
            for (int i = 9; i >= 1; i--)
            {
                for (int j = 1; j <= cnt[i][0]; j++)
                    res[0].push_back(char('0' + i));
                for (int j = 1; j <= cnt[i][1]; j++)
                    res[1].push_back(char('0' + i));
            }
            for (int i = 0, j = 0; i < max(res[0].size(), res[1].size()); i++)
            {
                j += (i < res[0].size() ? res[0][i] - '0' : 0) + (i < res[1].size() ? res[1][i] - '0' : 0);
                inc += (j /= 10);
            }
            reverse(res[0].begin(), res[0].end());
            reverse(res[1].begin(), res[1].end());
            //cout << inc << " " << res[0] << " " << res[1] << '\n';
            if (sw)
                res[0].swap(res[1]);
            if (inc > mx)
            {
                mx = inc;
                ans[0] = res[0], ans[1] = res[1];
            }
        }
        swap(s[0], s[1]);
    }
    cout << ans[0] << '\n'
         << ans[1] << '\n';
}

/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t, n, x, dp[1000005], cnt[1000005];

signed main()
{
    fast;
    cin >> n;
    ofstream fout("2207.out");
    for (int i = 3; i <= n; i++)
    {

        for (int j = 1; j < (i + 1) / 2; j++)
            cnt[dp[i - j] ^ dp[j]]++;
        for (int j = 0; j <= i; j++)
            if (!cnt[j])
            {
                dp[i] = j;
                break;
            }
        for (int j = 1; j < (i + 1) / 2; j++)
            cnt[dp[i - j] ^ dp[j]]--;
        if (i % 100 == 0)
            cout << "finished " << i << '\n';
    }
    for (int i = 1; i <= n; i++)
        if (dp[i] == 0)
            fout << "(n == " << i << ") || ";
}
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
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775807;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int N, pre[100005][26];
pii mi[26];
string s;

signed main()
{
    fast;
    cin >> s;
    N = s.size();
    for (int i = 1; i < N; i++)
        if(s[i - 1] == s[i])
        {
            cout << i << " " << i + 1 << '\n';
            return 0;
        }
    for (int i = 1; i < N - 1; i++)
        if(s[i - 1] == s[i + 1])
        {
            cout << i << " " << i + 2 << '\n';
            return 0;
        }
    cout << -1 << " " << -1 << '\n';
}

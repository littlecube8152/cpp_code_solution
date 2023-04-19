/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, K, x;
string s;

signed main()
{
    fast;
    cin >> N >> K;
    cin >> s;
    for (auto c : s)
        if (c == 'X')
            x++;
    if (K > x)
    {
        for (int i = 0; i < N; i++)
            s[i] = (s[i] == 'X' ? 'Y' : 'X');
        K = N - K;
    }
    if (s == string(N, 'X'))
    {
        cout << max(0, K - 1) << '\n';
        return 0;
    }

    vector<int> v;
    int last = -1, ans = 0;
    for (int i = 0; i < N; i++)
        if (s[i] == 'Y')
        {
            if (last != -1)
                v.emplace_back(i - last - 1);

            last = i;
        }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        if (K >= i)
        {
            K -= i;
            ans += i + 1;
        }
    }
    ans += K;
    cout << ans << '\n';
}

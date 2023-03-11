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
// #pragma pack(0)
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

int N, M, inv;
vector<pii> ans;

signed main()
{
    fast;
    cin >> N >> M;
    if (M >= N)
        swap(N, M), inv = 1;
    for (int i = 0; i < M; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = -2; j < 3; j++)
                if (1 <= N - j - i && N - j - i <= N)
                    ans.emplace_back(pii(N - j - i, M - i));
        }
        else
            for (int j = -1; j < 2; j++)
                if (1 <= N - j - i && N - j - i <= N)
                    ans.emplace_back(pii(N - j - i, M - i));
    }
    int mx = ans.back().F;
    for (int i = 1; i < mx; i++)
        ans.emplace_back(pii(i, 1));
    for (auto &p : ans)
        if (inv)
            swap(p.F, p.S);
    cout << ans.size() << '\n';
    for (auto &p : ans)
        cout << p.F << ' ' << p.S << '\n';
}

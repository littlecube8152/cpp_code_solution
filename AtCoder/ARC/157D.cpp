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

const ll mod = 998244353;
ll N, M, ans, cnt;
vector<pii> Nv, Mv;

signed main()
{
    fast;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            char c;
            cin >> c;
            if (c == 'Y')
            {
                cnt++;
                Nv.emplace_back(pii(i, j));
            }
        }
    Mv = Nv;
    sort(Mv.begin(), Mv.end(), [&](pii p1, pii p2)
         { return pii(p1.S, p1.F) < pii(p2.S, p2.F); });

    if (cnt % 2 == 1 || cnt == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    for (int A = 1; A <= N; A++)
        if (cnt / 2 % A == 0 && cnt / 2 / A <= M)
        {
            // N -> A parts, M -> B parts (each parts has 2)
            int B = cnt / 2 / A;
            ll res = 1;
            vector<pii> a(A + 1, pii(N + 1, 0));
            vector<int> id(N + 1);
            vector<int> aa(A, 0);
            vector<pii> b(B + 1, pii(M + 1, 0));
            for (int i = 0; i < cnt; i++)
            {
                a[i / (2 * B)].F = min(a[i / (2 * B)].F, Nv[i].F);
                a[i / (2 * B)].S = max(a[i / (2 * B)].S, Nv[i].F);
            }
            for (int i = 0; i < A - 1; i++)
                res = res * max(0, a[i + 1].F - a[i].S) % mod;
            if (res == 0)
                continue;
            for (int i = 0; i < A; i++)
                for (int j = a[i].F; j <= a[i].S; j++)
                    id[j] = i;
            for (int i = 0; i < cnt; i++)
            {
                int idx = id[Mv[i].F];
                if (aa[idx] % 2 == 0)
                    b[aa[idx] / 2].F = min(b[aa[idx] / 2].F, Mv[i].S);
                else
                    b[aa[idx] / 2].S = max(b[aa[idx] / 2].S, Mv[i].S);
                aa[idx]++;
            }
            for (int i = 0; i < B - 1; i++)
                res = res * max(0, b[i + 1].F - b[i].S) % mod;
            ans = (ans + res) % mod;
        }
    cout << ans << '\n';
}


/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const ll mod = MOD;
const ll inv26 = 729486258;
const ll sz = 2;
using mtx = vector<vector<ll>>;

mtx mul(mtx a, mtx b)
{
    mtx tmp = mtx{{0, 0}, {0, 0}};
    for (int i = 0; i < sz; i++)
        for (int k = 0; k < sz; k++)
            for (int j = 0; j < sz; j++)
                tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % mod;
    return tmp;
}

mtx fastpow(mtx b, ll p)
{
    mtx a = mtx{{1, 0}, {0, 1}}, tmp = mtx{{0, 0}, {0, 0}};
    while (p)
    {
        if (p & 1)
            a = mul(a, b);
        b = mul(b, b);
        p >>= 1;
    }
    return a;
}

signed main()
{
    fast;
    ll p, n, m, k;
    char c;
    cin >> p >> n;
    cin >> m;
    cin >> k;
    mtx b = mtx{{(26 - k) * inv26 % mod, k * inv26 % mod},  // 1
                {k * inv26 % mod, (26 - k) * inv26 % mod}}; // -1
    b = fastpow(b, p);
    cout << (b[0][0] - b[1][0] + mod) % mod << '\n';
}

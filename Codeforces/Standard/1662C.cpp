/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

const int sz = 305;
const ll mod = 998244353;
int n, m, k;
ll A[sz][sz], B[sz][sz], tmp[sz][sz];

void mul(ll A[sz][sz], ll B[sz][sz], ll C[sz][sz])
{
    for (int i = 1; i <= 3 * n; i++)
        for (int j = 1; j <= 3 * n; j++)
            C[i][j] = 0;
    for (int i = 1; i <= 3 * n; i++)
        for (int k = 1; k <= 3 * n; k++)
            for (int j = 1; j <= 3 * n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
}

void copy(ll A[sz][sz], ll B[sz][sz])
{
    for (int i = 1; i <= 3 * n; i++)
        for (int j = 1; j <= 3 * n; j++)
            B[i][j] = A[i][j];
}

void fpow(int p)
{
    while (p)
    {
        if (p & 1)
        {
            mul(A, B, tmp);
            copy(tmp, A);
        }
        mul(B, B, tmp);
        copy(tmp, B);
        p >>= 1;
    }
}

signed main()
{
    fast;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        B[3 * i - 1][3 * i] = 1;
        B[3 * i - 1][3 * i - 2] = 1;
        B[3 * i - 2][3 * i - 1] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        B[3 * u][3 * v] = 1;
        B[3 * v][3 * v - 1]--;
        B[3 * u][3 * v - 2] = 1;
        B[3 * v][3 * u] = 1;
        B[3 * u][3 * u - 1]--;
        B[3 * v][3 * u - 2] = 1;
    }
    for (int i = 1; i <= n; i++)
        A[3 * i][3 * i] = 1;
    fpow(k);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + A[3 * i][3 * i] + mod) % mod;
    cout << ans << '\n';
}

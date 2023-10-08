/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
// #define int long long
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

ll n, k, mx[1000006];
vector<int> sol[2];

signed main()
{
    fast;
    cin >> n >> k;

    for (int i = n; i >= 1; i--)
        mx[i] = mx[i + 1] + (n - (n - i) / 2);

    if (k < n * (n + 1) / 2)
    {
        cout << -1 << '\n';
        return 0;
    }

    k = min(k, mx[1]);

    ll cur = 0;
    int side = 0;
    vector<int> trash;

    for (int i = 1, j = 0; i <= n; i++)
        for (int t = 1; t <= 2; t++)
            if (j < i && cur + i + mx[j + 2] >= k)
            {
                j++;
                cur += i;
                sol[side].emplace_back(i);
                side ^= 1;
                sol[side].emplace_back(0);
            }
            else
                trash.emplace_back(i);

    cout << k << '\n';
    for (int i = 0; i < n; i++)
        cout << (sol[0][i] == 0 ? trash[i] : sol[0][i]) << " \n"[i == n - 1];
    for (int i = 0; i < n; i++)
        cout << (sol[1][i] == 0 ? trash[i] : sol[1][i]) << " \n"[i == n - 1];
}

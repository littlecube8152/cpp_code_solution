/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
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

int n, m, v[1000006], a[1000006], b[1000006];

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if(v[i] <= m)
            a[v[i]]++;
    }
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j += i)
            b[j] += a[i];
    int z = 1;
    for (int i = 1; i <= m; i++)
        if(b[z] < b[i])
            z = i;
    cout << z << ' ' << b[z] << '\n';
    for (int i = 1; i <= n; i++)
        if(z % v[i] == 0)
            cout << i << ' ';
    cout << '\n';
}

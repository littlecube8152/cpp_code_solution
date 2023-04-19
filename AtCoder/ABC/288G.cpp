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

int p, N = 1, M, A[600000];

signed main()
{
    fast;
    cin >> p;
    for (int i = 1; i <= p; i++)
        N *= 3;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    M = N;
    while(p--)
    {
        M /= 3;
        for (int i = 0; i < N; i++)
            if(i / M % 3 == 1)
                A[i] = A[i - M] + A[i + M] - A[i];
        for (int i = 0; i < N; i++)
            if(i / M % 3 == 0)
                A[i] -= A[i + M];
            else if(i / M % 3 == 2)
                A[i] -= A[i - M];
    }
    for (int i = 0; i < N; i++)
        cout << A[i] << " \n"[i == N - 1];
}

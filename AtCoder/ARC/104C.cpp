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

int N, a[205], io[205], both[105], dp[205];

signed main()
{
    fast;
    cin >> N;
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        int A, B;
        cin >> A >> B;
        if (A != -1)
        {
            if (a[A])
                dp[0] = 0;
            a[A] = i;
            io[A] = 1;
        }
        if (B != -1)
        {
            if (a[B])
                dp[0] = 0;
            a[B] = i;
            io[B] = 2;
        }
        if (A != -1 && B != -1)
            both[i] = 1;
        
    }
    for (int i = 2; i <= 2 * N; i += 2)
        for (int j = 0; j < i; j += 2)
            if (dp[j])
            {
                int k = (i - j) / 2;
                bool v = 1;
                for (int l = j + 1; l <= j + k; l++)
                    if (a[l] != a[l + k] && a[l] != 0 && a[l + k] != 0)
                        v = 0;
                    else if (a[l] != a[l + k] && both[a[l]])
                        v = 0;
                    else if (a[l] != a[l + k] && both[a[l + k]])
                        v = 0;
                    else if (io[l] == 2 || io[l + k] == 1)
                        v = 0;
                if (v)
                    dp[i] = 1;
            }
    cout << (dp[2 * N] ? "Yes\n" : "No\n");
}

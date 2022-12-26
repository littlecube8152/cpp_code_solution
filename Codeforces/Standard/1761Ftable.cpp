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

int n;
vector<int> cur;

void brute(int mask)
{
    if (__builtin_popcount(mask) == n)
    {
        for (int i : cur)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
        if ((mask & (1 << i)) == 0)
        {
            cur.emplace_back(i);
            int m = cur.size();
            bool valid = 1;
            for (int j = 3; j <= m; j += 2)
            {
                int mid = cur[m - (j + 1) / 2], l = 0, r = 0;
                for (int k = 1; k <= j; k++)
                    if (cur[m - k] < mid)
                        l++;
                    else if (cur[m - k] > mid)
                        r++;
                if (l == r)
                    valid = 0;
            }
            if (valid)
                brute(mask ^ (1 << i));
            cur.pop_back();
        }
}

signed main()
{
    fast;
    cin >> n;
    brute(0);
}

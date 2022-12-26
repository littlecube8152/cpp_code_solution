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

int n, m, bit[400005];
string s;

void reset()
{
    for (int i = 1; i <= m; i++)
        bit[i] = 0;
}

void modify(int pos, int val)
{
    for (int i = pos; i <= m; i += (i & -i))
        bit[i] += val;
}

int query(int pos)
{
    int res = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        res += bit[i];
    return res;
}

void solve()
{
    cin >> n >> s;
    m = 2 * n + 1;
    reset();
    ll ans = 0, cur = 0, mid = n + 1;
    vector<int> neg(2 * n + 2);
    for (int i = 1; i <= n; i++)
    {
        char c = s.back();
        s.pop_back();
        modify(mid, 1);
        neg[mid]++;
        if (c == ')')
        {
            cur -= (i - query(mid));
            cur += i;
            mid++;
        }
        else if (c == '(')
        {
            cur += (i - query(mid - 1));
            cur -= (i - neg[mid]);
            neg[mid - 1] += neg[mid];
            neg[mid] = 0;
            mid--;
        }

        ans += cur;
    }
    cout << ans << '\n';
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}

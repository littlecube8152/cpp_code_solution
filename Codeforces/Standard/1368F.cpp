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

int n, m;
set<int> st;

signed main()
{
    cin >> n;
    int k = 2;
    for (int i = 2; i < n - 1; i++)
        if (n - (n + k - 1) / k - (k - 1) < n - (n + i - 1) / i - (i - 1))
            k = i;
    cerr << k << ' ' << n - (n + k - 1) / k - (k - 1) << '\n';

    for (int i = 1; i < n; i++)
        if (i % k != 0)
            st.insert(i);
    while (st.size() >= k)
    {
        cout << k;
        for (int i = 1; i <= k; i++)
        {
            cout << ' ' << *st.begin();
            st.erase(st.begin());
        }
        cout << endl;

        int x;
        cin >> x;
        for (int i = 1; i <= k; i++)
        {
            if (x < n && x % k != 0)
                st.insert(x);
            x = x % n + 1;
        }
    }
    cout << 0 << endl;
}

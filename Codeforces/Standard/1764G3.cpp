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

int n, ans[2000][2000], a[2000];

int ask(int i, int j, int k)
{
    if (k == 2 && ans[i][j])
        return ans[i][j];
    if (i == 1 && j == n && k == 2)
        return n / 2 + 1;
    int t;
    cout << "? " << i << ' ' << j << ' ' << k << endl;

    // set<int> st;
    // for (int x = i; x <= j; x++)
    //     st.insert(a[x] / k);
    // t = st.size();
    // cout << t << endl;
    cin >> t;
    if (k == 2)
        ans[i][j] = t;
    return t;
}

signed main()
{
    cin >> n;

    // for(int i = 1; i <= n; i++)
    //     cin >> a[i];

    int L = 1, R = n, tot = (n + 2) / 2;
    int n1 = 0;
    while (R - L > 1)
    {
        int mid = (L + R) / 2;
        int ql = ask(1, mid, 2), qr = ask(mid + 1, n, 2);
        int cross = ql + qr - tot;
        int ls = mid - 2 * ql + cross,
            rs = n - mid - 2 * qr + cross;
        cerr << L << ' ' << R << ' ' << ls << ' ' << rs << '\n';
        if (ls < 0 && rs < 0)
        {
            if (n1 == 0)
                n1 = (ask(1, mid, n) == 2 ? 1 : 2);
            if (n1 == 1)
                ls++;
            else
                rs++;
        }
        if (ls < rs)
            R = mid;
        else
            L = mid + 1;
    }
    if (L < R)
    {
        if (n1 == 0 && ask(L, R, n) == 2)
        {
            if (L > 1)
                L = R = (ask(L - 1, L, n) == 1 ? L : R);
            else
                L = R = (ask(R, R + 1, n) == 1 ? R : L);
        }
        else
        {
            if (R == n || ask(L, n, 2) - ask(R + 1, n, 2) == 2)
                L = R = (ask(1, L, 2) - ask(1, L - 1, 2) == 1 ? L : R);
            else
                L = R = (ask(R, n, 2) - ask(R + 1, n, 2) == 1 ? R : L);
        }
    }
    cout << "! " << L << endl;
}

//
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

int t, n, vis[1005], c[1005], d[1005];

void solve()
{
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        vis[i] = c[i] = 0;
        cin >> d[i];
        v.emplace_back(i);
    }
    sort(v.begin(), v.end(), [&](int i, int j)
         { return d[i] > d[j]; });
    for(auto i : v)
        if(!vis[i])
        {
            int color = i;
            bool sw = 0;
            vector<int> u = {i};
            for (int j = 1; !sw && j <= d[i]; j++)
            {
                int k;
                cout << "? " << i << endl;
                cin >> k;
                u.emplace_back(k);
                if(vis[k])
                    sw = 1;
            }
            if(sw)
                color = c[u.back()];
            for(int j : u)
                vis[j] = 1, c[j] = color;
        }
    cout << "!";
    for(int i = 1; i <= n; i++)
        cout << ' ' << c[i];
    cout << endl;
}

signed main()
{
    cin >> t;
    while (t--)
        solve();
}

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

struct dsu
{
    int h[1005];

    dsu(int n)
    {
        for (int i = 0; i < n; i++)
            h[i] = i;
    }

    int find(int k)
    {
        return k == h[k] ? k : h[k] = find(h[k]);
    }

    bool merge(int a, int b)
    {
        int ra = find(a), rb = find(b);
        h[ra] = rb;
        return ra != rb;
    }
};

int N, M;
vector<int> xg[1005], yg[1005];

signed main()
{
    fast;
    cin >> N >> M;
    dsu x(N), y(M);
    xg[0].emplace_back(0);
    xg[N - 1].emplace_back(0);
    yg[0].emplace_back(0);
    yg[M - 1].emplace_back(0);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                xg[i].emplace_back(j % (M - 1));
                yg[j].emplace_back(i % (N - 1));
            }
        }
    xg[0].emplace_back(0);
    xg[N - 1].emplace_back(0);
    yg[0].emplace_back(0);
    yg[M - 1].emplace_back(0);

    int Nans = N - 2, Mans = M - 2;
    for (int i = 0; i < N; i++)
        for (int j = 1; j < xg[i].size(); j++)
            Mans -= y.merge(xg[i][j - 1], xg[i][j]);

    for (int i = 0; i < M; i++)
        for (int j = 1; j < yg[i].size(); j++)
            Nans -= x.merge(yg[i][j - 1], yg[i][j]);

    cout << min(Mans, Nans) << '\n';
}

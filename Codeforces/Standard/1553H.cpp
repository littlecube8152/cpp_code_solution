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
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

struct node
{
    int l = -1, r = -1, mid = 777771449;
    void apply(int k)
    {
        l = (l == -1 ? -1 : l ^ k);
        r = (r == -1 ? -1 : r ^ k);
    }
};

node merge(node n, node m)
{
    if (n.l == -1)
        return m;
    if (m.l == -1)
        return n;
    return node{n.l, m.r, min({n.mid, m.mid, m.l - n.r})};
}

int K, N, ans[1 << 19];
vector<node> v[1 << 19];

void calc(int i)
{
    node tot;
    for (auto u : v[i])
        tot = merge(tot, u);
    ans[i] = tot.mid;
}

signed main()
{
    fast;
    cin >> N >> K;
    v[0].resize(1 << K);
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        v[0][a] = node{a, a};
    }

    calc(0);

    for (int k = 0; k < K; k++)
    {
        for (int i = 0; i < (1 << k); i++)
        {
            int j = i ^ (1 << k);
            v[j] = v[i];
            for (int l = 0; l < v[j].size(); l += 2)
            {
                v[j][l].apply(1 << k);
                v[j][l + 1].apply(1 << k);
                swap(v[j][l], v[j][l + 1]);
            }
        }
        for (int i = 0; i < (1 << (k + 1)); i++)
        {
            vector<node> nxt;
            for (int j = 0; j < v[i].size(); j += 2)
                nxt.emplace_back(merge(v[i][j], v[i][j + 1]));
            nxt.swap(v[i]);
        }
        for (int i = (1 << k); i < (1 << (k + 1)); i++)
            calc(i);
    }
    for (int i = 0; i < (1 << K); i++)
        cout << ans[i] << " \n"[i + 1 == (1 << K)];
}

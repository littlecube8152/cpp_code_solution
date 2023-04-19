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

int N, M, A[200005], B[200005], pre[200005], dis[200005], vis[200005], ans[200005];
vector<pii> E[200005];

void dfs(int u)
{
    vis[u] = 1;
    for(auto [v, i] : E[u])
        if(!vis[v])
        {
            ans[abs(i)] = 1 + (i < 0);
            dis[v] = dis[u] + 1, pre[v] = u;
            dfs(v);
        }
        else if(!ans[abs(i)])
            ans[abs(i)] = 1 + (i < 0);
}

signed main()
{
    fast;
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        cin >> A[i];
    for (int i = 1; i <= M; i++)
    {
        cin >> B[i];
        E[A[i]].emplace_back(pii(B[i], i));
        E[B[i]].emplace_back(pii(A[i], -i));
    }
    for (int i = 1; i <= N; i++)
        if(!vis[i])
            dfs(i);
    for (int i = 1; i <= M; i++)
        cout << ans[i] - 1;
    cout << '\n';
}

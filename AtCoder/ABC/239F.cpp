/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

#define LOCAL

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int N, M, D[200005], vis[200005], idx, sumD[200005];
set<pii> st;
vector<int> E[200005];
vector<pii> sol, cc[200005];

ll dfs(int k)
{
    ll res = 0;
    for (int i : E[k])
        if (!vis[i])
        {
            vis[i] = 1;
            res += dfs(i);
        }
    if (D[k] - E[k].size() > 0)
        cc[idx].emplace_back(pii{k, D[k] - E[k].size()});
    return res + D[k] - E[k].size();
}

signed main()
{
    fast;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> D[i];
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= N; i++)
        if (E[i].size() > D[i])
        {
            cout << -1 << '\n';
            return 0;
        }
    for (int i = 1; i <= N; i++)
        if (!vis[i])
        {
            idx++;
            vis[i] = 1;
            sumD[idx] = dfs(i);
            st.insert(pii{sumD[idx], idx});
        }
    for (int i = 1; i <= N - 1 - M; i++)
    {
        auto f = st.begin(), s = prev(st.end());
        if (f->F <= 0)
        {
            cout << -1 << '\n';
            return 0;
        }
        sol.emplace_back(pii{f->S, s->S});
        st.insert(pii{s->F - 1, s->S});
        st.erase(f);
        st.erase(s);
    }
    if (st.size() > 1 || st.begin()->F != 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    for (auto [u, v] : sol)
    {
        cout << cc[u].back().F << " " << cc[v].back().F << '\n';
        if (--cc[u].back().S == 0)
            cc[u].pop_back();
        if (--cc[v].back().S == 0)
            cc[v].pop_back();
    }
}

/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma loop_opt(on)
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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
//using namespace __gnu_pbds;

int T, N, M, Q, dsu[500005], rk[500005], ans[500005], cc;
vector<pii> seg[1000005];
map<pii, int> last, cnt;

int find(int k)
{
    return k == dsu[k] ? k : find(dsu[k]);
}

bool merge(int u, int v)
{
    if (rk[u] <= rk[v])
    {
        cc--;
        rk[v] += rk[u];
        dsu[u] = v;
        return false;
    }
    else
    {
        merge(v, u);
        return true;
    }
}

void undo(int u, int v)
{
    cc++;
    rk[v] -= rk[u];
    dsu[u] = u;
}

void init(int i = 1, int L = 1, int R = 1 + Q)
{
    seg[i].clear();
    if (L != R)
    {
        int mid = (L + R) / 2;
        init(i + 1, L, mid);
        init(i + 2 * (mid - L + 1), mid + 1, R);
    }
}

void modify(int mL, int mR, pii operation, int i = 1, int L = 1, int R = 1 + Q)
{
    if (mL <= L && R <= mR)
        seg[i].emplace_back(operation);
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        modify(mL, mR, operation, i + 1, L, mid);
        modify(mL, mR, operation, i + 2 * (mid - L + 1), mid + 1, R);
    }
}

void dfs(int i = 1, int L = 1, int R = 1 + Q)
{
    vector<pii> st;
    for (auto [u, v] : seg[i])
    {
        int ru = find(u), rv = find(v);
        if (ru != rv)
        {
            if (merge(ru, rv))
                st.emplace_back(pii{rv, ru});
            else
                st.emplace_back(pii{ru, rv});
        }
    }
    if (L == R)
        ans[L] = cc;
    else
    {
        int mid = (L + R) / 2;
        dfs(i + 1, L, mid);
        dfs(i + 2 * (mid - L + 1), mid + 1, R);
    }
    for (auto [u, v] : st)
        undo(u, v);
}

void solve()
{
    cin >> N >> M >> Q;
    init();
    for (int i = 0; i < N; i++)
        dsu[i] = i, rk[i] = 1;
    cc = N;

    for (int t = 1; t <= M; t++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        cnt[{u, v}]++;
        if (cnt[{u, v}] == 1)
            last[{u, v}] = 1;
    }
    for (int t = 2; t <= Q + 1; t++)
    {
        char c;
        int u, v;
        cin >> c >> u >> v;
        if (u > v)
            swap(u, v);
        if (c == 'N')
        {
            cnt[{u, v}]++;
            if (cnt[{u, v}] == 1)
                last[{u, v}] = t;
        }
        else
        {
            cnt[{u, v}]--;
            if (cnt[{u, v}] == 0)
            {
                modify(last[{u, v}], t - 1, {u, v});
                last.erase(last.find({u, v}));
            }
        }
    }
    for (auto [f, s] : last)
    {
        int u = f.F, v = f.S;
        modify(last[{u, v}], Q + 1, {u, v});
    }
    last.clear();
    cnt.clear();
    dfs();
    for (int i = 2; i <= Q + 1; i++)
        cout << ans[i] << '\n';
}

signed main()
{
    fast;
    cin >> T;
    while (T--)
        solve();
}
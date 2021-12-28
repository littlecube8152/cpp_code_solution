/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string a, b, s;
int N, M, order[400005], neworder[400005], v[400005], lcp[400005][20], ans;
pii substr[400005];

inline void buildlcp()
{
    for (int p = 1; p <= 19; p++)
        for (int i = 0; i < N; i++)
            lcp[i][p] = min(lcp[i][p - 1], lcp[min(N - 1, i + (1 << (p - 1)))][p - 1]);
}

inline void init()
{
    s = s + ' ';
    N = s.length();
    iota(v, v + N, 0);
    sort(v, v + N, [&](int p1, int p2) { return s[p1] < s[p2]; });
    order[v[0]] = 0;
    for (int i = 1; i < N; i++)
        order[v[i]] = order[v[i - 1]] + (s[v[i]] != s[v[i - 1]]);
}

inline void ordering(int k)
{
    neworder[v[0]] = 0;
    tuple<ll, ll> pre = tie(order[v[0]], order[(v[0] + k) % N]), now;
    for (int i = 1; i < N; i++)
    {
        now = tie(order[v[i]], order[(v[i] + k) % N]);
        neworder[v[i]] = neworder[v[i - 1]] + (pre != now);
        pre = now;
    }
    for (int i = 0; i < N; i++)
        order[i] = neworder[i];
}

int query(int l, int r)
{
    if (r < l)
        swap(l, r);
    int len = __lg(r - l);
    return min(lcp[l][len], lcp[r - (1 << len)][len]);
}

inline void count_sort(int k)
{
    vector<vector<int>> count(N);
    for (int i = 0; i < N; i++)
        v[i] = (v[i] - k + N) % N;
    for (int i = 0; i < N; i++)
        count[order[v[i]]].pb(v[i]);
    for (int i = 0, idx = 0; i < N; i++)
        for (int j : count[i])
            v[idx++] = j;
}

signed main()
{
    fast;
    cin >> s;
    init();
    for (int i = 0; (1 << i) < N && i <= 18; i++)
    {
        count_sort(1 << i);
        ordering(1 << i);
    }

    int k = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int pi = order[i];
        int j = v[pi - 1];
        while (s[i + k] == s[j + k])
            k++;
        lcp[order[j]][0] = k;
        k = max(k - 1LL, 0LL);
    }
    buildlcp();
    cin >> M;
    for (int i = 1; i <= M; i++)
        cin >> substr[i].F >> substr[i].S;
    for (int i = 1; i <= M; i++)
        substr[i].F--, substr[i].S--;
    sort(substr + 1, substr + M + 1, [&](pii p1, pii p2) {
        if (p1.F == p2.F)
            return p1.S < p2.S;
        int llcp = query(order[p1.F], order[p2.F]);
        if (p1.S < p1.F + llcp || p2.S < p2.F + llcp)
        {
            if (p1.S - p1.F != p2.S - p2.F)
                return p1.S - p1.F < p2.S - p2.F;
            return p1 < p2;
        }
        return s[p1.F + llcp] < s[p2.F + llcp];
    });
    for (int i = 1; i <= M; i++)
        substr[i].F++, substr[i].S++;
    for (int i = 1; i <= M; i++)
        cout << substr[i].F << " " << substr[i].S << '\n';
}
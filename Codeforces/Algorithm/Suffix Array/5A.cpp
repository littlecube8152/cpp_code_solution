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

string s;
int N, order[400005], neworder[400005], v[400005], lcp[400005], ans;

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
    s += '$';
    N = s.length();
    iota(v, v + N, 0);
    sort(v, v + N, [&](int p1, int p2) { return s[p1] < s[p2]; });
    order[v[0]] = 0;
    for (int i = 1; i < N; i++)
        order[v[i]] = order[v[i - 1]] + (s[v[i]] != s[v[i - 1]]);

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
        while(s[i + k] == s[j + k])
            k++;
        lcp[i] = k;
        k = max(k - 1LL, 0LL);
    }
    ans = N * (N - 1) / 2;
    for (int i = 1; i < N; i++)
        ans -= lcp[v[i]];
    cout << ans;
}
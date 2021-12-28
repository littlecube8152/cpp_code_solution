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

string s, t;
int N, M, order[300005], neworder[300005], v[300005];

inline void ordering(int k)
{
    neworder[v[0]] = 0;
    for (int i = 1; i < N; i++)
        neworder[v[i]] = neworder[v[i - 1]] + (order[v[i]] != order[v[i - 1]] || order[(v[i] + k) % N] != order[(v[i - 1] + k) % N]);
    for (int i = 0; i < N; i++)
        order[i] = neworder[i];
}

int binary(int L, int R)
{
    int mid = (L + R) / 2;
    string sub = s.substr(v[mid], min((int)t.length(), (int)s.length() - v[mid]));
    if (L == R)
        return L;
    if (sub < t)
        return binary(mid + 1, R);
    return binary(L, mid);
}

int binary2(int L, int R)
{
    int mid = (L + R) / 2;
    string sub = s.substr(v[mid], min((int)t.length(), (int)s.length() - v[mid]));
    if (L == R)
        return L;
    if (sub <= t)
        return binary2(mid + 1, R);
    return binary2(L, mid);
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
    vector<vector<int>> count(N);
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
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> t;
        cout << binary2(0, N) - binary(0, N) << '\n';
    }
}
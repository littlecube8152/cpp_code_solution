#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, D, H[100005], U, B, uid[200005], udx;
bool mx[200005], my[200005];
pii change[200005];
bool block[2005][200005];
vector<int> v[100005];
vector<int> fri[100005];
map<int, int> mp[100005];

void init(int n, int d, int h[])
{
    N = n;
    D = d;
    for (int i = 0; i < N; i++)
        H[i] = h[i];
}

void curseChanges(int u, int a[], int b[])
{
    U = u;
    B = sqrt((U + 1) / 3);
    for (int i = 0; i < U; i++)
    {
        if (a[i] > b[i])
            swap(a[i], b[i]);
        change[i].F = a[i];
        change[i].S = b[i];
    }
    for (int i = 0; i < U; i++)
        if (mp[a[i]].find(b[i]) != mp[a[i]].end())
            uid[i] = mp[a[i]][b[i]];
        else
        {
            mp[a[i]][b[i]] = uid[i] = i;
            v[a[i]].emplace_back(i);
            fri[a[i]].emplace_back(b[i]);
            v[b[i]].emplace_back(i);
            fri[b[i]].emplace_back(a[i]);
        }
    for (int i = 0; i < N; i++)
        sort(fri[i].begin(), fri[i].end(), [&](int i1, int i2)
             { return H[i1] < H[i2]; });
    for (int i = 1, j = 0; j < U; i++)
    {
        for (int k = 0; k < U; k++)
            block[i][k] = block[i - 1][k];
        for (; j < i * B && j < U; j++)
            block[i][uid[j]] ^= 1;
    }
}

int question(int x, int y, int V)
{
    int b = V / B;
    vector<ll> sx, sy;
    for (int i : v[x])
        if (block[b][i])
        {
            if (change[i].F == x)
                mx[change[i].S] = 1;
            else
                mx[change[i].F] = 1;
        }
    for (int i : v[y])
        if (block[b][i])
        {
            if (change[i].F == y)
                my[change[i].S] = 1;
            else
                my[change[i].F] = 1;
        }
    for (int i = b * B; i < V; i++)
    {
        if (change[i].S == x)
            mx[change[i].F] ^= 1;
        if (change[i].S == y)
            my[change[i].F] ^= 1;
        if (change[i].F == x)
            mx[change[i].S] ^= 1;
        if (change[i].F == y)
            my[change[i].S] ^= 1;
    }
    for (ll i : fri[x])
        if (mx[i])
            sx.emplace_back(H[i]);
    for (ll i : fri[y])
        if (my[i])
            sy.emplace_back(H[i]);
    ll ans = 1e9;
    while (!sx.empty() && !sy.empty())
    {
        ans = min(ans, abs(sx.back() - sy.back()));
        if (sx.back() >= sy.back())
            sx.pop_back();
        else
            sy.pop_back();
    }
    for (ll i : fri[x])
        mx[i] = 0;
    for (ll i : fri[y])
        my[i] = 0;
    return ans;
}

/*
6 5 11 4
2 42 1000 54 68 234
0 1 2 0 3 4 3 5 3 5 1 3 5 3 0 5 3 0 1 3 3 5
0 3 4 26
3 0 8 0
0 5 5 1000000000
3 0 11 14
*/
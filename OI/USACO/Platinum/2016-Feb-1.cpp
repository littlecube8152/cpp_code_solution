#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N;
pii p[100005], a[100005], ans[100005];

int bs(int L, int R)
{
    if (L == R)
        return L;
    int mid = (L + R) / 2;
    bool valid = false;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    left.push(1e9);
    right.push(-1e9);
    for (int i = 0, j = 1; i <= N; i++)
    {
        while (j <= N && a[j].S <= i)
        {
            left.push(a[j].F);
            right.push(a[j].F);
            j++;
        }
        while (left.size() > mid + 1)
            left.pop();
        while (right.size() > mid + 1)
            right.pop();
        ans[i] = {right.top(), left.top()};
    }
    while (left.size())
        left.pop();
    while (right.size())
        right.pop();
    left.push(1e9);
    right.push(-1e9);
    for (int i = N + 1, j = N; i >= 1; i--)
    {
        while (j >= 1 && a[j].S >= i)
        {
            left.push(a[j].F);
            right.push(a[j].F);
            j--;
        }
        while (left.size() > mid + 1)
            left.pop();
        while (right.size() > mid + 1)
            right.pop();
        if (max(right.top(), ans[i - 1].F) < min(left.top(), ans[i - 1].S))
            valid = 1;
    }
    while (left.size())
        left.pop();
    while (right.size())
        right.pop();
    if (valid)
        return bs(L, mid);
    else
        return bs(mid + 1, R);
}

signed main()
{
    fast;
    ifstream cin("balancing.in");
    ofstream cout("balancing.out");
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> p[i].F >> p[i].S;
        a[i] = p[i];
    }
    sort(p + 1, p + 1 + N);
    for (int i = 1; i <= N; i++)
        a[i].F = lower_bound(p + 1, p + 1 + N, pii{a[i].F, 0}) - p;
    auto cmp = [&](pii p1, pii p2)
    { return pii{p1.S, p1.F} < pii{p2.S, p2.F}; };
    sort(p + 1, p + 1 + N, cmp);
    for (int i = 1; i <= N; i++)
        a[i].S = lower_bound(p + 1, p + 1 + N, pii{0, a[i].S}, cmp) - p;
    sort(a + 1, a + 1 + N, cmp);
    cout << bs(1, N) << '\n';
}
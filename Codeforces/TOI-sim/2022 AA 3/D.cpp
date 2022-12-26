#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, A, B, Q, a[1000006], l[1000006], r[1000006], q[1000006];
ll bit[1000006], ans[1000006];
vector<int> dq[1000006];

void modify(int pos, ll val)
{
    for (int i = pos; i <= N; i += (i & -i))
        bit[i] += val;
}

ll query(int pos)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> l[i] >> r[i];
    for (int i = 1; i <= Q; i++)
        q[i] = i;
    sort(q + 1, q + Q + 1, [&](int i, int j)
         { return l[i] > l[j]; });
    int idx = 1;
    for (int i = N; i >= 1; i--)
    {
        dq[a[i]].emplace_back(i);
        int sz = dq[a[i]].size();
        if (sz == A)
            modify(dq[a[i]][sz - 1 - (A - 1)], a[i]);
        if (A < sz)
        {
            modify(dq[a[i]][sz - 1 - (A - 1)], a[i]);
            modify(dq[a[i]][sz - 1 - A], -a[i]);
        }
        if (B < sz)
            modify(dq[a[i]][sz - 1 - B], -a[i]);
        if (B + 1 < sz)
            modify(dq[a[i]][sz - 1 - (B + 1)], +a[i]);
        while (idx <= Q && l[q[idx]] == i)
        {
            ans[q[idx]] = query(r[q[idx]]);
            idx++;
        }
    }
    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';
}
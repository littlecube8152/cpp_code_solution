/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

ll N, M, dp[200005], seg[800005], lazy[800005], ptr1, ptr2;
vector<pair<pii, int>> pos;
vector<pair<pii, int>> neg;

void modify(int a, int b, int i, int l, int r, int v)
{
    if (a <= l && r <= b)
        lazy[i] += v;
    else if (b < l || r < a)
        return;
    else
    {
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
        lazy[i] = 0;

        int mid = (l + r) / 2;
        modify(a, b, i * 2, l, mid, v);
        modify(a, b, i * 2 + 1, mid + 1, r, v);

        seg[i] = max(seg[i * 2] + lazy[i * 2], seg[i * 2 + 1] + lazy[i * 2 + 1]);
    }
}

ll query(int a, int b, int i, int l, int r)
{
    if (a <= l && r <= b)
        return seg[i] + lazy[i];
    else if (b < l || r < a)
        return -1e18;
    else
    {
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
        lazy[i] = 0;

        seg[i] = max(seg[i * 2] + lazy[i * 2], seg[i * 2 + 1] + lazy[i * 2 + 1]);

        int mid = (l + r) / 2;

        return max(query(a, b, i * 2, l, mid), query(a, b, i * 2 + 1, mid + 1, r));
    }
}

signed main()
{
    fast;
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        ll l, r, w;
        cin >> l >> r >> w;
        pos.pb(make_pair(make_pair(l, l - 1), w));
        neg.pb(make_pair(make_pair(r, l - 1), -w));
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    for (int i = 1; i <= N + 1; i++)
    {
        while(ptr1 < pos.size() && pos[ptr1].F.F == i)
        {
            modify(0, pos[ptr1].F.S, 1, 0, N + 1, pos[ptr1].S);
            ptr1++;
        }

        dp[i] = query(0, i - 1, 1, 0, N + 1);
        modify(i, i, 1, 0, N + 1, dp[i]);

        while(ptr2 < neg.size() && neg[ptr2].F.F == i)
        {
            modify(0, neg[ptr2].F.S, 1, 0, N + 1, neg[ptr2].S);
            ptr2++;
        }
    }
    cout << query(0, N + 1, 1, 0, N + 1) << '\n';
}

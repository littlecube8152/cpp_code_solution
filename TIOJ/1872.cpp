/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
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

struct Q
{
    int i, l, r;
};

int n, q, arr[1000005], sieve[1000005], seg[4000000], prime[1000005], idx = 1, ans[1000005];
vector<pii> mq[1000000];
vector<Q> query;

int fastpow(int base, int p)
{
    int a = 1, b = base;
    while (p > 0)
    {
        if (p & 1)
            a = a * b % MOD;
        b = b * b % MOD;
        p >>= 1;
    }
    return a;
}

void Modify(int l, int r, int i, int pos, int val)
{
    //cout << "Modify " << l << " " << pos << " " << val << '\n';
    seg[i] = seg[i] * val % MOD;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    if (pos <= mid)
        Modify(l, mid, i * 2, pos, val);
    else
        Modify(mid + 1, r, i * 2 + 1, pos, val);
}

int Query(int l, int r, int i, int a, int b)
{
    if (a <= l && r <= b)
        return seg[i];
    else if (b < l || r < a)
        return 1;
    else
    {
        int mid = (l + r) / 2;
        return Query(l, mid, i * 2, a, b) * Query(mid + 1, r, i * 2 + 1, a, b) % MOD;
    }
}

signed main()
{
    fast;
    for (int i = 2; i <= 1000000; i += 2)
        sieve[i] = 2;
    prime[2] = 1;
    for (int i = 3; i <= 1000000; i += 2)
        if (sieve[i] == 0)
        {
            sieve[i] = i;
            prime[i] = ++idx;
            for (int j = i * i; j <= 1000000; j += i)
                sieve[j] = i;
        }

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        query.emplace_back(Q{i, l, r});
    }
    for (int i = 1; i < 4000000; i++)
        seg[i] = 1;

    sort(query.begin(), query.end(), [](Q q1, Q q2) { return q1.r < q2.r; });
    idx = 0;

    for (int i = 1; i <= n; i++)
    {
        while (arr[i] > 1)
        {
            int base = sieve[arr[i]], p = 0;
            while (arr[i] % base == 0)
                arr[i] /= base, p++;
            while (!mq[prime[base]].empty() && p >= mq[prime[base]].back().S)
            {
                pii last = mq[prime[base]].back();
                Modify(1, 1000000, 1, last.F, fastpow(base, last.S * (MOD - 2) % (MOD - 1)));
                mq[prime[base]].pop_back();

                if (!mq[prime[base]].empty())
                    Modify(1, 1000000, 1, mq[prime[base]].back().F, fastpow(base, last.S));
            }
            int res = fastpow(base, p);
            Modify(1, 1000000, 1, i, res);
            if (!mq[prime[base]].empty())
                Modify(1, 1000000, 1, mq[prime[base]].back().F, fastpow(res, MOD - 2));
            mq[prime[base]].emplace_back(make_pair(i, p));
        }
        while (idx < q && query[idx].r == i)
        {
            ans[query[idx].i] = Query(1, 1000000, 1, query[idx].l, query[idx].r);
            idx++;
        }
        if (idx > q - 1)
            break;
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}

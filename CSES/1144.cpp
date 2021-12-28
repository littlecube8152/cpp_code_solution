/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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

int n, q;
ll bit[600005], arr[200005];
vector<pair<char, pii>> queries;

void modify(int pos, ll v)
{
    for (int i = pos; i <= n; i += (i & -i))
        bit[i] += v;
}

ll query(int pos)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

void init()
{
    for (int i = 1; i <= n; i++)
        if (i + (i & -i) <= n)
            bit[i + (i & -i)] += bit[i];
}

signed main()
{
    fast;
    cin >> n >> q;
    vector<int> disc;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        disc.emplace_back(arr[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == '?')
            disc.emplace_back(a);
        disc.emplace_back(b);

        queries.emplace_back(pair<char, pii>{c, {a, b}});
    }
    sort(disc.begin(), disc.end());
    disc.resize(unique(disc.begin(), disc.end()) - disc.begin());
    for (int i = 1; i <= n; i++)
        arr[i] = lower_bound(disc.begin(), disc.end(), arr[i]) - disc.begin() + 1;
    for (int i = 0; i < q; i++)
    {
        queries[i].S.S = lower_bound(disc.begin(), disc.end(), queries[i].S.S) - disc.begin() + 1;
        if (queries[i].F == '?')
            queries[i].S.F = lower_bound(disc.begin(), disc.end(), queries[i].S.F) - disc.begin() + 1;
    }
    for (int i = 1; i <= n; i++)
        bit[arr[i]]++;
    n = (n + 2 * q);
    init();
    for (int i = 0; i < q; i++)
    {
        char type = queries[i].F;
        if (type == '!')
        {
            int k = queries[i].S.F, x = queries[i].S.S;
            modify(x, 1);
            modify(arr[k], -1);
            arr[k] = x;
        }
        else if (type == '?')
        {
            int a = queries[i].S.F, b = queries[i].S.S;
            cout << query(b) - query(a - 1) << '\n';
        }
    }
}

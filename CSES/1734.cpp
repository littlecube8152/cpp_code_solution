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
ll bit[200005], arr[200005], ans[200005], last[200005], qdx = 0;
vector<pair<pii, int>> queries;

void modify(int pos, ll v)
{
    for (int i = pos; 0 < i && i <= n; i += (i & -i))
        bit[i] += v;
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
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<int> disc;
    for (int i = 1; i <= n; i++)
        disc.emplace_back(arr[i]);
    sort(disc.begin(), disc.end());
    disc.resize(unique(disc.begin(), disc.end()) - disc.begin());
    for (int i = 1; i <= n; i++)
        arr[i] = lower_bound(disc.begin(), disc.end(), arr[i]) - disc.begin() + 1;

    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        queries.emplace_back(pair<pii, int>{{a, b}, i});
    }

    sort(queries.begin(), queries.end(), less<pair<pii, int>>());
    qdx = queries.size() - 1;
    for (int i = n; i >= 1; i--)
    {
        modify(i, 1);
        if(last[arr[i]] > 0)
            modify(last[arr[i]], -1);
        last[arr[i]] = i;
        while(qdx >= 0 && queries[qdx].F.F >= i)
        {
            ans[queries[qdx].S] = query(queries[qdx].F.S);
            qdx--;
        }
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}

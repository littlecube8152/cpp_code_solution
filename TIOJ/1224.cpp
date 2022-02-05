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

int n, m, seg[400000], lazy[400000];
ll ans;
vector<int> t;
vector<int> pos;
vector<pair<int, pii>> add;
vector<pair<int, pii>> rem;

void push(int l, int r, int i)
{
    if (lazy[i] > 0)
    {
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
        lazy[i] = 0;
        seg[i] = (pos[r] - pos[l]);
    }
}

void pull(int l, int r, int i)
{
    int mid = (l + r) / 2;
    if (lazy[i] > 0)
        seg[i] = (pos[r] - pos[l]);
    else
        seg[i] = (lazy[i * 2] > 0 ? (pos[mid] - pos[l]) : seg[i * 2]) + (lazy[i * 2 + 1] > 0 ? (pos[r] - pos[mid]) : seg[i * 2 + 1]);
}

void modify(int l, int r, int i, int a, int b, int val)
{

    if (l == r)
        return;
    if (b <= l || r <= a)
        return;
    //cout << "Modify " << l << " " << r << " " << a << " " << b << " " << val << " " << '\n';
    //cout << "   On " << i << " seg " << seg[i] << " " << lazy[i] << '\n';
    if (a <= l && r <= b)
        lazy[i] += val;
    else
    {
        int mid = (l + r) / 2;
        modify(l, mid, i * 2, a, b, val);
        modify(mid, r, i * 2 + 1, a, b, val);
    }
    pull(l, r, i);
}

signed main()
{
    fast;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        t.pb(d);
        t.pb(u);
        pos.pb(l);
        pos.pb(r);
        add.pb(make_pair(d, pii{l, r}));
        rem.pb(make_pair(u, pii{l, r}));
    }
    t.pb(-1);
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
    sort(pos.begin(), pos.end());
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
    sort(add.begin(), add.end(), greater<pair<int, pii>>());
    sort(rem.begin(), rem.end(), greater<pair<int, pii>>());
    for (int i = 1; i < t.size(); i++)
    {
        pull(0, pos.size() - 1, 1);
        ans += (ll)(t[i] - t[i - 1]) * seg[1];
        //cout << t[i] << " - " << seg[1] << '\n';
        while (!add.empty() && add.back().F == t[i])
        {
            int L = lower_bound(pos.begin(), pos.end(), add.back().S.F) - pos.begin(),
                R = lower_bound(pos.begin(), pos.end(), add.back().S.S) - pos.begin();
            modify(0, pos.size() - 1, 1, L, R, 1);
            add.pop_back();
        }
        while (!rem.empty() && rem.back().F == t[i])
        {
            int L = lower_bound(pos.begin(), pos.end(), rem.back().S.F) - pos.begin(),
                R = lower_bound(pos.begin(), pos.end(), rem.back().S.S) - pos.begin();
            modify(0, pos.size() - 1, 1, L, R, -1);
            rem.pop_back();
        }
    }
    cout << ans << '\n';
}

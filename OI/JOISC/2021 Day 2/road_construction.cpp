#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, bit[750005];
pll p[250005], pp[250005];

void modify(int pos, int val)
{
    for (int i = pos; i <= 3 * N; i += (i & -i))
        bit[i] += val;
}

ll query(int pos)
{
    ll val = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        val += bit[i];
    return val;
}

ll calc(ll L)
{
    vector<tuple<ll, int, int, int>> v;
    vector<ll> vy;
    v.reserve(3 * N);
    vy.reserve(3 * N + 1);
    ll res = 0;
    for (int i = 1; i <= N; i++)
    {
        vy.emplace_back(pp[i].S - L);
        vy.emplace_back(pp[i].S);
        vy.emplace_back(pp[i].S + L);
    }
    vy.emplace_back(-1e12);
    sort(vy.begin(), vy.end());
    vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
    
    for (int i = 1; i <= N; i++)
    {
        ll x = pp[i].F, y = pp[i].S, 
        l = lower_bound(vy.begin(), vy.end(), y - L) - vy.begin(),
        m = lower_bound(vy.begin(), vy.end(), y) - vy.begin(),
        r = lower_bound(vy.begin(), vy.end(), y + L) - vy.begin();
        
        v.emplace_back(make_tuple(x - L, -1, m, 0));
        v.emplace_back(make_tuple(x, 0, l, r));
        v.emplace_back(make_tuple(x + L, 1, m, 0));
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= 3 * N; i++)
        bit[i] = 0;
    for (auto [x, t, l, r] : v)
    {
        if (t == -1)
            modify(l, 1);
        else if (t == 1)
            modify(l, -1);
        else if (t == 0)
            res += query(r) - query(l - 1) - 1;
        
    }
    return res / 2;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> p[i].F >> p[i].S;
    for (int i = 1; i <= N; i++)
        pp[i] = pll(p[i].F + p[i].S, p[i].F - p[i].S);

    ll L = 1, R = 4'000'000'000;
    while (L < R)
    {
        ll mid = (L + R) / 2;
        if (calc(mid) < K)
            L = mid + 1;
        else
            R = mid;
    }
    L--;

    vector<tuple<ll, int, ll, ll>> v;
    vector<ll> ans;
    set<pll> st;

    for (int i = 1; i <= N; i++)
    {
        ll x = p[i].F + p[i].S, y = p[i].F - p[i].S;
        v.emplace_back(make_tuple(x - L, -i, y, 0));
        v.emplace_back(make_tuple(x, i, y - L, y + L));
        v.emplace_back(make_tuple(x + L, i + N, y, 0));
    }
    sort(v.begin(), v.end());
    for (auto [x, t, l, r] : v)
    {
        if (t < 0)
            st.insert(pll(l, -t));
        else if (t > N)
            st.erase(pll(l, t - N));
        else
        {
            auto lter = st.lower_bound(pll(l, 0)), rter = st.upper_bound(pll(r, N + 1));

            while (lter != rter)
            {
                ll i = lter->S;
                if (i < t)
                    ans.emplace_back(abs(p[t].F - p[i].F) + abs(p[t].S - p[i].S));
                ++lter;
            }
        }
    }
    sort(ans.begin(), ans.end());
    while (ans.size() < K)
        ans.emplace_back(R);
    for (ll i : ans)
        cout << i << '\n';
}
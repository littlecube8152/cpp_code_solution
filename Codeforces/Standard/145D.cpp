/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, m, a[100005], b[1005], c[1005], p[1005], s[100005];
ll ans;
vector<ll> v[1005];
map<ll, ll> mp;

bool luck(ll t)
{
    bool luck = 1;
    while (t)
    {
        luck &= (t % 10 == 4 || t % 10 == 7);
        t /= 10;
    }
    return luck;
}

signed main()
{
    fast;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        s[i] = s[i - 1] + i * (i + 1) / 2;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (luck(a[i]))
        {
            m++;
            if (mp[a[i]] == 0)
                mp[a[i]] = m;
            b[m] = mp[a[i]];
            p[m] = i;
            v[b[m]].emplace_back(i);
        }
        else
            c[m]++;
    }
    for (ll i = 1; i <= m; i++)
    {
        ll sum = n * (n + 1) / 2;
        set<ll> st;
        st.insert(0);
        st.insert(n + 1);
        for (ll j = i; j <= m; j++)
        {
            auto iter = st.find(p[j]);
            if (iter != st.end())
            {
                sum -= (*iter - *prev(iter) - 1) * (*iter - *prev(iter)) / 2;
                sum -= (*next(iter) - *iter - 1) * (*next(iter) - *iter) / 2;
                sum += (*next(iter) - *prev(iter) - 1) * (*next(iter) - *prev(iter)) / 2;
                st.erase(iter);
            }
            else
            {
                for (auto k : v[b[j]])
                    if (k > p[j])
                    {
                        auto iter = st.insert(k).F;
                        sum += (*iter - *prev(iter) - 1) * (*iter - *prev(iter)) / 2;
                        sum += (*next(iter) - *iter - 1) * (*next(iter) - *iter) / 2;
                        sum -= (*next(iter) - *prev(iter) - 1) * (*next(iter) - *prev(iter)) / 2;
                    }
            }
            iter = st.begin();
            // cerr << i << ' ' << j << ' ' << (c[i - 1] + 1) * (c[j] + 1) * (sum - (*next(iter) - *iter - 1) * (*next(iter) - *iter) / 2) + (c[i - 1] + 1) * (s[*next(iter) - p[j] - 1] - s[*next(iter) - p[j] - c[j] - 2]) << '\n';
            ans += (c[i - 1] + 1) * (c[j] + 1) * (sum - (*next(iter) - *iter - 1) * (*next(iter) - *iter) / 2);
            ll l = *next(iter) - p[j] - 1, r = max(0LL, *next(iter) - p[j] - c[j] - 2);
            ans += (c[i - 1] + 1) * (s[l] - s[r]);
        }
    }
    ll i = 0;
    for (ll j = 1; j < n; j++)
        if (luck(a[j]))
            i = j;
        else
            ans += (j - i) * (n - j) * (n - j + 1) / 2;
        
    cout << ans << '\n';
}

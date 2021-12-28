#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
 
ll n, k, ans1, ans2 = 1e18;
vector<int> v, v2;
vector<pii> u;
 
signed main()
{
    clock_t t = clock();
    fast;
    cin >> k >> n;
    for (int i = 1; i <= n; i++)
    {
        char c1, c2;
        int p1, p2;
        cin >> c1 >> p1 >> c2 >> p2;
        if (c1 == c2)
            ans1 += abs(p1 - p2);
        else
        {
            v.emplace_back(p1);
            v.emplace_back(p2);
            u.emplace_back(make_pair(p1, p2));
        }
    }
    sort(v.begin(), v.end());
 
    ans2 = v.size() / 2;
    if (!v.empty())
    {
        int mid = v[v.size() / 2];
        for (int i : v)
            ans2 += abs(mid - i);
    }
    if (k == 1)
        cout << ans2 + ans1 << '\n';
    else
    {
        unique(v.begin(), v.end());
        random_shuffle(v.begin(), v.end());
        v2 = v;
        random_shuffle(v2.begin(), v2.end());
        for (int i : v)
            for (int j : v2)
                if (i != j)
                {
                    ll res = 0;
                    for (pii p : u)
                        res += min(abs(p.F - i) + abs(p.S - i) + 1, abs(p.F - j) + abs(p.S - j) + 1);
                    ans2 = min(ans2, res);
                    if (clock() - t > CLOCKS_PER_SEC * 1.95)
                    {
                        cout << ans1 + ans2 << '\n';
                        break;
                    }
                }
        cout << ans1 + ans2 << '\n';
    }
}
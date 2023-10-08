#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int n, a[100005], bit[100005];
vector<int> p[100005];

void modify(int pos, int val)
{
    for (int i = pos; i <= n; i += (i & -i))
        bit[i] += val;
}

int query(int pos)
{
    int ans = 0;
    for (int i = pos; i; i -= (i & -i))
        ans += bit[i];
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        modify(i, 1);
        p[a[i]].emplace_back(i);
    }
    int r = n;
    for (int c = 1; c <= 100'000; c++)
        if (!p[c].empty())
        {
            int k = p[c].size();
            vector<int> pos;
            for (int i : p[c])
                pos.emplace_back(query(i));
            sort(pos.begin(), pos.end());
            vector<ll> psum(k + 1), ssum(k + 1);
            ll res = 1e18;
            for (int i = 0; i < k; i++)
                psum[i + 1] = psum[i] + (pos[i] - 1);
            for (int i = k - 1; i >= 0; i--)
                ssum[i] = ssum[i + 1] + (r - pos[i]);
            for (ll i = 0; i <= k; i++)
                res = min(res, psum[i] - i * (i - 1) / 2 + ssum[i] - (k - i) * (k - i - 1) / 2);
            ans += res;
            for (int i : p[c])
                modify(i, -1), r--;
        }
    cout << ans << '\n';
}
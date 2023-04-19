#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll n, q, bit[100005], arr[100005], totk, cura = 0, order[100005], pref[100005];
pii sorted[100005];
vector<int> front;
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + arr[i];
    for (int i = 1; i <= n; i++)
        sorted[i] = {arr[i], i};
    sort(sorted + 1, sorted + 1 + n);
    for (int i = 1; i <= n; i++)
        order[sorted[i].S] = i;
    for (int i = 1; i <= arr[1]; i++)
        front.emplace_back(i);
    for (int i = 1; i <= q; i++)
    {

        ll t, k;
        cin >> t >> k;
        if (t == 1)
        {
            int idx = lower_bound(pref + 1, pref + n + 1, totk + k) - pref;
            
            ll offset = 0, fixed = pref[idx - 1], cur = arr[idx];
            for (int i = order[idx]; i > 0; i -= (i & -i))
                offset += bit[i];
            ll pos = (((totk + k - fixed) - 1 - offset) % cur + cur) % cur;

            cout << fixed + pos + 1 << '\n';
        }
        else
        {
            totk += pref[cura + k] - pref[cura];
            int idx = lower_bound(sorted + 1, sorted + n + 1, pii{pref[cura + k] - pref[cura], n + 1}) - sorted;
            for (int i = idx; i <= n; i += (i & -i))
                bit[i] += pref[cura + k] - pref[cura];
            cura += k;
        }
    }
}
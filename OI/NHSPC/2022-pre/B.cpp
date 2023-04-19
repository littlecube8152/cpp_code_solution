#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, k[100005], l[100005], mid[100005], r[100005], ans = -1e18, sum;
vector<ll> v[100005];
vector<int> stl;

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> k[i];
        v[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++)
        {
            cin >> v[i][j];
            mid[i] += v[i][j];
            ans = max(ans, v[i][j]);
        }
        for (ll cur = 0, j = 0; j < k[i]; j++)
        {
            cur = max(0LL, cur + v[i][j]);
            if(cur > 0)
                ans = max(ans, cur);
        }
        for (ll cur = 0, j = 0; j < k[i]; j++)
        {
            cur += v[i][j];
            l[i] = max(l[i], cur);
        }
        for (ll cur = 0, j = k[i] - 1; j >= 0; j--)
        {
            cur += v[i][j];
            r[i] = max(r[i], cur);
        }
        mid[i] = max(mid[i], 0LL);
        sum += mid[i];
        stl.emplace_back(i);
    }
    sort(stl.begin(), stl.end(), [&](int i, int j)
         { return l[i] - mid[i] > l[j] - mid[j]; });
    for (int i = 1; i <= N; i++)
    {
        sum -= mid[i];
        sum += r[i];
        for(auto j : stl)
            if(i != j)
            {
                ll cur = sum - mid[j] + l[j];
                if(cur > 0)
                    ans = max(ans, cur);
                break;
            }

        sum += mid[i];
        sum -= r[i];
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q;
ll x[200005], w[200005], pM[200005], pm[200005], ans[200005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> x[i];
    for (int i = 1; i <= Q; i++)
    {
        cin >> w[i];
        w[i] += w[i - 1];
        pM[i] = max(pM[i - 1], w[i]);
        pm[i] = min(pm[i - 1], w[i]);
    }
    for (int i = 1; i < N; i++)
    {
        int L = 1, R = Q + 1;
        while (L < R)
        {
            int mid = (L + R) / 2;
            if (pM[mid] - pm[mid] >= x[i + 1] - x[i])
                R = mid;
            else
                L = mid + 1;
        }
        ans[i] += pM[L - 1], ans[i + 1] += -pm[L - 1];
        if (L <= Q)
        {
            if (pm[L] < pm[L - 1])
                ans[i + 1] += x[i + 1] - x[i] - (pM[L - 1] - pm[L - 1]);
            else
                ans[i] += x[i + 1] - x[i] - (pM[L - 1] - pm[L - 1]);
        }
    }
    ans[1] += -pm[Q];
    ans[N] += pM[Q];
    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
}
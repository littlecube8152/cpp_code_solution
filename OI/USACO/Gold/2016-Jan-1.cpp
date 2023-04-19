#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
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

int n, mdp[50005];
double ans = 1e9;
vector<int> v, ldp, rdp;

signed main()
{
    fast;
    ifstream cin("angry.in");
    ofstream cout("angry.out");
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    ldp.resize(n + 1);
    ldp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int L = 1, R = i - 1;
        while (R - L > 1)
        {
            int mid = (L + R) / 2;
            if (ldp[mid] + 1 <= v[i] - v[mid])
                L = mid;
            else
                R = mid;
        }
        ldp[i] = min(max(ldp[L] + 1, v[i] - v[L]), max(ldp[R] + 1, v[i] - v[R]));
    }

    rdp.resize(n + 1);
    rdp[n] = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        int L = i + 1, R = n;
        while (R - L > 3)
        {
            int mid = (L + R) / 2;
            if (rdp[mid] + 1 <= v[mid] - v[i])
                R = mid;
            else
                L = mid;
        }
        rdp[i] = 1e9;
        for (int j = L; j <= R; j++)
            rdp[i] = min(max(rdp[j] + 1, v[j] - v[i]), rdp[i]);
    }
    for (int i = 2; i <= n; i++)
    {
        int L = 1, R = i - 1;
        while (R - L > 3)
        {
            int mid = (L + R) / 2;
            if (ldp[mid] <= (v[i] - v[mid]) / 2.0)
                L = mid;
            else
                R = mid;
        }
        for (int j = L; j <= R; j++)
            ans = min(ans, max({rdp[i] * 1.0 + 1, ldp[j] * 1.0 + 1, (v[i] - v[j]) / 2.0}));
    }

    cout << fixed << setprecision(1) << ans << '\n';
}
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
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    unique(v.begin(), v.end());

    ldp.resize(v.size());
    ldp[0] = 0;
    for (int i = 1; i < v.size(); i++)
        ldp[i] = max(ldp[i - 1] + 1, v[i] - v[i - 1]);

    reverse(v.begin(), v.end());

    rdp.resize(v.size());
    rdp[0] = 0;
    for (int i = 1; i < v.size(); i++)
        rdp[i] = max(rdp[i - 1] + 1, v[i - 1] - v[i]);

    reverse(v.begin(), v.end());
    reverse(rdp.begin(), rdp.end());

    for (int i = 1; i < v.size(); i++)
        ans = min(ans, max({ldp[i - 1] + 1.0, rdp[i] + 1.0, (v[i] - v[i - 1]) / 2.0}));
    cout << fixed << setprecision(1) << ans << '\n';
}
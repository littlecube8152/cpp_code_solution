//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<vector<ll>> mtx(50, vector<ll>(50, 0));
ll n, k;

vector<vector<ll>> fpow(ll k)
{
    if (k == 1)
        return mtx;

    if (k % 2)
    {
        vector<vector<ll>> mtx1 = fpow(k - 1), res(50, vector<ll>(50, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int l = 0; l < n; l++)
                    res[i][j] = (res[i][j] + mtx[i][l] * mtx1[l][j]) % MOD;
        return res;
    }
    vector<vector<ll>> mtx1 = fpow(k / 2), res(50, vector<ll>(50, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int l = 0; l < n; l++)
                res[i][j] = (res[i][j] + mtx1[i][l] * mtx1[l][j]) % MOD;
    return res;
}

signed main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mtx[i][j];
    vector<vector<ll>> res = fpow(k);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = (ans + res[i][j]) % MOD;
    cout << ans << '\n';
}
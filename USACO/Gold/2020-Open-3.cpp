#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> p = {2};
int n, m, dsu[100005], rk[100005], pw[500], res = 1;

int find(int k)
{
    while (k != dsu[k])
        k = dsu[k];
    return k;
}

ll fpow(int b, int p, int m)
{
    ll a = 1, k = b;
    while (p)
    {
        if (p & 1)
            a = a * k % m;
        k = k * k % m;
        p >>= 1;
    }
    return a;
}
signed main()
{
    fast;
    //ifstream cin("poetry.in");
    //ofstream cout("poetry.out");
    cin >> n >> m;
    for (int i = 3; i <= n; i += 2)
        for (int j : p)
        {
            if (j > sqrt(i))
            {
                p.emplace_back(i);
                break;
            }
            if (i % j == 0)
                break;
        }
    for (int j : p)
        cout << j << " ";
    for (int i = 1; i <= n; i++)
        dsu[i] = i, rk[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        int x, rx, ri;
        cin >> x;
        rx = find(x), ri = find(i);
        if (rx != ri)
        {
            if (rk[rx] > rk[ri])
                dsu[ri] = rx, dsu[x] = rx, rk[rx] += rk[ri];
            else
                dsu[rx] = ri, dsu[i] = ri, rk[ri] += rk[rx];
        }
    }
    for (int i = 1; i <= n; i++)
        if (i == dsu[i])
            for (int j = 0; j < p.size(); j++)
            {
                int cnt = 0;
                while (rk[i] > 1 && rk[i] % p[j] == 0)
                    rk[i] /= p[j], cnt++;
                pw[j] = max(pw[j], cnt);
            }
    for (int i = 0; i < p.size(); i++)
        res = res * fpow(p[i], pw[i], m) % MOD;
    cout << res << '\n';
}
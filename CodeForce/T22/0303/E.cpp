#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int gcd(ll  a, ll b)
{
    if (a * b == 0)
        return a + b;
    return gcd(b % a, a);
}

int n, m, a[5005], r, bp[5005], modify, g[5005];
vector<int> p = {2};
signed main()
{
    fast;
    for (int i = 3; i < 50000; i += 2)
    {
        bool b = 1;
        int sq = ceil(sqrt(i));
        for (int j : p)
            if (j > sq)
                break;
            else if (!(i % j))
            {
                b = 0;
                break;
            }
        if (b)
            p.emplace_back(i);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> bp[i];
    
    for (int i = 1; i <= n; i++)
    {
        int k = a[i];
        for (int j = 1; j <= m; j++)
            if (bp[j] > k)
                continue;
            else
                while (k % bp[j] == 0)
                    k /= bp[j], r--;
        for (int j : p)
            if (j > k)
               continue;
            else
                while (k % j == 0)
                    k /= j, r++;
        if (k > 1)
            r++;
    }
    for (int i = 1; i <= n; i++)
        g[i] = gcd(a[i], g[i - 1]);

    for (int i = n; i >= 1; i--)
    {
        int k = g[i], mdf = 0;
        for (int j = 1; j <= m; j++)
            if (bp[j] > k)
                continue;
            else
                while (k % bp[j] == 0)
                    k /= bp[j], mdf++;
        for (int j : p)
            if (j > k)
                continue;
            else
                while (k % j == 0)
                    k /= j, mdf--;
        if (k > 1)
            mdf--;
        if (mdf > 0)
        {
            for (int j = 1; j < i; j++)
                g[j] /= g[i];
            //cout << "MDF " << mdf << " " << i << '\n';
            modify += mdf * i;
        }
    }
    cout << r + modify;
}
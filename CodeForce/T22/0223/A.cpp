#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;
pll p[200005];
bool isb[200005];
ll n, a, b, maxi, maxdiff, sum, mdf, lasti = -1;

int main()
{
    cin >> n >> a >> b;
    a = 1LL << a;
    for (int i = 0; i < n; i++)
        cin >> p[i].F >> p[i].S;

    sort(p, p + n, [](pll p1, pll p2) { return p1.F - p1.S > p2.F - p2.S; });
    for (int i = 0; i < min(n, b); i++)
        if (p[i].F - p[i].S > 0)
        {
            isb[i] = 1;
            lasti = i;
        }

    for (int i = 0; i < n; i++)
        if (isb[i])
            sum += p[i].F;
        else
            sum += p[i].S;

    if (b == 0)
    {
        cout << sum;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (isb[i])
            mdf = max(-p[i].F + p[i].F * a, mdf);
        else if (b - lasti - 1 > 0)
            mdf = max(-p[i].S + p[i].F * a, mdf);
        else
            mdf = max(-p[i].S + p[i].F * a - p[lasti].F + p[lasti].S, mdf);
    }
    cout << sum + mdf;
}
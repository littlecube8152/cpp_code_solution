#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

int n;
pdd arr[105], user;

double dis(pdd p1, pdd p2)
{
    return sqrtl((p1.F - p2.F) * (p1.F - p2.F) + (p1.S - p2.S) * (p1.S - p2.S));
}

double bs(double l, double r, int id)
{
    
    double lmid = (2.0 * l + r) / 3.0, rmid = (l + 2.0 * r) / 3.0;
    pdd lp = pdd{lmid * arr[id].F + (1.0 - lmid) * arr[id + 1].F, lmid * arr[id].S + (1.0 - lmid) * arr[id + 1].S},
        rp = pdd{rmid * arr[id].F + (1.0 - rmid) * arr[id + 1].F, rmid * arr[id].S + (1.0 - rmid) * arr[id + 1].S};
    double lans = dis(lp, user), rans = dis(rp, user);
    if (abs(l - r) < 1e-8)
        return lans;
    if (lans < rans)
        return bs(l, rmid, id);
    else
        return bs(lmid, r, id);
}

signed main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    cin >> user.F >> user.S;
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> arr[i].F >> arr[i].S;
    double ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, bs(0, 1, i));
    }
    cout << fixed << setprecision(9) << ans << '\n';
}
/*
2 1 5
1 3
3 3
5 1
7 2
7 4
9 3*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, a[1000005], b[1000005], ans = 1e18;

ll solve(ll L, ll R, ll p)
{
    if (R - L + 1 >= (1LL << p))
        return R / (1LL << p);
    if ((R & ((1LL << p) - 1LL)) < (L & ((1LL << p) - 1LL)))
        return min(solve(L, L | ((1LL << p) - 1LL), p), solve((R & ~((1LL << p) - 1LL)), R, p));
    //cout << "solve" << L << " " << R << " " << p << '\n';
    ll bitL = L & ((1LL << p) - 1LL),
       bitR = R & ((1LL << p) - 1LL);
    //cout << "     " << bitL << " " << bitR << " = ";
    ll cur = 0, ans = 1e18;
    for (ll b = p - 1; b >= 0; b--)
    {
        if (((bitL >> b) & 1LL) && ((bitR >> b) & 1LL))
            cur++;
        else if (((bitL >> b) & 1LL) == 0 && ((bitR >> b) & 1LL))
        {
            ans = min(ans, cur + 1);
            bitR = (bitR ^ (1LL << b)) | ((1LL << b) - 1);
        }
    }
    ans = min(ans, cur);
    //cout << ans << ' ' << ans + R / (1LL << p) << '\n';
    return ans + R / (1LL << p);
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        cin >> b[i];
    for (ll p = 0; p <= 31; p++)
    {
        ll L = 0, R = 8e18;
        for (int i = 1; i <= N; i++)
        {
            L = max(L, (b[i] << p) - a[i]);
            R = min(R, ((b[i] << p) ^ ((1LL << p) - 1LL)) - a[i]);
        }
        if (R < L)
            continue;
        ll mid = ((L - 1) / (1LL << p) + 1) * (1LL << p), res;

        if (mid > R || mid - 1 < L)
            res = solve(L, R, p) + p;
        else
            res = min(solve(L, mid - 1, p), solve(mid, R, p)) + p;
        ans = min(ans, res);
    }
    if (ans >= 1e17)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

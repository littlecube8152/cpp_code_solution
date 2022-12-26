#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N;
ll a[200005], ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    int ldx = 1, rdx = N;
    while (rdx - ldx > 0)
    {
        //for (int i = 1; i <= N; i++)
        //    cout << a[i] << " \n"[i == N];
        //cout << ldx << " " << rdx << " " << ans << '\n';
        ll l = a[ldx - 1] - a[ldx] + 1, r = a[rdx + 1] - a[rdx] + 1;

        if (l <= r)
        {
            ans += max(l, 0LL);
            a[ldx - 1] -= max(l, 0LL);
            a[rdx + 1] -= max(l, 0LL);
            ldx++;
        }
        else
        {
            ans += max(r, 0LL);
            a[ldx - 1] -= max(r, 0LL);
            a[rdx + 1] -= max(r, 0LL);
            rdx--;
        }
    }
    if ((a[ldx] < a[ldx - 1] && a[ldx] < a[ldx + 1]) || a[ldx] == min(a[ldx - 1], a[ldx + 1]))
    {
        if (abs(a[ldx - 1] - a[ldx + 1]) == 1)
            ans += max(a[ldx - 1], a[ldx + 1]) - a[ldx] + 1;
        else
            ans += min(a[ldx - 1], a[ldx + 1]) - a[ldx] + 1;
    }
    else if (a[ldx] == max(a[ldx - 1], a[ldx + 1]))
        ans++;
    cout << ans << '\n';
}
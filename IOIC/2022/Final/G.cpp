#include <bits/stdc++.h>
#define ll long long
using namespace std;

int Q;
ll aseg[2000005], bseg[2000005];

void modify(ll a, ll b, ll i = 1, ll L = 1, ll R = 1e6)
{
    ll mid = (L + R) / 2;
    if (aseg[i] * mid + bseg[i] < a * mid + b)
    {
        swap(a, aseg[i]);
        swap(b, bseg[i]);
    }
    if (L != R)
    {
        if (a >= aseg[i])
            modify(a, b, i + 2 * (mid - L + 1), mid + 1, R);
        else
            modify(a, b, i + 1, L, mid);
    }
}

ll query(ll x, ll i = 1, ll L = 1, ll R = 1e6)
{
    ll mid = (L + R) / 2;
    if (L != R)
    {
        if (x <= mid)
            return max(aseg[i] * x + bseg[i], query(x, i + 1, L, mid));
        else
            return max(aseg[i] * x + bseg[i], query(x, i + 2 * (mid - L + 1), mid + 1, R));
    }
    return aseg[i] * x + bseg[i];
}

int main()
{
    cin >> Q;
    while (Q--)
    {
        int t, a, b;
        cin >> t >> a;
        if (t == 0)
        {
            cin >> b;
            modify(a, b);
        }
        else
        {
            ll res = query(a);
            if (res <= 0)
                cout << "empty\n";
            else
                cout << res << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;

ll N, Q, one[400005], two[400005], lazy[400005];

ll getone(int i, ll L, ll R)
{
    // sum (x + k)^2 = sum x^2 + 2 * x * k + k^2
    return (one[i] + ((R - L + 1LL) * lazy[i] % mod)) % mod;
}

ll gettwo(int i, ll L, ll R)
{
    // sum (x + k)^2 = sum x^2 + 2 * x * k + k^2
    return (two[i] + ((2LL * one[i] % mod) * lazy[i] % mod) + (((R - L + 1LL) * lazy[i] % mod) * lazy[i] % mod)) % mod;
}

void push(int i, ll L, ll R)
{
    int mid = (L + R) / 2;
    two[i] = gettwo(i, L, R);
    one[i] = (one[i] + lazy[i]) % mod;
    lazy[i + 1] = (lazy[i + 1] + lazy[i]) % mod;
    lazy[i + 2 * (mid - L + 1)] = (lazy[i + 2 * (mid - L + 1)] + lazy[i]) % mod;
    lazy[i] = 0;
}

void pull(int i, ll L, ll R)
{
    int mid = (L + R) / 2;
    one[i] = (getone(i + 1, L, mid) + getone(i + 2 * (mid - L + 1), mid + 1, R)) % mod;
    two[i] = (gettwo(i + 1, L, mid) + gettwo(i + 2 * (mid - L + 1), mid + 1, R)) % mod;
}

void modify(int mL, int mR, ll val, int i = 1, ll L = 1, ll R = N)
{
    if (mL <= L && R <= mR)
        lazy[i] = (lazy[i] + val) % mod;
    else if (R < mL || mR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        push(i, L, R);
        modify(mL, mR, val, i + 1, L, mid);
        modify(mL, mR, val, i + 2 * (mid - L + 1), mid + 1, R);
        pull(i, L, R);
    }
}

ll query(int qL, int qR, int i = 1, ll L = 1, ll R = N)
{
    if (qL <= L && R <= qR)
        return gettwo(i, L, R);
    else if (R < qL || qR < L)
        return 0;
    else
    {
        int mid = (L + R) / 2;
        push(i, L, R);
        ll ans = (query(qL, qR, i + 1, L, mid) + query(qL, qR, i + 2 * (mid - L + 1), mid + 1, R)) % mod;
        pull(i, L, R);
        return ans;
    }
}

int main()
{
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        ll a;
        cin >> a;
        modify(i, i, a);
    }
    for (int i = 1; i <= Q; i++)
    {
        ll t, l, r, x;
        cin >> t >> l >> r;
        if (t == 1)
        {
            cin >> x;
            modify(l, r, x);
        }
        else
            cout << query(l, r) << '\n';
    }
}

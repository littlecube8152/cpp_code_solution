/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;
const int C = 5e5;
ll N, Q, sum[1000200], mx[1000200], lazy[1000200];
bool iscover[1000200];
ll ans;

ll getsum(int i, ll L, ll R)
{
    return (iscover[i] ? 0 : sum[i]) + (R - L + 1) * lazy[i];
}

ll getmx(int i)
{
    return (iscover[i] ? lazy[i] : lazy[i] + mx[i]);
}

void push(int i, int L, int R)
{
    int mid = (L + R) / 2;
    if (iscover[i])
    {
        sum[i] = mx[i] = lazy[i + 1] = lazy[i + 2 * (mid - L + 1)] = 0,
        iscover[i + 1] = iscover[i + 2 * (mid - L + 1)] = 1;
        iscover[i] = 0;
    }
    lazy[i + 1] += lazy[i];
    lazy[i + 2 * (mid - L + 1)] += lazy[i];
    sum[i] += lazy[i] * (R - L + 1);
    mx[i] += lazy[i];
    lazy[i] = 0;
}

void modify(int mL, int mR, int val, int i = 1, ll L = 1, ll R = C)
{
    int mid = (L + R) / 2;
    if (R < mL || mR < L)
        return;
    if (mL <= L && R <= mR)
        lazy[i] += val;
    else
    {
        push(i, L, R);
        modify(mL, mR, val, i + 1, L, mid);
        modify(mL, mR, val, i + 2 * (mid - L + 1), mid + 1, R);
        sum[i] = getsum(i + 1, L, mid) + getsum(i + 2 * (mid - L + 1), mid + 1, R);
        mx[i] = max(getmx(i + 1), getmx(i + 2 * (mid - L + 1)));
    }
}

void modify2(int mL, int mR, int val, int i = 1, ll L = 1, ll R = C)
{
    int mid = (L + R) / 2;
    if (R < mL || mR < L)
        return;
    if (mL <= L && R <= mR)
    {
        iscover[i] = 1;
        lazy[i] = val;
    }
    else
    {
        push(i, L, R);
        modify2(mL, mR, val, i + 1, L, mid);
        modify2(mL, mR, val, i + 2 * (mid - L + 1), mid + 1, R);
        sum[i] = getsum(i + 1, L, mid) + getsum(i + 2 * (mid - L + 1), mid + 1, R);
        mx[i] = max(getmx(i + 1), getmx(i + 2 * (mid - L + 1)));
    }
}

ll query(int qL, int qR, int i = 1, ll L = 1, ll R = C)
{
    int mid = (L + R) / 2;
    if (R < qL || qR < L)
        return 0;
    if (qL <= L && R <= qR)
        return getsum(i, L, R);
    else
    {
        push(i, L, R);
        ll res = query(qL, qR, i + 1, L, mid) + query(qL, qR, i + 2 * (mid - L + 1), mid + 1, R);
        sum[i] = getsum(i + 1, L, mid) + getsum(i + 2 * (mid - L + 1), mid + 1, R);
        mx[i] = max(getmx(i + 1), getmx(i + 2 * (mid - L + 1)));
        return res;
    }
}

ll query2(int qL, int qR, int i = 1, ll L = 1, ll R = C)
{
    int mid = (L + R) / 2;
    if (R < qL || qR < L)
        return 0;
    if (qL <= L && R <= qR)
        return getmx(i);
    else
    {
        push(i, L, R);
        ll res = max(query2(qL, qR, i + 1, L, mid), query2(qL, qR, i + 2 * (mid - L + 1), mid + 1, R));
        sum[i] = getsum(i + 1, L, mid) + getsum(i + 2 * (mid - L + 1), mid + 1, R);
        mx[i] = max(getmx(i + 1), getmx(i + 2 * (mid - L + 1)));
        return res;
    }
}

signed main()
{
    fast;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        modify(i, i, a);
    }
    for (int i = 1; i <= Q; i++)
    {
        ll k, l, r, x;
        cin >> k >> l >> r;
        if(k <= 2)
            cin >> x;
        if(k == 1)
            modify2(l, r, x);
        if(k == 2)
            modify(l, r, x);
        if(k == 3)
            cout << query(l, r) << '\n';
        if(k == 4)
            cout << query2(l, r) << '\n';
    }
}

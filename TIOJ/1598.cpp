#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, b, p[100005];

int search(int l, int r)
{

    if (l == r)
        return l;
    int lmid = (2 * l + r) / 3, lb = 0, lt = 0,
        rmid = (l + 2 * r) / 3, rb = 0, rt = 0;
    for (int i = 1; i <= n; i++)
    {
        lt = max(lt, (int)ceil(log2((p[i] - 1) / lmid))), lb += (p[i] - 1) / lmid;
        rt = max(rt, (int)ceil(log2((p[i] - 1) / rmid))), rb += (p[i] - 1) / rmid;
    }
    lt += lmid;
    rt += rmid;
    //printf("BS %d (%d,%d) (%d,%d) %d\n", l, lmid, lt, rmid, rt, r);
    if (rb > b)
        return search(rmid + 1, r);
    if (lb > b)
        return search(lmid + 1, r);
    if (lt > rt)
        return search(lmid, r);
    else
        return search(l, rmid);
}

signed main()
{
    //fast;
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    int size = search(1, 1000000), res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, (int)ceil(log2((p[i] - 1) / size)));
    cout << res + size << '\n';
}
/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n;
pii arr[100005];

struct Seg
{
    int val, index;
    int lazyA, lazyC;
} seg[400005];

void push(int i)
{
    seg[i].val += arr[seg[i].index].F * seg[i].lazyA + seg[i].lazyC;
    seg[i * 2].lazyA = seg[i * 2 + 1].lazyA = seg[i].lazyA;
    seg[i * 2].lazyC = seg[i * 2 + 1].lazyC = seg[i].lazyC;
    seg[i].lazyA = seg[i].lazyC = 0;
}

void modifyC(int l, int r, int i, int a, int b, int val)
{
    push(i);
    if (b < a)
        return;
    if (b < l || r < a)
        return;
    cout << "Modify " << l << " " << r << '\n';
    if (a <= l && r <= b)
    {
        seg[i].lazyC += val;
    }
    else
    {
        int mid = (l + r) / 2;
        modifyC(l, mid, i * 2, a, b, val);
        modifyC(mid + 1, r, i * 2 + 1, a, b, val);
        if (pii{seg[i * 2].val, seg[i * 2].index} > pii{seg[i * 2 + 1].val, seg[i * 2 + 1].index})
            seg[i] = seg[i * 2];
        else
            seg[i] = seg[i * 2 + 1];
    }
    push(i);
}

void modifyA(int l, int r, int i, int a, int b)
{
    push(i);
    if (b < a)
        return;
    if (a <= l && r <= b)
        seg[i].lazyA++;
    else if (b < l || r < a)
        return;
    else
    {
        int mid = (l + r) / 2;
        modifyA(l, mid, i * 2, a, b);
        modifyA(mid + 1, r, i * 2 + 1, a, b);
        if (pii{seg[i * 2].val, seg[i * 2].index} > pii{seg[i * 2 + 1].val, seg[i * 2 + 1].index})
            seg[i] = seg[i * 2];
        else
            seg[i] = seg[i * 2 + 1];
    }
    push(i);
}

pii query(int l, int r, int i, int a, int b)
{
    push(i);
    if (a <= l && r <= b)
        return pii{seg[i].val, seg[i].index};
    else if (b < l || r < a)
        return {0, 0};
    else
    {
        int mid = (l + r) / 2;
        return max(query(l, mid, i * 2, a, b), query(mid + 1, r, i * 2 + 1, a, b));
    }
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].F >> arr[i].S;

    sort(arr + 1, arr + n);
    for (int i = 0, j = 0; i < n; i++)
    {
        int pos = upper_bound(arr + 1, arr + n, pii{arr[j].F + arr[j].S, 1000005}) - arr - 1;
        cout << pos << "  ";
        modifyC(0, n - 1, 1, 0, pos, arr[j].S);

        //modifyA(0, n - 1, 1, pos + 1, n - 1);
        //modifyC(0, n - 1, 1, pos + 1, n - 1, -arr[j].F);

        modifyC(0, n - 1, 1, j, j, -100000000000000);
        j = query(0, n - 1, 1, 1, n - 1).S;
        for (int i = 0; i < n; i++)
            cout << query(0, n - 1, 1, i, i).F << " ";
        cout << '\n';
    }
    cout << query(0, n - 1, 1, 0, 0).F;
}

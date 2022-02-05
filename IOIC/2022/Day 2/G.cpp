#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q, C;
int arr[100005];

int of(int a, int b, int c)
{
    // do a ? b : c for each bit
    return (a & b) | (~a & c);
}

int nand(int x, int y)
{
    const int mask = (1 << C) - 1;
    int ret = ~(x & y);
    return ret & mask;
}

struct segTree
{
    int zero[400005], one[4000005];
    void modify(int pos, int val, int i = 1, int L = 1, int R = N)
    {
        if (L == R)
        {
            zero[i] = nand(0, val);
            one[i] = nand((1 << C) - 1, val);
        }
        else
        {
            int mid = (L + R) / 2;
            if (pos <= mid)
                modify(pos, val, i << 1, L, mid);
            else
                modify(pos, val, (i << 1) | 1, mid + 1, R);
            zero[i] = of(zero[i << 1], one[(i << 1) | 1], zero[(i << 1) | 1]);
            one[i] = of(one[i << 1], one[(i << 1) | 1], zero[(i << 1) | 1]);
        }
    }
    pii query(int qL, int qR, int i = 1, int L = 1, int R = N)
    {
        if (qL > qR)
            return {0, (1 << C) - 1};
        if (qL <= L && R <= qR)
            return {zero[i], one[i]};
        else if (qR < L || R < qL)
            return {0, (1 << C) - 1};
        else
        {
            int mid = (L + R) / 2;
            pii lans = query(qL, qR, i << 1, L, mid),
                rans = query(qL, qR, (i << 1) | 1, mid + 1, R);
            return {of(lans.F, rans.S, rans.F), of(lans.S, rans.S, rans.F)};
        }
    }
} seg;

int main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> Q >> C;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < C; j++)
            seg.modify(i, arr[i]);
    }
    for (int i = 1; i <= Q; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            pii res = seg.query(l + 1, r);
            cout << of(arr[l], res.S, res.F) << '\n';
        }
        else if (t == 2)
        {
            arr[l] = r;
            seg.modify(l, arr[l]);
        }
    }
}

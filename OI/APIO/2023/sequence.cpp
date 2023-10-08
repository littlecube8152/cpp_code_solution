#include "sequence.h"
#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h>
using namespace __gnu_pbds;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

namespace
{
    int N;

    struct BIT
    {
        int bit[500005];
        void init()
        {
            for (int i = 0; i <= N; i++)
                bit[i] = 0;
        }
        void modify(int pos, int val)
        {
            for (; pos <= N; pos += (pos & -pos))
                bit[pos] += val;
        }
        int query(int pos)
        {
            int ans = 0;
            for (; pos > 0; pos -= (pos & -pos))
                ans += bit[pos];
            return ans;
        }
    } bitbig, bitsmall;

    struct segTree
    {
        struct node
        {
            int maxp, minp, maxsum, minsum;
        } seg[2000006];

        node merge(node l, node r)
        {
            return node{max(l.maxp, l.maxsum + r.maxp), min(l.minp, l.minsum + r.minp),
                        l.maxsum + r.maxsum, l.minsum + r.minsum};
        }

        void init(int i = 1, int L = 1, int R = N)
        {
            if (L == R)
                seg[i] = {0, -1, -1, -1};
            else
            {
                int mid = (L + R) / 2;
                init(i << 1, L, mid);
                init(i << 1 | 1, mid + 1, R);
                seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
            }
        }

        void modify(int pos, int val, int i = 1, int L = 1, int R = N)
        {
            if (L == R)
                seg[i] = node{1, 0, 1, val};
            else
            {
                int mid = (L + R) / 2;
                if (pos <= mid)
                    modify(pos, i << 1, L, mid);
                else
                    modify(pos, i << 1 | 1, mid + 1, R);
                seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
            }
        }
        node query(int qL, int qR, int i = 1, int L = 1, int R = N)
        {
            if (qL <= L && R <= qR)
                return seg[i];
            else if (R < qL || qR < L)
                return node{0, 0, 0, 0};
            else
            {
                int mid = (L + R) / 2;
                return merge(query(qL, qR, i << 1, L, mid), query(qL, qR, i << 1 | 1, mid + 1, R));
            }
        }
    } lseg, rseg;
    vector<int> v[500005];

}

int sequence(int N, vector<int> A)
{
    ::N = N;
    int ans = 1;
    A.insert(A.begin(), 0);
    for (int i = 1; i <= N; i++)
        v[A[i]].emplace_back(i);
    for (int i = 1; i <= N; i++)
        bitbig.modify(i, -1), bitsmall.modify(i, -1);
    lseg.init();
    rseg.init();
    for (int i = 1; i <= N; i++)
    {
        for (int j : v[i])
            bitbig.modify(j, 2), lseg.modify(j, 0), rseg.modify((N + 1) - j);
        if (v[i].size() == 2)
        {
            int l = v[i][0], r = v[i][1];
            // check there is any range contain [l, r] and avaliable: check max and min
            int mid = bitsmall.query(r - 1) - bitsmall.query(l);
            int lsum = bit.query(l - 1);
            int rsum = bit.query(N) - bit.query(r);
            auto lres = lseg.query(1, l - 1);
            auto rres = rseg.query(1, (N + 1) - (r + 1));
            int pmin = mid + (lsum - lres.maxp) + (rsum - rres.maxp);
            int pmax = mid + (lsum - lres.minp) + (rsum - rres.minp);
            // cerr << i << ' ' << pmin << ' ' << pmax << '\n';
            for (int j = -2; j <= 2; j++)
                if (pmin <= j && j <= pmax)
                    ans = 2;
        }
        if (v[i].size() >= 3)
            assert(0);
        for (int j : v[i])
            bit.modify(j, 2), lseg.modify(j), rseg.modify((N + 1) - j);
    }
    return ans;
}
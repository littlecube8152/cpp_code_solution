#include "candies.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;


struct node
{
    ll m, M, sum;
    bool check(int c)
    {
        return M - m < c;
    }
} seg[850005];

node merge(node p, node q)
{
    auto [lm, lM, lsum] = p;
    auto [rm, rM, rsum] = q;
    return node{min(lm + rsum, rm), max(lM + rsum, rM), lsum + rsum};
}

int n, q;
node emp = {0, 0, 0};

void init()
{
    for (int i = 1; i <= 4 * (q + 2); i++)
        seg[i] = emp;
}

void modify(int pos, node val, int i = 1, int L = 0, int R = q + 1)
{
    if (L == R)
        seg[i] = val;
    else
    {
        int mid = (L + R) / 2;
        if (pos <= mid)
            modify(pos, val, i << 1, L, mid);
        else
            modify(pos, val, i << 1 | 1, mid + 1, R);
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
}

pair<int, node> search(int c, node suf = emp, int i = 1, int L = 0, int R = q + 1)
{
    if (L == R)
        return make_pair(L, suf);
    else
    {
        int mid = (L + R) / 2;
        if (merge(seg[i << 1 | 1], suf).check(c))
            return search(c, merge(seg[i << 1 | 1], suf), i << 1, L, mid);
        else
            return search(c, suf, i << 1 | 1, mid + 1, R);
    }
}

vector<int> in[200000], out[200001];
node base[200002];
vector<int> distribute_candies(vector<int> c, vector<int> l,
                               vector<int> r, vector<int> v)
{
    vector<int> ans;
    n = c.size(), q = l.size();
    v.insert(v.begin(), 1);
    l.insert(l.begin(), 0);
    r.insert(r.begin(), 0);
    for (int i = 1; i <= q; i++)
    {
        in[l[i]].emplace_back(i);
        out[r[i] + 1].emplace_back(i);
        if (v[i] < 0)
            base[i] = node{v[i], 0, v[i]};
        else
            base[i] = node{0, v[i], v[i]};
    }
    init();
    for (int i = 0; i < n; i++)
    {
        for (auto j : in[i])
            modify(j, base[j]);
        for (auto j : out[i])
            modify(j, emp);
        auto [L, s] = search(c[i]);
        if (v[L] < 0)
            ans.emplace_back(s.M);
        else
            ans.emplace_back(c[i] + s.m);
    }
    return ans;
}
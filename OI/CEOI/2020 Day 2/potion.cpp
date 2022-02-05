#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, d, h[100005], u, hdx;
vector<int> avaliable[100005];
map<int, int> exist[100005];
vector<pii> history[100005];

struct pSegTree
{
    int t, L, R, val;
    pSegTree *l, *r;
    pSegTree() : t(0){};
    pSegTree(int t, int L, int R, int val, pSegTree *l, pSegTree *r) : t(t), L(L), R(R), val(val), l(l), r(r){};
    pSegTree(int t, pSegTree *p) : t(t), L(p->L), R(p->R), val(p->val), l(p->l), r(p->r){};
    void build()
    {
        if (L == R)
            return;
        int mid = (L + R) / 2;
        l = new pSegTree(t, L, mid, -1, nullptr, nullptr);
        l->build();
        r = new pSegTree(t, mid + 1, R, -1, nullptr, nullptr);
        r->build();
    }
    void modify(int pos, int val)
    {
        if (L == R)
            this->val = val;
        else
        {
            int mid = (L + R) / 2;
            if (pos <= mid)
            {
                if (l->t != t)
                    l = new pSegTree(t, l);
                l->modify(pos, val);
            }
            else
            {
                if (r->t != t)
                    r = new pSegTree(t, r);
                r->modify(pos, val);
            }
        }
    }
    void arr(vector<ll> &v)
    {
        //cout << "arring " << t << " " << L << " " << R << " " << val << "\n";
        if (L == R)
        {
            if (val != -1)
                v.emplace_back(h[val]);
        }
        else
        {
            l->arr(v);
            r->arr(v);
        }
    }
};

pSegTree *seg[500005];

void init(int N, int D, int H[])
{
    n = N;
    d = D;
    for (int i = 0; i < N; i++)
        h[i] = H[i];
}

void curseChanges(int U, int A[], int B[])
{
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= d; j++)
            avaliable[i].emplace_back(j);
    seg[0] = new pSegTree(0, 1, d, -1, nullptr, nullptr);
    seg[0]->build();
    for (int i = 0; i < n; i++)
        history[i].emplace_back(pii{0, 0});
    hdx = 0;

    for (int i = 0; i < U; i++)
    {

        int a = A[i], b = B[i];
        if (exist[A[i]].find(B[i]) != exist[A[i]].end())
        {
            ++hdx;
            seg[hdx] = new pSegTree(hdx, seg[history[A[i]].back().S]);
            history[A[i]].emplace_back(pii{i + 1, hdx});
            seg[hdx]->modify(exist[A[i]][B[i]], -1);
            avaliable[A[i]].emplace_back(exist[A[i]][B[i]]);
            exist[A[i]].erase(exist[A[i]].find(B[i]));

            ++hdx;
            seg[hdx] = new pSegTree(hdx, seg[history[B[i]].back().S]);
            history[B[i]].emplace_back(pii{i + 1, hdx});
            seg[hdx]->modify(exist[B[i]][A[i]], -1);
            avaliable[B[i]].emplace_back(exist[B[i]][A[i]]);
            exist[B[i]].erase(exist[B[i]].find(A[i]));
        }
        else
        {
            ++hdx;
            seg[hdx] = new pSegTree(hdx, seg[history[A[i]].back().S]);
            history[A[i]].emplace_back(pii{i + 1, hdx});
            exist[A[i]][B[i]] = avaliable[A[i]].back();
            seg[hdx]->modify(avaliable[A[i]].back(), B[i]);
            avaliable[A[i]].pop_back();

            ++hdx;
            seg[hdx] = new pSegTree(hdx, seg[history[B[i]].back().S]);
            history[B[i]].emplace_back(pii{i + 1, hdx});
            exist[B[i]][A[i]] = avaliable[B[i]].back();
            seg[hdx]->modify(avaliable[B[i]].back(), A[i]);
            avaliable[B[i]].pop_back();
        }
    }
    for (int i = 0; i < n; i++)
        history[i].emplace_back(pii{U + 1, 0});
    for (int i = 0; i < n; i++)
        avaliable[i].clear(), exist[i].clear();
}

int question(int x, int y, int v)
{
    int verX = prev(upper_bound(history[x].begin(), history[x].end(), pii{v, 1e9}))->S;
    int verY = prev(upper_bound(history[y].begin(), history[y].end(), pii{v, 1e9}))->S;
    vector<ll> hX, hY;
    seg[verX]->arr(hX);
    seg[verY]->arr(hY);
    hX.emplace_back(-1e9);
    hX.emplace_back(2e9);
    sort(hX.begin(), hX.end());
    ll ans = 1e9;
    for (ll i : hY)
    {
        auto iter = lower_bound(hX.begin(), hX.end(), i);
        ans = min({ans, abs(i - *iter), abs(i - *prev(iter))});
    }
    return ans;
}

/*
6 5 11 4
2 42 1000 54 68 234
0 1
2 0
3 4
3 5
3 5
1 3
5 3
0 5
3 0
1 3
3 5
0 3 4 26
3 0 8 0
0 5 5 1000000000
3 0 11 14*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int n, q, c[500005], a[500005];
vector<pii> qu[500005];
vector<int> b;

const int P = 20;
struct XORBasis
{
    int val[P];
    void clear()
    {
        for (int i = 0; i < P; i++)
            val[i] = 0;
    }
    int eliminate(int x)
    {
        for (int i = P - 1; i >= 0; i--)
            if ((x >> i) & 1)
                x ^= val[i];
        return x;
    }
    void insert(int x)
    {
        if (x == 0)
            return;
        val[__lg(x)] = x;
    }
    int max()
    {
        int res = 0;
        for (int i = P - 1; i >= 0; i--)
            if (!((res >> i) & 1))
                res ^= val[i];
        return res;
    }
} basis;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        qu[l].emplace_back(pii(r, i));
    }
    for (int i = n; i >= 1; i--)
    {
        sort(qu[i].begin(), qu[i].end());
        vector<int> nb = {i};
        basis.clear();
        basis.insert(c[i]);
        int qdx = 0;
        for (auto j : b)
        {
            int x = basis.eliminate(c[j]);
            if (x)
            {
                while (qdx < qu[i].size() && qu[i][qdx].F < j)
                {
                    a[qu[i][qdx].S] = basis.max();
                    qdx++;
                }
                basis.insert(x);
                nb.emplace_back(j);
            }
        }
        b = nb;
        while (qdx < qu[i].size())
        {
            a[qu[i][qdx].S] = basis.max();
            qdx++;
        }
    }
    for (int i = 1; i <= q; i++)
        cout << a[i] << '\n';
}
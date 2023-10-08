#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int n;

struct sparse
{
    ll table[100005][20];
    void build()
    {
        for (int p = 0; p + 1 < 20; p++)
            for (int i = 0; i + (1 << p) <= n; i++)
                table[i][p + 1] = max(table[i][p], table[i + (1 << p)][p]);
    }
    ll query(int l, int r)
    {
        int p = __lg(r - l + 1);
        return max(table[l][p], table[r + 1 - (1 << p)][p]);
    }
} table[2];

ll dp[100005][2], b[100005], w[100005], t[100005];

int cost(int i, int j, int k)
{
    return dp[i][k ^ 1] + table[k].query(i + 1, j) - (k == 0 ? b : w)[i];
}

int search(int i, int j, int k, int L, int R = n)
{
    if (L == R)
        return L;
    else
    {
        int mid = (L + R + 1) / 2;
        if (cost(i, mid, k) < cost(j, mid, k))
            return search(i, j, k, mid, R);
        else
            return search(i, j, k, L, mid - 1);
    }
}

void concave1D1D()
{
    vector<pii> st[2];
    st[0].emplace_back(pii(0, n + 1));
    st[1].emplace_back(pii(0, n + 1));
    // pair (index, right end $h_\texttt{index}$)
    for (int i = 1; i <= n; i++)
    {
        for (int c = 0; c <= 1; c++)
        {
            while (st[c].back().S < i)
                st[c].pop_back();
            int j = st[c].back().F;
            dp[i][c] = cost(j, i, c);
            // cerr << i << ' ' << c << ' ' << dp[i][c] << " from " << j << '\n';
        }
        for (int c = 0; c <= 1; c++)
        {
            int j = st[c].back().F;
            while (!st[c].empty() && search(i, j, c, i) >= st[c].back().S)
            {
                st[c].pop_back();
                j = st[c].back().F;
            }
            st[c].emplace_back(pii(i, search(i, j, c, i)));
        }
    }
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= n; i++)
        table[0].table[i][0] = (b[i] += b[i - 1]) + t[i],
        table[1].table[i][0] = (w[i] += w[i - 1]) + t[i];
    table[0].build();
    table[1].build();
    concave1D1D();
    ll ans = 1e18;
    for (int i = 0; i <= n; i++)
        ans = min({ans, b[n] - b[i] + dp[i][1], w[n] - w[i] + dp[i][0]});
    cout << ans << '\n';
}
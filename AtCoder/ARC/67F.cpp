#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct sparse
{
    ll table[5003][20];
    void build(int n)
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
};
sparse table[202]; // refer to previous code
ll ans, A[5003], S[5003];
int N, M;

ll F(int i, int j)
{
    ll res = 0;
    for (int k = 1; k <= M; k++)
        res += table[k].query(i, j);
    return res - (A[j] - A[i]);
}

void dc(int L, int R, int ansL, int ansR)
{
    int mid = (L + R) / 2, ansmid = 0;
    ll opt = -1e18;
    for (int i = max(mid, ansL); i <= ansR; i++)
        if (F(mid, i) > opt)
            ansmid = i, opt = F(mid, i);
    ans = max(ans, opt);
    if (L == R)
        return;
    dc(L, mid, ansL, ansmid);
    dc(mid + 1, R, ansmid, ansR);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 2; i <= N; i++)
    {
        cin >> A[i];
        A[i] += A[i - 1];
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> table[j].table[i][0];
    for (int j = 1; j <= M; j++)
        table[j].build(N);
    dc(1, N, 1, N);
    cout << ans << '\n';
}

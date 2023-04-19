#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int n, m, b[405][405], k, mx, idx;

void brute(int i, int j)
{
    cerr << (mx = max(mx, idx)) << '\n';
    if (idx >= k)
    {
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                cout << b[i][j] << " \n"[j == m];
        exit(0);
    }
    else if (i == m + 1)
        return;
    else if (b[i][j])
    {
        if (j == m)
            brute(i + 1, 1);
        else
            brute(i, j + 1);
        return;
    }
    bool no[401] = {};
    for (int k = 1; k <= m; k++)
        no[b[i][k]] = no[b[k][j]] = 1;
    int I = (i - 1) / n, J = (j - 1) / n;
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
            no[b[I * n + x][J * n + y]] = 1;
    for (int k = 1; k <= m; k++)
        if (!no[k])
        {
            b[i][j] = k, idx++;
            if (j == m)
                brute(i + 1, 1);
            else
                brute(i, j + 1);
            if (!no[k])
                b[i][j] = 0, idx--;
        }
}

signed main()
{
    cin >> n;
    m = n * n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    if (!(cin >> k))
        k = m * m + 1;
    cerr << k << '\n';
    brute(1, 1);
}
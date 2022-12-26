#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int n, m, b[405][405], k;

signed main()
{
    cin >> n;
    m = n * n;
    for (int i = 0, cur = 1; i < m; i++)
    {
        for (int j = 1; j <= m; j++)
            b[cur][j] = (i + j - 1) % m + 1;
        cur += n;
        if(cur > m)
            cur -= m - 1;
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            cout << b[i][j] << " \n"[j == m];
}
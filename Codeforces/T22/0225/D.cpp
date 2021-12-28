#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

long long n, m, a[105], b[105], mat[105][105];
int main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int t = 0; t <= 30; t++)
    {
        long long bita[105] = {0}, bitb[105] = {0}, bca = 0, bcb = 0, bit[105][105] = {{0}};
        for (int i = 1; i <= n; i++)
            if (a[i] & (1 << t))
                bita[i] = 1, bca++;
        for (int i = 1; i <= m; i++)
            if (b[i] & (1 << t))
                bitb[i] = 1, bcb++;

        if ((bca + bcb) % 2)
        {
            cout << "NO";
            return 0;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (bita[i] && bitb[j] && bca % 2 && bcb % 2)
                {
                    bit[i][j] = 1;
                    bca--;
                    bcb--;
                    bita[i] ^= 1;
                    bitb[j] ^= 1;
                }
        if (bca > 0)
        {
            for (int i = 1; i <= n; i++)
                if (bita[i])
                    for (int j = i + 1; j <= n; j++)
                        if (bita[j])
                        {
                            bit[i][1] ^= 1, bit[j][1] ^= 1, bita[i] = 0, bita[j] = 0;
                            i = j;
                            break;
                        }
        }
        if (bcb > 0)
            for (int i = 1; i <= m; i++)
                if (bitb[i])
                    for (int j = i + 1; j <= m; j++)
                        if (bitb[j])
                        {
                            bit[1][i] ^= 1, bit[1][j] ^= 1, bitb[i] = 0, bitb[j] = 0;
                            i = j;
                            break;
                        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                mat[i][j] += (bit[i][j] << t);
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << " \n"[j == m];
}
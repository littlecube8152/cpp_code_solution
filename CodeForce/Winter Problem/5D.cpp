#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    ll n, m, k, x, y, p[101][101] = {{0}}, _max = 0, _min = _INFINITY;
    cin >> n >> m >> k >> x >> y;
    if (n == 1)
    {
        cout << (k + m - 1) / m << " " << k / m << ' ';
        if (y <= k % m)
            cout << (k + m - 1) / m;
        else
            cout << k / m;
        return 0;
    }
    else
    {
        ll round = k / ((n - 1) * m), leave = k % ((n - 1) * m);
        for (int i = 1; i <= n - 1; i++)
            for (int j = 1; j <= m; j++)
                p[i][j] += (round + 1) / 2;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= m; j++)
                p[i][j] += (round) / 2;


        if (round % 2 == 0)
            for (int i = 1; i <= (leave + m - 1) / m; i++)
                for (int j = 1; (i - 1) * m + j <= leave && j <= m; j++)
                    p[i][j]++;
        else
            for (int i = 1; i <= (leave + m - 1) / m; i++)
                for (int j = 1; (i - 1) * m + j <= leave && j <= m; j++)
                    p[(n - i + 1)][j]++;

        

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                _max = max(_max, p[i][j]);
                _min = min(_min, p[i][j]);
            }
        cout << _max << " " << _min << " " << p[x][y];
    }
}
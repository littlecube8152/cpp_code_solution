
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/extc++.h>
#define ll long long
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const ll mod = 2;
ll inv(ll b)
{
    ll a = 1, p = mod - 2;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

ll n, m, a[505][505], b[505];

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int i = 0;
    for (; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
            if (a[j][i + 1])
            {
                for (int k = 1; k <= m; k++)
                    swap(a[j][k], a[i + 1][k]);
                swap(b[j], b[i + 1]);
                break;
            }
        
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, idx = 0, a[5000][270] = {{}}, adj[70][70] = {{}}, x[270] = {}, b[5000] = {};
        // a1x1 + a2x2 + ... = b
        cin >> n >> m;

        int solved = 0;
        for (int i = 1; i <= m; i++)
        {
            int j = i + solved;
            if (j > idx)
                break;

            if (!a[j][i])
            {
                for (int k = j + 1; k <= idx; k++)
                    if (a[k][i])
                    {
                        for (int l = 1; l <= m; l++)
                            swap(a[j][l], a[k][l]);
                        swap(b[j], b[k]);
                        break;
                    }
            }
            if (a[j][i])
            {
                for (int k = j + 1; k <= idx; k++)
                    if (a[k][i])
                    {
                        // cout << j << " elimiate " << k << '\n';
                        int mul = a[k][i];
                        for (int l = 1; l <= m; l++)
                        {
                            a[k][l] = ((a[k][l] * a[j][i] - a[j][l] * mul) + 33333) % 3;
                            assert(a[k][l] >= 0);
                        }
                        b[k] = ((b[k] * a[j][i] - b[j] * mul) + 33333) % 3;
                        assert(b[k] >= 0);
                    }
            }
            else
                solved--;
            /*
            for (int i = 1; i <= idx; i++)
            {
                for (int j = 1; j <= m; j++)
                    cout << a[i][j] << " ";
                cout << "= " << b[i] << '\n';
            }
            cout << '\n';
            */
        }
        bool valid = true;
        int cur = m;
        for (int i = idx; i >= 1; i--)
        {
            int nonzero = 0;
            for (int j = 1; j <= m; j++)
            {
                if (nonzero == 0 && a[i][j] != 0)
                {
                    nonzero = j;
                    for (int k = nonzero + 1; k <= cur; k++)
                        if (x[k] == -1)
                            x[k] = 3;
                    cur = j;
                }
                else if (a[i][j] != 0)
                {
                    b[i] = (b[i] - a[i][j] * x[j] + 33333) % 3;
                    assert(b[i] >= 0);
                    a[i][j] = 0;
                }
            }
            if (nonzero == 0 && b[i] != 0)
            {
                valid = false;
                break;
            }
            else if (nonzero != 0)
            {
                x[nonzero] = (b[i] * a[i][nonzero] + 33333) % 3;
                // should be b[i] / a[i][nonzero] but 1 * 1 = 1 (mod 3) and 2 * 2 = 1 (mod 3)
                assert(x[nonzero] >= 0);
            }
            /*
            for (int i = 1; i <= m; i++)
                cout << x[i] << " \n"[i == m];
            */
        }
        for (int j = 1; j <= m; j++)
            if (x[j] == -1)
                x[j] = 3;
        if (valid)
            for (int i = 1; i <= m; i++)
                cout << (x[i] == 0 ? 3 : x[i]) << " \n"[i == m];
        else
            cout << "-1\n";
    }
}

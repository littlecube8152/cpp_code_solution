#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, q, arr[500001], table[20][500001];

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        table[0][i] = arr[i];

    for (int t = 1; t <= log2(n); t++)
        for (int i = 0; i < n; i++)
            table[t][i] = min(table[t - 1][i], table[t - 1][min(n - 1, i + (1 << (t - 1)))]);
    for (int i = 1; i <= q; i++)
    {
        int l, r, t;
        cin >> l >> r;
        t = log2((--r) - l + 1);
        cout << min(table[t][l], table[t][r - (1 << t) + 1]) << '\n';
    }
}
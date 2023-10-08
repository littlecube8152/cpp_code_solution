#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int n, m, msb[1000], no[1000];
bitset<1000> b[1000], r[1000], I[1000], c[1000], out, s[1000];
vector<int> basis;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            r[i][j] = (s[j] == '1');
        c[i][i] = 1;
        for (int j : basis)
            if (r[i][msb[j]])
                r[i] ^= r[j], c[i] ^= c[j];
        if (r[i].none())
            out |= c[i];
        else
        {
            basis.emplace_back(i);
            msb[i] = r[i]._Find_first();
            sort(basis.begin(), basis.end(), [&](int x, int y)
                 { return msb[x] < msb[y]; });
        }
    }

    for (int i = 0; i < m; i++)
    {
        I[i][i] = 1;
        for (int j : basis)
            if (I[i][msb[j]])
                I[i] ^= r[j], s[i] ^= c[j];
        no[i] = I[i].none();
    }
    for (int i = 0; i < n; i++)
    {
        if (out[i])
            for (int j = 0; j < m; j++)
                cout << (no[j] ? '0' : '+');
        else
            for (int j = 0; j < m; j++)
                cout << (no[j] && s[j][i] ? '-' : '0');
        cout << '\n';
    }
}
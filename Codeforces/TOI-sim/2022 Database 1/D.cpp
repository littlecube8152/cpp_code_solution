#include <bits/stdc++.h>
#define ll long lonh
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

// seg[i][j]
// i: 0 = rock, 1 = paper, 2 = scissor
// j: lefthas + 16 righthas
// has: 1 = rock, 2 = paper, 4 = scissor
int n, q, seg[400005][3][9], has[400005];

void pull(int i, int l, int r)
{
    has[i] = has[l] | has[r];
    for (int j = 0; j < 3; j++)
        for (int k = 0; k < 9; k++)
            seg[i][j][k] = 0;
    for (int j = 0; j < 3; j++)
    {
        int lose = 1 << ((j + 1) % 3), win = 1 << ((j + 2) % 3);

        for (int kl = 0; kl < 3; kl++)
            for (int kr = 0; kr < 3; kr++)
            {
                if (has[l] & win)
                    seg[i][j][6 + kr] += seg[r][j][kl * 3 + kr];
                else if (has[l] & lose)
                    seg[i][j][max(3 * kl, 3) + kr] += seg[r][j][kl * 3 + kr];
                else
                    seg[i][j][kl * 3 + kr] += seg[r][j][kl * 3 + kr];

                if (has[r] & win)
                    seg[i][j][kl * 3 + 2] += seg[l][j][kl * 3 + kr];
                else if (has[r] & lose)
                    seg[i][j][kl * 3 + max(kr, 1)] += seg[l][j][kl * 3 + kr];
                else
                    seg[i][j][kl * 3 + kr] += seg[l][j][kl * 3 + kr];
            }
    }
}

void modify(int pos, int val, int i = 1, int L = 1, int R = n)
{
    if (L == R)
    {
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 9; k++)
                seg[i][j][k] = 0;
        seg[i][val][0] = 1;
        has[i] = (1 << val);
    }
    else
    {
        int mid = (L + R) / 2;
        if (pos <= mid)
            modify(pos, val, i + 1, L, mid);
        else
            modify(pos, val, i + 2 * (mid - L + 1), mid + 1, R);
        pull(i, i + 1, i + 2 * (mid - L + 1));
    }
}

int calc()
{
    int ans = 0;
    for (int i = 0; i < 3; i++)
        ans += seg[1][i][0] + seg[1][i][2] + seg[1][i][6] + seg[1][i][8];
    return ans;
}

signed main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    char c;
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        modify(i, (c == 'R' ? 0 : (c == 'P' ? 1 : 2)));
    }
    cout << calc() << '\n';
    for (int i = 1; i <= q; i++)
    {
        int p;
        cin >> p >> c;
        modify(p, (c == 'R' ? 0 : (c == 'P' ? 1 : 2)));
        cout << calc() << '\n';
    }
}
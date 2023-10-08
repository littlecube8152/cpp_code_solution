/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, k, pos[102][2], r, g;
int nim[100];

signed main()
{
    fast;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        pos[i][0] = pos[i][1] = -1;
        char c;
        for (int j = 1; j <= m; j++)
        {
            c = s[j - 1];
            if (c == 'G')
                pos[i][0] = j;
            else if (c == 'R')
                pos[i][1] = j;
        }
        if (pos[i][0] < 0 && pos[i][1] > 0 && s != "RR" && s != "R")
            r++;
        else if (pos[i][0] > 0 && pos[i][1] < 0 && s != "GG" && s != "G")
            g++;
        else if (pos[i][0] > 0 && pos[i][1] > 0)
        {
            int f = abs(pos[i][0] - pos[i][1]) - 1, j = 0;
            while (f)
            {
                nim[j] = (nim[j] + (f & 1)) % (k + 1);
                f /= 2; // (k + 1);
                j++;
            }
        }
    }
    if (m == 1)
        cout << "Second\n";
    else if (r && g)
        cout << "Draw\n";
    else if (g)
        cout << "First\n";
    else if (r)
        cout << "Second\n";
    else
    {
        for (int j = 0; j <= 20; j++)
            if (nim[j])
            {
                cout << "First\n";
                return 0;
            }

        cout << "Second\n";
    }
}

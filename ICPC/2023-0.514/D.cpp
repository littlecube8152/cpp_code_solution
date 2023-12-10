/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

int h, w, k, t;
string row[1005], col[1005];
vector<int> sol[1005];

signed main()
{
    fast;
    cin >> h >> w >> k;
    for (int i = 1; i <= h - 1; i++)
        cin >> row[i] >> col[i];
    cin >> row[h];

    if (k == 1)
    {
        int ver = 0;
        for (int i = 1; i <= h - 1; i++)
            for (auto c : col[i])
                ver += (c == 'E' ? 1 : -3);
        for (int i = 1; i <= h; i++)
            for (auto c : row[i])
                ver += (c == 'E' ? 1 : -3);
        if (ver >= 0)
        {
            cout << "YES\n";
            for (int i = 1; i <= h; i++)
                for (int j = 1; j <= w; j++)
                    cout << 1 << " \n"[j == w];
        }
        else
            cout << "NO\n";
        return 0;
    }

    if (h * (w - 1) < w * (h - 1))
    {
        t = 1;

        stringstream ss;
        for (int i = 0; i < w - 1; i++)
        {
            for (int j = 1; j <= h - 1; j++)
                ss << col[j][i];
            ss << '\n';
            for (int j = 1; j <= h; j++)
                ss << row[j][i];
            ss << '\n';
        }
        for (int j = 1; j <= h - 1; j++)
            ss << col[j][w - 1];
        ss << '\n';

        swap(h, w);
        for (int i = 1; i <= h - 1; i++)
            ss >> row[i] >> col[i];
        ss >> row[h];
    }

    for (int i = 1; i <= h; i++)
    {
        sol[i].emplace_back(1);
        for (int j = 0; j < w - 1; j++)
            sol[i].emplace_back(sol[i].back() ^ (row[i][j] == 'E' ? 0 : 3));
        if (i > 1)
        {
            int ver = 0;
            for (int j = 0; j < w; j++)
                ver += ((sol[i][j] == sol[i - 1][j]) ^ (col[i - 1][j] == 'E') ? -1 : 1);
            if (ver < 0)
                for (auto &j : sol[i])
                    j ^= 3;
        }
    }

    cout << "YES\n";

    if (!t)
        for (int i = 1; i <= h; i++)
            for (int j = 0; j < w; j++)
                cout << sol[i][j] << " \n"[j == w - 1];
    else
        for (int j = 0; j < w; j++)
            for (int i = 1; i <= h; i++)
                cout << sol[i][j] << " \n"[i == h];
}

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

vector<string> ans = {"z"};

signed main()
{
    fast;
    string s[6];
    cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5];
    sort(s, s + 6);
    do
    {
        /*
        *0*
        1 2
        *3*3*
          2 4
          *5*
        */
        if (s[0].size() + s[5].size() == s[3].size() + 1 &&
            s[1].size() + s[4].size() == s[2].size() + 1 &&
            s[0].front() == s[1].front() &&
            s[0].back() == s[2].front() &&
            s[1].back() == s[3].front() &&
            s[3].back() == s[4].front() &&
            s[2].back() == s[5].front() &&
            s[4].back() == s[5].back() &&
            s[2][(int)s[1].size() - 1] == s[3][(int)s[0].size() - 1])
        {
            vector<string> res(s[2].size());
            for (int i = 0; i < s[2].size(); i++)
                res[i] = string(s[3].size(), '.');

            for (int i = 0; i < s[0].size(); i++)
                res[0][i] = s[0][i];
            for (int i = 0; i < s[1].size(); i++)
                res[i][0] = s[1][i];
            for (int i = 0; i < s[2].size(); i++)
                res[i][(int)s[0].size() - 1] = s[2][i];
            for (int i = 0; i < s[3].size(); i++)
                res[(int)s[1].size() - 1][i] = s[3][i];
            for (int i = 0; i < s[4].size(); i++)
                res[(int)s[1].size() - 1 + i].back() = s[4][i];
            for (int i = 0; i < s[5].size(); i++)
                res.back()[(int)s[0].size() - 1 + i] = s[5][i];
            ans = min(ans, res);
        }

    } while (next_permutation(s, s + 6));
    if (ans.size() <= 1)
        cout << "Impossible\n";
    else
        for (auto s : ans)
            cout << s << '\n';
}

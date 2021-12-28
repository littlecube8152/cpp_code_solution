#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

string s, t;
int S, T;
int front[3005][3005], back[3005][3005];

pair<int, pii> solve(string s, string t)
{
    int ans = 0;
    pii anspos;
    S = s.size(), T = t.size();
    for (int i = 0; i < S; i++)
        for (int j = 0; j < T; j++)
            front[i][j] = back[i][j] = 0;
    for (int k = -S; k <= S; k++)
    {
        vector<int> v;
        for (int i = max(0, -k); 0 <= i && i < S && 0 <= i + k && i + k < T; i++)
            if (s[i] == t[i + k])
                v.emplace_back(i);
            else
            {
                int acc = 0;
                while (!v.empty())
                {
                    front[v.back()][v.back() + k] = ++acc;
                    v.pop_back();
                }
            }
        int acc = 0;
        while (!v.empty())
        {
            front[v.back()][v.back() + k] = ++acc;
            if (front[v.back()][v.back() + k] > ans)
                ans = front[v.back()][v.back() + k], anspos = pii{v.back(), v.back() + k};
            v.pop_back();
        }
    }
    int reach[3003] = {};
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < T; j++)
            reach[j] = T;
        for (int j = 0; j < T; j++)
            if (front[i][j] > 0)
                reach[j + front[i][j] - 1] = min(reach[j + front[i][j] - 1], j);
        int mi = T;
        for (int j = T - 1; j >= 0; j--)
        {
            mi = min(mi, reach[j]);
            back[i][j] = max(0, j - mi + 1);
            back[i][j] = max(0, back[i][j] + j);
        }
    }
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < T; j++)
            reach[j] = T;
        for (int j = 0; j < T; j++)
            if (front[i][j] > 0)
                reach[j + front[i][j] - 1] = min(reach[j + front[i][j] - 1], j);
        int mi = T;
        for (int j = T - 1; j >= 0; j--)
        {
            mi = min(mi, reach[j]);
            back[i][j] = max(0, j - mi + 1);
        }
    }
    for (int i = 1; i < T; i++)
    {
        pii table[13][3005];
        for (int j = 0; j < S; j++)
            table[0][j] = pii{back[j][i - 1] + j, j};
        for (int p = 1; p <= 12; p++)
            for (int j = 0; j < S; j++)
                table[p][j] = max(table[p - 1][j], table[p - 1][min(S - 1, j + (1 << (p - 1)))]);
        for (int j = 0; j < S; j++)
        {
            int a = j, b = j + front[j][i];
            int lg = __lg(b - a + 1);
            int tmpans = -j + max(table[lg][a], table[lg][b - (1 << lg) + 1]).F;
            if (tmpans > ans)
            {

                ans = tmpans;
                anspos = {j,
                          max(table[lg][a], table[lg][b - (1 << lg) + 1]).S + (i - j) - tmpans};
            }
        }
    }
    return make_pair(ans, anspos);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s >> t;
    pair<int, pii> ans1 = solve(s, t);
    reverse(t.begin(), t.end());
    pair<int, pii> ans2 = solve(s, t);
    ans2.S.S = t.size()  - 1 - (ans2.S.S + ans2.F - 1);
    pair<int, pii> ans = max(ans1, ans2);

    cout << ans.F << '\n';
    cout << ans.S.F << " " << ans.S.S << '\n';
}
/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int n, k, pos[500005];
string s[500005];

#define sigma 26
struct AhoCorasick
{
    int ch[500005][sigma] = {{}}, f[500005] = {-1}, cnt[500005], ord[500005];
    int idx = 0;
    int insert(string &s)
    {
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!ch[j][s[i] - 'a'])
                ch[j][s[i] - 'a'] = ++idx;
            j = ch[j][s[i] - 'a'];
        }
        return j;
    }
    void build()
    {
        queue<int> q;
        q.push(0);
        for (int i = 0; !q.empty(); i++)
        {
            int u = ord[i] = q.front();
            q.pop();
            for (int v = 0; v < sigma; v++)
                if (ch[u][v])
                {
                    int cur = f[u];
                    while (cur >= 0)
                        if (ch[cur][v])
                            break;
                        else
                            cur = f[cur];
                    f[ch[u][v]] = (cur < 0 ? 0 : ch[cur][v]);
                    q.push(ch[u][v]);
                }
        }
    }
    void match(string &s)
    {
        for (int i = 0; i <= idx; i++)
            cnt[i] = 0;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            while (j >= 0)
                if (ch[j][s[i] - 'a'])
                    break;
                else
                    j = f[j];
            j = (j < 0 ? 0 : ch[j][s[i] - 'a']);
            cnt[j]++;
        }
        vector<int> v;
        v.emplace_back(0);
        for (int i = idx; i > 0; i--)
            cnt[f[ord[i]]] += cnt[ord[i]];
    }
} ac;

signed main()
{
    fast;
    cin >> s[0];
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> s[i];
        pos[i] = ac.insert(s[i]);
    }
    ac.build();
    ac.match(s[0]);
    for (int i = 1; i <= k; i++)
        cout << ac.cnt[pos[i]] << '\n';
}

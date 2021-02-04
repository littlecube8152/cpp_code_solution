//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> e[300005], re[300005];
queue<int> q;
int deg[300005] = {0}, val[300005][26] = {{0}}, counter = 0, n, m, res = 0;
string s;

int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].emplace_back(y);
        re[y].emplace_back(x);
        deg[x]++;
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
        {
            q.push(i);
            val[i][s[i - 1] - 'a'] = 1;
        }
    
    while (!q.empty())
    {
        for (int i : e[q.front()])
            for (int j = 0; j < 26; j++)
                val[q.front()][j] = max(val[q.front()][j], val[i][j] + (s[q.front() - 1] - 'a' == j));
        for (int i : re[q.front()])
        {
            deg[i]--;
            if (!deg[i])
                q.push(i);
        }
        q.pop();
        counter++;
    }
    if (counter != n)
        cout << "-1\n";
    else
    {
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 26; j++)
                res = max(res, val[i][j]);
        cout << res << '\n';
    }
}
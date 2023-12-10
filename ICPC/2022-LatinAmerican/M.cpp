#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int N, M, vis[1005][105];
string s[1005];
bitset<105> g[1005], bolt[105];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
        cin >> s[i];
    int ans = 0;
    for (int t = 0; t <= 1; t++)
    {
        for (int i = 1; i <= N; i++)
            for (int j = 0; j < M; j++)
                g[i][j] = s[i][j] == '1', vis[i][j] = 0;

        for (int i = 0; i < M; i++)
            for (int j = 0; j < M; j++)
                bolt[i][j] = s[0][(i + j) % M] == '1';

        queue<pii> q;
        for (int i = 0; i < M; i++)
            q.emplace(pii(0, i)), vis[0][i] = 1;
        while (!q.empty())
        {
            auto [i, j] = q.front();
            if (i == N)
                ans = 1;
            q.pop();
            auto check = [&](int x, int y)
            {
                if (x >= 0 && x <= N && !vis[x][y] && (bolt[y] & g[x]).count() == 0)
                    vis[x][y] = 1, q.emplace(pii(x, y));
            };
            check(i - 1, j);
            check(i + 1, j);
            check(i, (j + 1) % M);
            check(i, (j - 1 + M) % M);
        }
        reverse(all(s[0]));
    }
    if (ans)
        cout << "Y\n";
    else
        cout << "N\n";
}
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, B, f[255], d[255], s[255], vis[255][255];

signed main()
{
    ifstream cin("snowboots.in");
    ofstream cout("snowboots.out");
    cin >> N >> B;
    for (int i = 1; i <= N; i++)
        cin >> f[i];
    for (int i = 1; i <= B; i++)
        cin >> d[i] >> s[i];
    vis[1][1] = 1;
    queue<pii> q;
    q.push({1, 1});
    while(!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        for (int k = j + 1; k <= B; k++)
            if (d[k] >= f[i] && !vis[i][k])
            {
                vis[i][k] = 1;
                q.push({i, k});
            }
        for (int k = 1; k <= s[j]; k++)
            if(i + k <= N && d[j] >= f[i + k] && !vis[i + k][j])
            {
                vis[i + k][j] = 1;
                q.push({i + k, j});
            }
    }
    for (int i = 1; i <= B; i++)
        if(vis[N][i])
        {
            cout << i - 1 << '\n';
            return 0;
        }
}
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, K, color[300005], adj[300005][6], adj2[100005][33];
pii edge[300005];
ll ans;

int encode(int i)
{
    return (1 << (i - 1));
}

signed main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        cin >> color[i];
    for (int i = 1; i <= M; i++)
        cin >> edge[i].F >> edge[i].S;
    if (K >= 2)
    {
        for (int i = 1; i <= M; i++)
            if (color[edge[i].F] != color[edge[i].S])
                ans += 2;
    }
    cerr << ans << '\n';
    if (K >= 3)
    {
        for (int i = 1; i <= M; i++)
            if (color[edge[i].F] != color[edge[i].S])
            {
                adj[edge[i].F][color[edge[i].S]]++;
                adj[edge[i].S][color[edge[i].F]]++;
            }
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= K; j++)
                for (int k = j + 1; k <= K; k++)
                    ans += adj[i][j] * adj[i][k] * 2;
    }
    cerr << ans << '\n';
    if (K >= 4)
    {
        for (int i = 1; i <= M; i++)
            if (color[edge[i].F] != color[edge[i].S])
                for (int j = 1; j <= K; j++)
                    for (int k = 1; k <= K; k++)
                        if (j != k && color[edge[i].F] != k && color[edge[i].S] != j)
                            ans += adj[edge[i].F][j] * adj[edge[i].S][k] * 2;
    }
    cerr << ans << '\n';
    if (K >= 5)
    {
        for (int i = 1; i <= M; i++)
            if (color[edge[i].F] != color[edge[i].S])
            {
                for (int j = 1; j <= K; j++)
                    if (color[edge[i].F] != j)
                        adj2[edge[i].F][encode(color[edge[i].F]) ^ encode(color[edge[i].S]) ^ encode(j)] += adj[edge[i].S][j];
                for (int j = 1; j <= K; j++)
                    if (color[edge[i].S] != j)
                        adj2[edge[i].S][encode(color[edge[i].F]) ^ encode(color[edge[i].S]) ^ encode(j)] += adj[edge[i].F][j];
            }
       
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= K; j++)
                if (j != color[i])
                    for (int k = j + 1; k <= K; k++)
                        if (k != color[i])
                        {
                            ans += adj2[i][encode(color[i]) ^ encode(j) ^ encode(k)] * adj2[i][31 ^ encode(j) ^ encode(k)];
                        }
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define ll long long
using namespace std;

int T;
long long N, M, Q;
bool color[200005], visit[200005];
vector<pii> E[200005];

bool dfs(int k, int l, int r)
{
    
    bool result = true;
    visit[k] = true;
    for (pii p : E[k])
        if (visit[p.F] && (p.S < l || p.S > r))
        {
            if (color[p.F] == color[k])
                result = false;
        }
        else if ((p.S < l || p.S > r))
        {
            color[p.F] = color[k] ^ 1;

            result &= dfs(p.F, l, r);
        }
    return result;
}

void solve()
{
    
    cin >> N >> M >> Q;
    for (int i = 1; i <= M; i++)
    {
        int x, y;
        cin >> x >> y;
        E[x].emplace_back(make_pair(y, i));
        E[y].emplace_back(make_pair(x, i));
    }

    for (int i = 1; i <= Q; i++)
    {
        int l, r;
        bool bipartie = true;

        cin >> l >> r;
        for (int i = 1; i <= N; i++)
            visit[i] = color[i] = 0;
        for (int i = 1; i <= N; i++)
            if (!visit[i])
                bipartie &= dfs(i, l, r);

        if (!bipartie)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    solve();
}
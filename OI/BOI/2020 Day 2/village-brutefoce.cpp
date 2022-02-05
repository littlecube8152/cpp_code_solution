#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, dis[15][15], pre[15][15], optans = 0;
vector<int> E[100005];
vector<int> best;

void dfs(int k, int root)
{

    for (int i : E[k])
        if (i != pre[root][k])
        {
            pre[root][i] = k;
            dis[root][i] = dis[root][k] + 1;
            dfs(i, root);
        }
}

signed main()
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        E[x].emplace_back(y);
        E[y].emplace_back(x);
    }
    vector<int> perm(N);
    for (int i = 1; i <= N; i++)
        dfs(i, i);
    for (int i = 1; i <= N; i++)
        perm[i - 1] = i;

    cin >> optans;
    for (int i = 1; i <= 3628800; i++)
    {
        int ans = 0;
        bool valid = 1;
        for (int i = 0; i < N; i++)
        {
            if (perm[i] == i + 1)
                valid = 0;
            ans += dis[i + 1][perm[i]];
        }

        if (valid)
            if (ans == optans)
            {
                for (int i = 0; i < N; i++)
                    cout << perm[i] << " \n"[i == N - 1];
            }

        next_permutation(perm.begin(), perm.end());
    }
    cout << optans << '\n';
    for (int i = 0; i < N; i++)
        cout << best[i] << " ";
}

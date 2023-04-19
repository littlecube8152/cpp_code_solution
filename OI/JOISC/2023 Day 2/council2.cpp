#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, M, sum[20], ans[300005];
vector<pii> dp[1 << 20];
bitset<20> b[300005];

void simplify(vector<pii> &v)
{
    sort(v.begin(), v.end(), greater<pii>());
    v.resize(unique(v.begin(), v.end(), [&](pii p1, pii p2)
             { return p1.S == p2.S; }) - v.begin());
    if (v.size() >= 2)
        v.resize(2);
}

signed main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a;
            cin >> a;
            b[i][j] = a;
            sum[j] += a;
        }
        dp[b[i].to_ulong()].emplace_back(pii(1, i));
        simplify(dp[b[i].to_ulong()]);
    }
    for (int j = 0; j < M; j++)
        for (int i = 0; i < (1 << M); i++)
            if ((i >> j) & 1)
            {
                for (pii k : dp[i ^ (1 << j)])
                    dp[i].emplace_back(k);
                sort(dp[i].begin(), dp[i].end(), greater<pii>());
                simplify(dp[i]);
            }

    const int all = (1 << M) - 1;
    for (int i = 0; i < (1 << M); i++)
    {
        if ((i ^ all) > i)
            swap(dp[i], dp[i ^ all]);
        for (auto &[val, pos] : dp[i])
            val = __builtin_popcount(i);
    }
    for (int j = 0; j < M; j++)
        for (int i = 0; i < (1 << M); i++)
            if ((i >> j) & 1)
            {
                for (pii k : dp[i ^ (1 << j)])
                    dp[i].emplace_back(k);
                sort(dp[i].begin(), dp[i].end(), greater<pii>());
                simplify(dp[i]);
            }

    for (int i = 1; i <= N; i++)
    {
        int ans = 0;
        bitset<20> cur;
        for (int j = 0; j < M; j++)
        {
            sum[j] -= b[i][j];
            if (sum[j] == N / 2)
                cur[j] = 1;
            else if (sum[j] > N / 2)
                ans++;
        }
        // cout << cur << " = ";
        // for (auto [val, pos] : dp[cur.to_ulong()])
        //     cout << val << ", " << pos << "  ";
        // cout << '\n';
        int mask = cur.to_ulong();
        if (dp[mask].empty() || (dp[mask].size() == 1 && dp[mask][0].S == i))
        {
            //cerr << "no submask ";
            cout << ans << '\n';
        }
        else if (dp[mask][0].S != i)
        {
            //cerr << "submask  0 ";
            cout << ans + dp[mask][0].F << '\n';
        }
        else
        {
            //cerr << "submask  1 ";
            cout << ans + dp[mask][1].F << '\n';
        }
        for (int j = 0; j < M; j++)
            sum[j] += b[i][j];
    }
}

/*
4 12
1 1 1 0 1 1 0 1 0 1 1 0
1 1 0 1 1 0 1 1 1 1 1 0
0 0 1 1 1 0 0 0 0 0 1 1
1 0 0 0 1 1 1 1 1 0 0 0
  *       * *   * * *
*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, K, A[305], B[305], sumA;

void fail(bool args)
{
    if (args)
    {
        cout << "Impossible\n";
        exit(0);
    }
}

bool dfs(int cur, int sum, int finish, int &mask)
{
    if (finish >= K)
        return true;
    if (cur == mask)
        return false;
    bool valid = false;
    for (int i = 0; i < M; i++)
        if ((mask & (1 << i)) && !(cur & (1 << i)))
        {
            if (B[i] >= N)
                valid |= dfs(cur ^ (1 << i), sum, finish + 1, mask);
            else if(sum + B[i] >= N)
                valid |= dfs(cur ^ (1 << i), sum + B[i] - N, finish + 1, mask);
            else
                valid |= dfs(cur ^ (1 << i), sum + B[i], finish, mask);
        }
    return valid;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    assert(M <= 15);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        fail(A[i] < K);
        sumA += A[i];
    }
    for (int i = 0; i < M; i++)
        cin >> B[i];
    int ans = 1e9;
    for (int mask = 0; mask < (1 << M); mask++)
    {
        int tot = 0, restot = 0;
        for (int i = 0; i < M; i++)
            if (mask & (1 << i))
                tot += B[i], restot += min(N, B[i]);
        if (tot < sumA)
            continue;
        bool valid = (restot >= N * K);
        if (valid)
            ans = min(ans, tot - sumA);
    }
    fail(ans >= 1e8);
    cout << ans << '\n';
}
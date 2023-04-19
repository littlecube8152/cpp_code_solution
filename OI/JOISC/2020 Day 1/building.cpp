#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, A[1000006], B[1000006];
const pii emp = pii(0, -1);
pii dp[1000006][2];

pii operator+(pii p, int i)
{
    return pii(p.F + i, p.S + i);
}

pii merge(pii p1, pii p2)
{
    if (p1.S < p1.F)
        return p2;
    if (p2.S < p2.F)
        return p1;
    assert(max(p1.S, p2.S) - min(p1.F, p2.F) + 1 <= p1.S + p2.S - p1.F - p2.F + 2);
    return pii(min(p1.F, p2.F), max(p1.S, p2.S));
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= 2 * N; i++)
        cin >> A[i];
    for (int i = 1; i <= 2 * N; i++)
        cin >> B[i];
    for (int i = 0; i <= 2 * N; i++)
        dp[i][0] = dp[i][1] = emp;
    dp[0][0] = pii(0, 0);
    for (int i = 1; i <= 2 * N; i++)
    {
        if (A[i - 1] <= A[i])
            dp[i][0] = merge(dp[i][0], dp[i - 1][0] + 1);
        if (B[i - 1] <= A[i])
            dp[i][0] = merge(dp[i][0], dp[i - 1][1] + 1);
        if (A[i - 1] <= B[i])
            dp[i][1] = merge(dp[i][1], dp[i - 1][0]);
        if (B[i - 1] <= B[i])
            dp[i][1] = merge(dp[i][1], dp[i - 1][1]);
    }
    string ans;
    int cur = N, i = 2 * N, j = -1;
    if (dp[i][0].F <= cur && cur <= dp[i][0].S)
        j = 0;
    if (dp[i][1].F <= cur && cur <= dp[i][1].S)
        j = 1;
    if (j < 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    while (i)
    {
        ans.push_back(j == 0 ? 'A' : 'B');
        if (j == 0)
        {
            cur--;
            if (A[i - 1] <= A[i] && dp[i - 1][0].F <= cur && cur <= dp[i - 1][0].S)
                i--, j = 0;
            else
                i--, j = 1;
        }
        else
        {
            if (A[i - 1] <= B[i] && dp[i - 1][0].F <= cur && cur <= dp[i - 1][0].S)
                i--, j = 0;
            else
                i--, j = 1;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
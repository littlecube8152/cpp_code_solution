#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const ll MOD = 1000000007;
ll N, Left[4000005], Right[400005], notempty[4000005];
pii dp[400005][2][2];
map<int, int> order;
vector<int> v, w;

void Modify(int L, int R, int i, int p, int v)
{
    notempty[i] = true;
    if (L == R)
    {
        Left[i] = v;
        Right[i] = v;
        dp[i][1][1] = pii{1, 0};
        dp[i][0][0] = pii{0, 1};
    }
    else
    {
        int mid = (L + R) / 2;
        if (p <= mid)
            Modify(L, mid, i * 2, p, v);
        else
            Modify(mid + 1, R, i * 2 + 1, p, v);

        if (!notempty[i * 2])
        {
            Left[i] = Left[i * 2 + 1], Right[i] = Right[i * 2 + 1];
            dp[i][0][0] = dp[i * 2 + 1][0][0];
            dp[i][0][1] = dp[i * 2 + 1][0][1];
            dp[i][1][0] = dp[i * 2 + 1][1][0];
            dp[i][1][1] = dp[i * 2 + 1][1][1];
        }
        else if (!notempty[i * 2 + 1])
        {
            Left[i] = Left[i * 2], Right[i] = Right[i * 2];
            dp[i][0][0] = dp[i * 2][0][0];
            dp[i][0][1] = dp[i * 2][0][1];
            dp[i][1][0] = dp[i * 2][1][0];
            dp[i][1][1] = dp[i * 2][1][1];
        }
        else
        {
            Left[i] = Left[i * 2], Right[i] = Right[i * 2 + 1];
            dp[i][0][0] = pii{
                0, (dp[i * 2][0][0].S * dp[i * 2 + 1][0][0].S +
                    dp[i * 2][0][1].S * dp[i * 2 + 1][0][0].S +
                    dp[i * 2][0][0].S * ((dp[i * 2 + 1][1][0].F * ((Left[i * 2 + 1] - Right[i * 2] - 1) / 2) + dp[i * 2 + 1][1][0].S) % MOD) +
                    dp[i * 2][0][1].S * ((dp[i * 2 + 1][1][0].F * ((Left[i * 2 + 1] - Right[i * 2]) / 2) + dp[i * 2 + 1][1][0].S) % MOD)) %
                       MOD};
            dp[i][0][1] = pii{
                0, (dp[i * 2][0][0].S * dp[i * 2 + 1][0][1].S +
                    dp[i * 2][0][1].S * dp[i * 2 + 1][0][1].S +
                    dp[i * 2][0][0].S * ((dp[i * 2 + 1][1][1].F * ((Left[i * 2 + 1] - Right[i * 2] - 1) / 2) + dp[i * 2 + 1][1][0].S) % MOD) +
                    dp[i * 2][0][1].S * ((dp[i * 2 + 1][1][1].F * ((Left[i * 2 + 1] - Right[i * 2]) / 2) + dp[i * 2 + 1][1][0].S) % MOD)) %
                       MOD};
            dp[i][1][0] = pii{
                (dp[i * 2][1][0].F * dp[i * 2 + 1][0][0].S +
                 dp[i * 2][1][1].F * dp[i * 2 + 1][0][0].S +
                 dp[i * 2][1][0].F * ((dp[i * 2 + 1][1][0].F * ((Left[i * 2 + 1] - Right[i * 2] - 1) / 2) + dp[i * 2 + 1][1][0].S) % MOD) +
                 dp[i * 2][1][1].F * ((dp[i * 2 + 1][1][0].F * ((Left[i * 2 + 1] - Right[i * 2]) / 2) + dp[i * 2 + 1][1][0].S) % MOD)) %
                    MOD,
                (dp[i * 2][1][0].S * dp[i * 2 + 1][0][0].S +
                 dp[i * 2][1][1].S * dp[i * 2 + 1][0][0].S +
                 dp[i * 2][1][0].S * ((dp[i * 2 + 1][1][0].F * ((Left[i * 2 + 1] - Right[i * 2] - 1) / 2) + dp[i * 2 + 1][1][0].S) % MOD) +
                 dp[i * 2][1][1].S * ((dp[i * 2 + 1][1][0].F * ((Left[i * 2 + 1] - Right[i * 2]) / 2) + dp[i * 2 + 1][1][0].S) % MOD)) %
                    MOD};
            dp[i][1][1] = pii{
                (dp[i * 2][1][0].F * dp[i * 2 + 1][0][1].S +
                 dp[i * 2][1][1].F * dp[i * 2 + 1][0][1].S +
                 dp[i * 2][1][0].F * ((dp[i * 2 + 1][1][1].F * ((Left[i * 2 + 1] - Right[i * 2] - 1) / 2) + dp[i * 2 + 1][1][0].S) % MOD) +
                 dp[i * 2][1][1].F * ((dp[i * 2 + 1][1][1].F * ((Left[i * 2 + 1] - Right[i * 2]) / 2) + dp[i * 2 + 1][1][0].S) % MOD)) %
                    MOD,
                (dp[i * 2][1][0].S * dp[i * 2 + 1][0][1].S +
                 dp[i * 2][1][1].S * dp[i * 2 + 1][0][1].S +
                 dp[i * 2][1][0].S * ((dp[i * 2 + 1][1][1].F * ((Left[i * 2 + 1] - Right[i * 2] - 1) / 2) + dp[i * 2 + 1][1][0].S) % MOD) +
                 dp[i * 2][1][1].S * ((dp[i * 2 + 1][1][1].F * ((Left[i * 2 + 1] - Right[i * 2]) / 2) + dp[i * 2 + 1][1][0].S) % MOD)) %
                    MOD};
        }
    }
}

signed main()
{
    int N;
    cin >> N;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> v[i];
    w = v;
    sort(w.begin() + 1, w.end());
    for (int i = 1; i <= N; i++)
        order[w[i]] = i;

    for (int i = 1; i <= N; i++)
    {
        Modify(1, N, 1, order[w[i]], w[i]);
        cout << (dp[1][0][0].S + dp[1][0][1].S + dp[1][1][0].F * ((Left[i] - 1) / 2) + dp[1][1][0].S + dp[1][1][1].F * ((Left[i] - 1) / 2) + dp[1][1][1].S) % MOD << '\n';
    }
}

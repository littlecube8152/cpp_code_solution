#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll MOD = 1e9 + 7;
ll N, M, K;
string s[4105];
ll arr[4105][4105], w[4105], cnt[4105][5];
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        cin >> s[i];
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < M; j++)
            if (s[i][j] == 'A')
                arr[i][j + 1] = 1;
            else if (s[i][j] == 'T')
                arr[i][j + 1] = 2;
            else if (s[i][j] == 'C')
                arr[i][j + 1] = 3;
            else if (s[i][j] == 'G')
                arr[i][j + 1] = 4;
    for (int i = 1; i <= N; i++)
        w[i] = rd() % MOD;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cnt[j][arr[i][j]] += w[i];
    for (int i = 1; i <= N; i++)
    {
        ll totc = 0, totw = 0;
        for (int j = 1; j <= N; j++)
            if(i != j)
                totw = (totw + w[j]) % MOD;
        totw = totw * K % MOD;
        for (int j = 1; j <= M; j++)
        {
            for (int k = 1; k <= 4; k++)
                if(k != arr[i][j])
                    totc = (totc + cnt[j][k]) % MOD;
        }
        if(totc == totw)
        {
            cout << i << '\n';
            return 0;
        }
    }
}
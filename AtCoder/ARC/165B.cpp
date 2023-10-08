#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0), \
             cin.tie(0), cout.tie(0)
using namespace std;

int N, K, P[200005], Q[200005], inc[200005];

signed main()
{
    fast;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> P[i];
    for (int i = 2; i <= N; i++)
        inc[i] = inc[i - 1] + (P[i] > P[i - 1]);
    bool u = 0;
    for (int i = K; i <= N; i++)
        if (inc[i] - inc[i - K + 1] == K - 1)
            u = 1;
    if (!u)
    {
        // find unchanging prefix
        int f = N - K;
        for (int i = f + 1; i <= N; i++)
            Q[i] = max(Q[i - 1], P[i]);

        while (f)
        {
            if (P[f] > P[f + 1])
                break;
            f--;
        }
        f++;
        if (f + K <= N - K || P[N - K] < Q[f + K])
            sort(P + f, P + f + K);
        else
            sort(P + N + 1 - K, P + 1 + N);
    }
    for (int i = 1; i <= N; i++)
        cout << P[i] << " \n"[i == N];
}
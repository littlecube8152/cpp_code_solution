#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, K, A[305], B[305], sumA;
int smalldp[90005], bigdp[90005];

void fail(bool args)
{
    if (args)
    {
        cout << "Impossible\n";
        exit(0);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    fail(K > M);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        fail(A[i] < K);
        sumA += A[i];
    }
    for (int i = 1; i <= M; i++)
        cin >> B[i];
    for (int i = 1; i <= 300 * M; i++)
        bigdp[i] = -500;
    smalldp[0] = 1;
    for (int i = 1; i <= M; i++)
        if (B[i] >= N)
            for (int j = 300 * M; j >= B[i]; j--)
                bigdp[j] = max(bigdp[j], bigdp[j - B[i]] + 1);
        else
            for (int j = 300 * M; j >= B[i]; j--)
                smalldp[j] |= smalldp[j - B[i]];
    vector<int> v;
    set<ll> s;
    s.insert(1e9);
    ll idx = 0;
    for (int i = 0; i <= 300 * M; i++)
        if (bigdp[i] >= 0)
            v.emplace_back(i);
    sort(v.begin(), v.end(), [&](int i1, int i2)
         { return bigdp[i1] > bigdp[i2]; });
    ll ans = 1e9;
    for (int i = 0; i <= 300 * M; i++)
        if (smalldp[i])
        {
            while (idx < v.size() && bigdp[v[idx]] >= max(0LL, (K - i / N)))
            {
                s.insert(v[idx]);
                idx++;
            }
            
            ans = min(ans, i + *s.lower_bound(sumA - i) - sumA);
            //cout << i << " " << ans << '\n';
        }
    fail(ans >= 1e7);
    cout << ans << '\n';
}
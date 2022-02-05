#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct P
{
    ll type, c, f, v;
    P(ll type, ll c, ll f, ll v) : type(type), c(c), f(f), v(v){};
    P() : type(0), c(0), f(0), v(0){};
};

ll M, N, dp[100001], cost, mxsize;
P a[4005], com[2005];

void debug()
{
    if (1)
        for (int i = 1; i <= mxsize; i++)
            cout << dp[i] << " \n"[i == mxsize];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i].c >> a[i].f >> a[i].v;
        a[i].type = 1;
        com[i] = a[i];
    }

    cin >> M;
    for (int i = N + 1; i <= N + M; i++)
    {
        a[i].type = 2;
        cin >> a[i].c >> a[i].f >> a[i].v;
    }

    sort(a + 1, a + 1 + N + M, [](P p1, P p2)
         { return make_pair(p1.f, p1.type) < make_pair(p2.f, p2.type); });

    sort(com + 1, com + 1 + N, [](P p1, P p2)
         { return p1.f < p2.f; });

    for (int i = 1; i <= N; i++)
    {
        com[i].c += com[i - 1].c;
        cost += com[i].v;
    }
    mxsize = com[N].c;

    for (int i = 1; i <= M + N; i++)
    {
        if (a[i].type == 2)
        {
            ll idx = prev(lower_bound(com, com + 1 + N,
                                      P(0, 0, a[i].f, 0), [](P p1, P p2)
                                      { return p1.f < p2.f; }))
                         ->c;
            for (int j = mxsize; j >= idx + a[i].c; j--)
                dp[j] = max({dp[j], dp[j - a[i].c] + a[i].v});
        }
        else
        {
            ll ldx = prev(lower_bound(com, com + 1 + N,
                                      P(0, 0, a[i].f, 0), [](P p1, P p2)
                                      { return p1.f < p2.f; }))
                         ->c;

            ll rdx = prev(upper_bound(com, com + 1 + N,
                                      P(0, 0, a[i].f, 0), [](P p1, P p2)
                                      { return p1.f < p2.f; }))
                         ->c;
            cout << ldx << "-" << rdx << '\n';
            for (int j = rdx; j >= ldx + a[i].c; j--)
                dp[j] = max({dp[j], dp[j - a[i].c] + a[i].v});
                
        }

        debug();

        for (int j = 1; j <= mxsize; j++)
            dp[j] = max(dp[j], dp[j - 1]);
    }
    cout << dp[mxsize] - cost << '\n';
}

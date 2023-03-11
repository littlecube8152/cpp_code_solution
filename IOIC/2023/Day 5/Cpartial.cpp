#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, vis[1505];
pll wall[3005], site[3005];

pll operator-(pll p1, pll p2)
{
    return pll(p1.F - p2.F, p1.S - p2.S);
}
ll cross(pll p1, pll p2)
{
    return p1.F * p2.S - p1.S * p2.F;
}
int ori(pll a, pll b, pll c)
{
    ll cr = cross(b - a, c - a);
    if (cr < 0)
        return -1;
    if (cr > 0)
        return 1;
    return 0;
}

bool banana(pll p1, pll p2, pll p3, pll p4)
{
    int a123 = ori(p1, p2, p3),
        a124 = ori(p1, p2, p4),
        a341 = ori(p3, p4, p1),
        a342 = ori(p3, p4, p2);
    return a123 * a124 < 0 && a341 * a342 < 0;
}

int quadurant(pll p)
{
    if (p.F > 0 && p.S >= 0)
        return 1;
    if (p.F <= 0 && p.S > 0)
        return 2;
    if (p.F < 0 && p.S <= 0)
        return 3;
    return 4;
}

auto query_cmp = [](pair<pll, int> q1, pair<pll, int> q2)
{
    // angle cmp
    auto [p1, w1] = q1;
    auto [p2, w2] = q2;
    if (quadurant(p1) != quadurant(p2))
        return quadurant(p1) < quadurant(p2);
    if (p1.S * p2.F != p2.S * p1.F)
        return p1.S * p2.F < p2.S * p1.F;
    return w1 > w2;
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> site[i].F >> site[i].S;
    cin >> M;
    for (int i = 1; i <= M; i++)
        cin >> wall[i * 2].F >> wall[i * 2].S >> wall[i * 2 + 1].F >> wall[i * 2 + 1].S;

    assert(N <= 500);
    for (int i = 1; i <= N; i++)
    {
        int ans = 0;
        for (int j = 1; j <= N; j++)
            if (j != i)
            {
                bool see = 1;
                for (int k = 1; k <= M; k++)
                    if (banana(pll(0, 0), site[j] - site[i], wall[k * 2 + 1] - site[i], wall[k * 2] - site[i]))
                        see = 0;
                ans += see;
            }
        cout << ans << '\n';
    }
}
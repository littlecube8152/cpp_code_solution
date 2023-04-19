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

    for (int i = 1; i <= N; i++)
    {
        int cur = 0, ans = 0;
        vector<pair<pll, int>> v;
        for (int j = 1; j <= M; j++)
        {
            if (query_cmp(make_pair(wall[j * 2 + 1] - site[i], 0), make_pair(wall[j * 2] - site[i], 0)))
                swap(wall[j * 2 + 1], wall[j * 2]);

            cout << i << " -> " << j << ' ' << (wall[j * 2] - site[i]).F << ' ' << (wall[j * 2] - site[i]).S << ' ' << (wall[j * 2 + 1] - site[i]).F << ' ' << (wall[j * 2 + 1] - site[i]).S << '\n';

            if (banana(pll(0, 0), pll(1'000'000'001, -1),
                       wall[j * 2 + 1] - site[i], wall[j * 2] - site[i]))
            {
                cout << i << " banana " << j << '\n';
                cur++;
                v.emplace_back(make_pair(wall[j * 2] - site[i], -1));
                v.emplace_back(make_pair(wall[j * 2 + 1] - site[i], 1));
            }
            else
            {
                v.emplace_back(make_pair(wall[j * 2] - site[i], 1));
                v.emplace_back(make_pair(wall[j * 2 + 1] - site[i], -1));
            }
        }
        for (int j = 1; j <= N; j++)
            if (j != i)
                v.emplace_back(make_pair(site[j] - site[i], 0));
        sort(v.begin(), v.end(), query_cmp);
        for (auto [_, val] : v)
        {
            cout << i << ' ' << _.F << ' ' << _.S << ' ' << val << ' ' << cur << '\n';
            cur += val;
            if(val == 0)
                ans += (cur == 0);
        }
        cout << ans << '\n';
    }
}
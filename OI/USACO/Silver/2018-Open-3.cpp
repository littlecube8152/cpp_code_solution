#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, c[62505], dsu[62505], rk[62505], idx, ans[2] = {1, 0};
vector<pair<pii, pii>> E;
vector<pii> roll;
map<int, int> mp;

int find(int k)
{
    return k == dsu[k] ? k : find(dsu[k]);
}

void merge(int x, int y, int &ans, bool rb = 0)
{
    if (x == y)
        return;
    if (rk[x] <= rk[y])
    {
        rk[y] += rk[x];
        dsu[x] = y;
        ans = max(ans, rk[y]);
        if (rb)
            roll.emplace_back(pii{x, y});
    }
    else
        merge(y, x, ans, rb);
}

void clear()
{
    while (roll.size())
    {
        auto [x, y] = roll.back();
        rk[y] -= rk[x];
        dsu[x] = x;
        roll.pop_back();
    }
}

signed main()
{
    ifstream cin("multimoo.in");
    ofstream cout("multimoo.out");
    auto pos = [&](int i, int j)
    { return (i - 1) * N + j; };
    cin >> N;
    for (int i = 1; i <= N * N; i++)
        dsu[i] = i, rk[i] = 1;
    for (int i = 1; i <= N * N; i++)
        cin >> c[i];
    for (int x = 1; x <= N; x++)
        for (int y = 1; y <= N; y++)
            for (int dx = x; dx <= min(N, x + 1); dx++)
                for (int dy = y; dy <= min(N, y + 1); dy++)
                    if (abs(dx - x) + abs(dy - y) == 1)
                    {
                        int i = pos(x, y), j = pos(dx, dy);
                        if (c[i] == c[j])
                            merge(find(i), find(j), ans[0]);
                        else
                            E.push_back(pair<pii, pii>{{min(c[i], c[j]), max(c[i], c[j])}, {i, j}});
                    }

    sort(E.begin(), E.end());
    pii pre = {0, 0};
    for (auto [i, e] : E)
    {
        if (i != pre)
            clear();
        pre = i;
        auto [x, y] = e;
        merge(find(x), find(y), ans[1], 1);
    }
    cout << ans[0] << '\n'
         << ans[1] << '\n';
}
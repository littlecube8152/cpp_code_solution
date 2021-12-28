#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;



signed main()
{
    int n, m, ans = 0;
    vector<pii> best;
    cin >> n;
    vector<pii> v;
    m = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            v.emplace_back(make_pair(i, j));

    for (ll mask = 0; mask < 40000; mask++)
    {
        mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
        shuffle(v.begin(), v.end(), rd);
        int deg[1005] = {};
        for (int i = 0; i < m; i++)
        {
            deg[v[i].F]++, deg[v[i].S]++;
            bool valid = true;
            for (int j = 0; j <= i; j++)
                if (__gcd(deg[v[j].F], deg[v[j].S]) != 1)
                    valid = false;
            if (valid && i > ans)
            {
                ans = i + 1;
                best = v;
            }
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < ans; i++)
        cout << "{" << best[i].F << ", " << best[i].S << "},\n";
}
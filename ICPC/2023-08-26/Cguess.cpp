#include <bits/stdc++.h>
using namespace std;
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define ll long long
#define F first
#define S second

int n, a[100005], b[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> pending;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int pivot = 0, type = 0;
    vector<int> sol;
    for (int i = 1; i <= n; i++)
        if (a[i] && b[i])
            pending.emplace_back(i);
        else
        {
            pivot = max(a[i], b[i]);
            if(pivot == a[i])
                type = 1;
        }
    if (pending.size() % 2)
    {
        cout << -1 << '\n';
        return 0;
    }
    auto solve = [&](int p, int q, int r, int s)
    {
        sol.emplace_back(q);
        sol.emplace_back(p);
        sol.emplace_back(pivot);
        sol.emplace_back(q);
        sol.emplace_back(s);
        sol.emplace_back(pivot);
        sol.emplace_back(q);
        sol.emplace_back(s);
        sol.emplace_back(pivot);
        sol.emplace_back(r);
        sol.emplace_back(s);
        sol.emplace_back(pivot);
    };
    if(type)
        sol.emplace_back(pivot);
    for (int i = 0; i < n - 1; i += 2)
        solve(a[pending[i]], b[pending[i]], a[pending[i + 1]], b[pending[i + 1]]);
    if(!type)
        sol.emplace_back(pivot);
    int m = sol.size();
    cout << sol.size() << '\n';
    for (int i = 0; i < m; i++)
        cout << sol[i] << " \n"[i == m - 1];
}
#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, A[1000006], sum, acc[1000006], id[1000006];
vector<pair<ll, pll>> v;
vector<ll> t;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        sum += A[i];
    }
    if (sum % K)
    {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 1; i <= N; i++)
        if (A[i] > sum / K)
        {
            cout << -1 << '\n';
            return 0;
        }
    int cur = 1;
    for (int i = 1; i <= N; i++)
    {
        if (A[i] >= sum / K - acc[cur])
        {
            v.emplace_back(make_pair(acc[cur], pll(cur, i)));
            A[i] -= sum / K - acc[cur];
            cur++;
        }
        if (A[i])
            v.emplace_back(make_pair(acc[cur], pll(cur, i)));
        acc[cur] += A[i];
    }
    v.emplace_back(make_pair(sum / K, pll(0, 0)));
    for (auto [a, p] : v)
        t.emplace_back(a);
    sort(v.begin(), v.end());
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());

    cout << t.size() - 1 << '\n';
    int vdx = 0;
    for (int i = 1; i < t.size(); i++)
    {
        cout << t[i] - t[i - 1];
        while (vdx < v.size() && v[vdx].F <= t[i - 1])
        {
            id[v[vdx].S.F] = v[vdx].S.S;
            vdx++;
        }
        for (int i = 1; i <= K; i++)
            cout << ' ' << id[i];
        cout << '\n';
    }
}

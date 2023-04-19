#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

struct query
{
    int i, T, L, R;
};

ll N, Q, arr[200005], ans[200005], bit[200005];
query q[200005];

void bitmodify(int pos, ll val)
{
    for (int i = pos; i <= N; i += (i & -i))
        bit[i] += val;
}

ll bitquery(int pos)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

signed main()
{
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= Q; i++)
    {
        cin >> q[i].T >> q[i].L >> q[i].R;
        q[i].i = i;
    }
    sort(q + 1, q + 1 + Q, [](query q1, query q2)
         { return q1.T < q2.T; });
    int qdx = 1;
    vector<pll> plus;
    int last = -1e9;
    for (int i = 1; i <= N; i++)
    {
        if (arr[i] == 1)
            plus.emplace_back(pll{i - last, i});
        else
            last = i;
    }
    sort(plus.begin(), plus.end());
    int pdx = 0;
    for (int i = 1; i <= N; i++)
        bitmodify(i, arr[i]);
    for (int i = 1; i <= N; i++)
    {
        while (pdx < plus.size() && plus[pdx].F == i)
        {
            bitmodify(plus[pdx].S, 1);
            pdx++;
        }
        while (qdx <= Q && q[qdx].T == i)
        {
            ans[q[qdx].i] = bitquery(q[qdx].R) - bitquery(q[qdx].L - 1);
            qdx++;
        }
    }
    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';
}
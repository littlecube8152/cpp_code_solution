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

ll N, Q, arr[205], ans[205];
query q[205];

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
    for (int i = 1; i <= N; i++)
    {
        for (int j = N; j >= 1; j--)
            arr[j] = max(arr[j], arr[j - 1]);
        while (qdx <= Q && q[qdx].T == i)
        {
            for (int j = q[qdx].L; j <= q[qdx].R; j++)
                ans[q[qdx].i] += arr[j];
            qdx++;
        }
    }
    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';
}
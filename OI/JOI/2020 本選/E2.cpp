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

ll N, Q, arr[200005], ans[200005];
query q[200005];

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

    int T = q[1].T;
    deque<pll> dq;
    for (int i = 1; i <= N; i++)
    {
        if (!dq.empty() && dq.back().S < i - T)
            dq.pop_back();
        while (!dq.empty() && dq.front().F < arr[i])
            dq.pop_front();
        dq.push_front(pll{arr[i], i});
        arr[i] = dq.back().F;
    }
    for (int i = 1; i <= N; i++)
        arr[i] += arr[i - 1];
    for (int i = 1; i <= Q; i++)
    {
        cout << arr[q[i].R] - arr[q[i].L - 1] << '\n';
    }
}
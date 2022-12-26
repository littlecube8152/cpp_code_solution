#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

ll n, k, p, arr[1000005], ans, diff[1000005], res[1000005];

ll bs(ll l, ll r)
{
    if(l == r)
        return l;
    int cnt = 0;
    ll mid = (l + r) / 2;
    for(int i = 1; i <= n - k + 1; i++)
        if(res[i] <= mid)
            cnt++, i += k - 1;
    if(cnt >= p)
        return bs(l, mid);
    else return bs(mid + 1, r);
}


signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n - 2; i++)
        diff[i] = arr[i + 2] - arr[i];
    deque<pll> dq;
    for (int ldx = 1, rdx = 1; ldx <= n; ldx++)
    {
        while (rdx <= n - 2 && rdx < ldx + k - 2)
        {
            while (!dq.empty() && dq.back().S <= diff[rdx])
                dq.pop_back();
            dq.push_back(pll{rdx, diff[rdx]});
            while (!dq.empty() && dq.front().F < ldx)
                dq.pop_front();
            if (dq.empty())
                res[ldx] = 0;
            else
                res[ldx] = dq.front().S;
            rdx++;
        }
        if(ldx <= n - k + 1)
            res[ldx] = max({res[ldx], arr[ldx + 1] - arr[ldx], arr[ldx + k - 1] - arr[ldx + k - 2]});
    }
    
    cout << bs(0, 1e9) << '\n';
}
/*
14 6 2
1 3 4 4 5 5 6 6 6 6 7 8 8 9
*/
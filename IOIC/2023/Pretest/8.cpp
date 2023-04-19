#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N;
ll C, h[200005], dp[200005];

template <typename T>
struct light_deque
{
    T dq[200005];
    int l = 0, r = 0;
    void emplace_back(T t)
    {
        dq[r] = t;
        ++r;
    }
    void pop_back()
    {
        --r;
    }
    void pop_front()
    {
        ++l;
    }
    int size()
    {
        return r - l;
    }
    T operator[](int idx)
    {
        return dq[l + idx];
    }
};

//   (h_i - h_j) ^ 2 + C
// = h_i^2 - 2h_ih_j + h_j^2 + C

inline ll intersect(pll l1, pll l2)
{
    // a1 x + b1 = a2 x + b2
    ll a = l1.F - l2.F, b = l2.S - l1.S;
    return (b + a - 1) / a;
}

inline ll cost(pll l, ll x)
{
    return l.F * x + l.S;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> C >> h[1];

    light_deque<pll> dq;
    dq.emplace_back(pll(-2 * h[1], h[1] * h[1]));
    for (int i = 2; i <= N; i++)
    {
        cin >> h[i];
        while (dq.size() >= 2 && cost(dq[0], h[i]) > cost(dq[1], h[i]))
            dq.pop_front();

        dp[i] = cost(dq[0], h[i]) + h[i] * h[i] + C;
        pll l = pll(-2 * h[i], dp[i] + h[i] * h[i]);

        int j = dq.size();
        while (j >= 2 && intersect(dq[j - 2], dq[j - 1]) >= intersect(dq[j - 1], l))
        {
            dq.pop_back();
            j--;
        }
        dq.emplace_back(l);
    }
    cout << dp[N] << '\n';
}
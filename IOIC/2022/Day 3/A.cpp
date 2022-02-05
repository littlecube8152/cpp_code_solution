#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, a[500005], b, dp[500005];

struct trans
{
    ll i, a, b;
    ll operator()(int x)
    {
        return a * x + b;
    }
};

ll intersect(trans t1, trans t2)
{
    ll actual;
    if (t2.a == t1.a)
    {
        if (t2.b >= t1.b)
            actual = -1;
        else
            actual = 1e9;
    }
    else
        actual = (t1.b - t2.b) / (t2.a - t1.a);
    return min(actual, t1.i + K);
}

int main()
{
    cin >> N >> K >> b;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    deque<trans> dq;
    dp[1] = a[1];
    dq.push_back(trans{1, 2LL * b, dp[1] - b});
    for (ll i = 2; i <= N; i++)
    {

        // dp[i] = max(dp[i'] - b * i'^2 + 2b * i * i') + a[i] - b * i^2
        //       = max(2bi' * i)
        while (dq.front().i < i - K)
            dq.pop_front();
        while (dq.size() >= 2 && dq[0](i) <= dq[1](i))
            dq.pop_front();
        //for (auto i : dq)
        //    printf("(%lld, %lld, %lld) ", i.i, i.a, i.b);
        //cout << '\n';
        dp[i] = dq.front()(i) + a[i] - b * i * i;
        trans cur{i, 2LL * b * i, dp[i] - b * i * i};
        while (dq.size() >= 2 && intersect(dq.back(), cur) - intersect(dq[dq.size() - 2], dq.back()) < 1)
        {
            //cout << "killed " << intersect(dq[dq.size() - 2], dq.back()) << " " << intersect(dq.back(), cur) << '\n';
            dq.pop_back();
        }
        dq.push_back(cur);
    }
    //for (ll i = 1; i <= N; i++)
    //    cout << dp[i] << " ";
    cout << dp[N] << '\n';
}
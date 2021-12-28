
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define ld long double
using namespace std;

struct query
{
    int id, q;
    ld ans;
};

ll N, Q, arr[7005], idx = 0;
ld dp[7005][2];
vector<query> v;

ld value(int i, int j)
{
    if (i > j)
        return 0.0;
    ld raw = arr[j] - arr[i - 1];
    ld radius = sqrtl(raw / 4.0 / acosl(-1));
    return raw * radius / 3.0;
}

void transfer(int j, int dpL, int dpR, int ansL, int ansR)
{
    if (dpL > dpR)
        return;

    int mid = (dpL + dpR) / 2, best = 0;
    dp[mid][j] = 1e18;
    for (int i = ansL; i <= min(mid, ansR); i++)
        if (dp[i][j ^ 1] + value(i + 1, mid) < dp[mid][j])
            dp[mid][j] = dp[i][j ^ 1] + value(i + 1, mid), best = i;

    if (dpL == dpR)
        return;

    transfer(j, dpL, mid - 1, ansL, best);
    transfer(j, mid + 1, dpR, best, ansR);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cin >> Q;
    v.resize(Q);
    for (int i = 0; i < Q; i++)
    {
        v[i].id = i;
        cin >> v[i].q;
    }

    sort(v.begin(), v.end(), [](query q1, query q2)
         { return q1.q < q2.q; });
    for (int i = 2; i <= N; i++)
        arr[i] += arr[i - 1];

    dp[0][0] = 0;
    for (int i = 1; i <= N; i++)
        dp[i][0] = 1e18;

    for (int j = 1; j <= 3000; j++)
    {
        transfer(j & 1, 0, N, 0, N);
        while (idx < v.size() && v[idx].q == j)
            v[idx++].ans = dp[N][j & 1];
    }

    sort(v.begin(), v.end(), [](query q1, query q2)
         { return q1.id < q2.id; });

    cout << fixed << setprecision(10);

    for (auto q : v)
        cout << q.ans << '\n';
}

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll cross(pll p1, pll p2)
{
    return p1.F * p2.S - p1.S * p2.F;
}
pll operator+(pll p1, pll p2)
{
    return pll(p1.F + p2.F, p1.S + p2.S);
}

int N;
pll p[200005];
ll adj[200005], sum;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> p[i].F >> p[i].S;
    for (int i = 0; i < N; i++)
        sum += adj[i] = cross(p[(i + N - 1) % N] + p[i], p[i] + p[(i + 1) % N]);

    for (int i = 0; i < N; i++)
    {
        cout << abs(sum - adj[(i + N - 1) % N] - adj[i] - adj[(i + 1) % N] +
                    2 * cross(p[i], p[(i + 1) % N] + p[(i + 2) % N]) +
                    2 * cross(p[(i + N - 1) % N] + p[(i + N - 2) % N], p[i]))
             << '\n';
    }
}
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, K, L[200005], R[200005], U[200005], D[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> K;
    int l = 0, r = 1e9, d = 0, u = 1e9;
    for (int i = 1; i <= N; i++)
    {
        cin >> L[i] >> D[i] >> R[i] >> U[i];
        l = max(l, L[i]), d = max(d, D[i]);
        r = min(r, R[i]), u = min(u, U[i]);
    }
    cout << l << ' ' << d << '\n';
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll floorsum(ll A, ll B, ll C, ll N)
{
    if (A == 0)
        return (N + 1) * (B / C);
    if (A > C || B > C)
        return (N + 1) * (B / C) + N * (N + 1) / 2 * (A / C) + floorsum(A % C, B % C, C, N);
    ll M = (A * N + B) / C;
    return N * M - floorsum(C, C - B - 1, A, M - 1);
}

signed main()
{
    ll T, A, B, C, N;
    cin >> T;
    while (T--)
    {
        cin >> N >> C >> A >> B;
        cout << floorsum(A, B, C, N - 1) << '\n';
    }
}
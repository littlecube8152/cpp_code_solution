#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ld N;
ld X, Y, arr[1000005], v[1000005];
ld bs(ld L, ld R)
{
    ld lmid = (2.0 * L + R) / 3.0, rmid = (L + 2.0 * R) / 3.0;
    ld lres = sqrtl((arr[1] - arr[0]) * (arr[1] - arr[0]) + lmid * lmid) / v[1] + sqrtl((arr[2] - arr[1]) * (arr[2] - arr[1]) + (Y - lmid) * (Y - lmid)) / v[2];
    ld rres = sqrtl((arr[1] - arr[0]) * (arr[1] - arr[0]) + rmid * rmid) / v[1] + sqrtl((arr[2] - arr[1]) * (arr[2] - arr[1]) + (Y - rmid) * (Y - rmid)) / v[2];
    if(abs(R - L) <= 1e-8)
        return lres;
    if(lres < rres)
        return bs(L, rmid);
    else
        return bs(lmid, R);
}

signed main()
{
    cin >> X >> Y >> N;
    if (N != 2)
        return 0;
    for (int i = 0; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= N; i++)
        cin >> v[i];

    cout << fixed << setprecision(10) << bs(0, Y) << '\n';
}
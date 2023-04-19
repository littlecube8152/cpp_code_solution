#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, A[300005], B[300005];

signed main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];
    ll L = 1, R = 1000000000000000000LL, mid, tot;
    while (L < R)
    {
        mid = (L + R + 1) / 2;
        tot = 0;
        for (int i = 1; i <= N; i++)
        {
            if (A[i] < B[i])
                tot += (mid - 1) / B[i] + 1;
            else if (A[i] * M < mid)
                tot += M + (mid - A[i] * M - 1) / B[i] + 1;
            else
                tot += (mid - 1) / A[i] + 1;
            if(tot > N * M)
                break;
        }
        if (tot <= N * M)
            L = mid;
        else
            R = mid - 1;
    }
    cout << L << '\n';
}
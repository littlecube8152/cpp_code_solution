#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, Q, A[200005], sz[200005], X, cur, idx = 1;

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        for (int j = 0; j <= 30; j++)
            if (A[i] % (1 << j) == 0)
                sz[i] = (1 << j);
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> X;
        while (cur + sz[idx] < X)
        {
            cur += sz[idx];
            idx++;
        }
        cout << A[idx] / sz[idx] << '\n';
    }
}
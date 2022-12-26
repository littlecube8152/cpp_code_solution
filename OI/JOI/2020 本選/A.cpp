#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, A[200005], B[200005], pre[2][200005], order[200005], ans[200005];

signed main()
{
    cin >> N;
    for (int i = 1; i <= N + 1; i++)
        cin >> A[i];
    for (int i = 1; i <= N + 1; i++)
        order[i] = i;
    sort(order + 1, order + 2 + N, [&](int i, int j)
         { return A[i] < A[j]; });
    sort(A + 1, A + 2 + N);
    for (int i = 1; i <= N; i++)
        cin >> B[i];
    sort(B + 1, B + 1 + N);
    for (int j = 0; j <= 1; j++)
        for (int i = 1; i <= N; i++)
            pre[j][i] = max(0, A[i + j] - B[i]);
    for (int i = 1; i <= N; i++)
        pre[0][i] = max(pre[0][i], pre[0][i - 1]);
    for (int i = N; i >= 1; i--)
        pre[1][i] = max(pre[1][i], pre[1][i + 1]);
    for (int i = 1; i <= N + 1; i++)
        ans[order[i]] = max(pre[0][i - 1], pre[1][i]);
    for (int i = 1; i <= N + 1; i++)
        cout << ans[i] << " \n"[i == N + 1];
}
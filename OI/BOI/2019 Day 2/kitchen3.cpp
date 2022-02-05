#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, K, A[305], B[305], sumA;

bitset<90005> b;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    assert(K == 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        sumA += A[i];
    }
    b[0] = 1;
    for (int i = 1; i <= M; i++)
    {
        cin >> B[i];
        b |= (b << B[i]);
    }
    for (int i = sumA; i <= 300 * 300; i++)
        if (b[i])
        {
            cout << i - sumA << '\n';
            return 0;
        }
    cout << "Impossible\n";
}
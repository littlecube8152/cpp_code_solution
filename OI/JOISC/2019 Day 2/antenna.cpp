#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, Q, A[2005], B[2005], H[2005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i] >> H[i];
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int L, R;
        for (int j = L; j <= R; j++)
            for (int k = j + 1; k <= R; k++)
    }
}
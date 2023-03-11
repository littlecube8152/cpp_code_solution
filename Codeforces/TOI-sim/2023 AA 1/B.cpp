#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
int N, A, B, p[200005], q[200005];
ll ans, C[5005][5005];

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i];
    cin >> A;
    for (int i = 1; i <= N; i++)
        cin >> q[i];
    cin >> B;

    for (int i = A; i <= N; i++)
    {
        set<int> st;
        for (int j = 1; j <= A; j++)
            st.insert(p[j]);
        for (int j = 1; j <= B - 1; j++)
            st.insert(q[j]);

        for (int j = B; j <= N; j++)
        {
            st.insert(q[j]);
            if (st.size() == A + B && p[i] != q[j])
                ans = (ans + C[A + B - 2][]) % mod;
        }
    }
}

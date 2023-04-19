#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int T = 1'000'000'000;

int N, Q, L[2005], R[2005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i < N; i++)
    {
        cin >> L[i] >> R[i];
        R[i]--;
    }
    for (int i = 1; i <= Q; i++)
    {
        int T, A, B, C, D;
        cin >> T;
        if (T == 1)
        {
            cin >> A >> B >> C;
            L[A] = B;
            R[A] = C - 1;
        }
        else
        {
            cin >> A >> B >> C >> D;
            if (A < C)
            {
                ll ans = 0, t = B;
                for (int i = A; i < C; i++)
                {
                    if (t < L[i])
                        t = L[i];
                    else if (t > R[i])
                        ans += t - R[i], t = R[i];
                    t++;
                }
                ans += max(0LL, t - D);
                cout << ans << '\n';
            }
            else if (C < A)
            {
                ll ans = 0, t = B;
                for (int i = A - 1; i >= C; i--)
                {
                    if(t < L[i])
                        t = L[i];
                    else if(t > R[i])
                        ans += t - R[i], t = R[i];
                    t++;
                }
                ans += max(0LL, t - D);
                cout << ans << '\n';
            }
            else
                cout << max(0LL, B - D) << '\n';
        }
    }
}
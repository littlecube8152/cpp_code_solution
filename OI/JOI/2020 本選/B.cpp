#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, K, J[200005], O[200005], I[200005];
int ans = 1e6;
char S[200005];

signed main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> S[i];
    deque<int> dq;
    J[N + 1] = O[N + 1] = I[N + 1] = N + 1;
    for (int i = N; i >= 1; i--)
    {
        if (S[i] == 'I')
            dq.emplace_front(i);
        if (dq.size() > K)
            dq.pop_back();
        if (dq.size() == K)
            I[i] = dq.back();
        else
            I[i] = N + 1;
        I[i] = min(I[i], I[i + 1]);
    }
    dq.clear();
    for (int i = N; i >= 1; i--)
    {
        if (S[i] == 'O')
            dq.emplace_front(i);
        if (dq.size() > K)
            dq.pop_back();
        if (dq.size() == K)
            O[i] = I[dq.back()];
        else
            O[i] = N + 1;
        O[i] = min(O[i], O[i + 1]);
    }
    dq.clear();
    for (int i = N; i >= 1; i--)
    {
        if (S[i] == 'J')
            dq.emplace_front(i);
        if (dq.size() > K)
            dq.pop_back();
        if (dq.size() == K)
            J[i] = O[dq.back()];
        else
            J[i] = N + 1;
        if (J[i] <= N)
            ans = min(ans, J[i] - i + 1 - K * 3);
    }
    cout << (ans > N ? -1 : ans) << '\n';
}
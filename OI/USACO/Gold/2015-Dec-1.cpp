#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, a[100005], c[100005], ans;
deque<int> dq;

signed main()
{
    fast;
    ifstream cin("cardgame.in");
    ofstream cout("cardgame.out");

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        c[a[i]] = i;
    }
    for (int i = 1; i <= 2 * N; i++)
        if (!c[i])
            dq.push_back(i);
    for (int i = 2 * N; i >= 1; i--)
        if (0 < c[i] && c[i] <= N / 2 && dq.back() > i)
        {
            dq.pop_back();
            ans++;
        }
    for (int i = 1; i <= 2 * N; i++)
        if (c[i] > N / 2 && dq.front() < i)
        {
            dq.pop_front();
            ans++;
        }
    cout << ans << '\n';
}
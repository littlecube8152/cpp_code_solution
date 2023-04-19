#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, arr[500005], ans, peak, ispeak[500005], getpeak[500005];

void solve()
{
    cin >> N;

    set<pii> st;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        auto iter = st.lower_bound(pii{arr[i], 0});
        if (iter == st.end())
            ispeak[i]++, peak++;
        else if (next(iter) == st.end())
            getpeak[iter->S]++;
        st.insert(pii{arr[i], i});
    }
    ans = peak;
    for (int i = 1; i <= N; i++)
        ans = max(ans, peak - ispeak[i] + getpeak[i]);
    cout << ans << '\n';
    ans = 0, peak = 0;
    for (int i = 1; i <= N; i++)
        ispeak[i] = getpeak[i] = 0;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}
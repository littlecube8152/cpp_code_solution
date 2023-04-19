#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, a[500005], cnt[500005];
ll ans;


ll calc(vector<int> L, vector<int> R, function<bool(int, int)> f)
{
    int mL = 1e9, rdx = 0;
    ll res = 0;
    for (auto i : L)
    {
        mL = min(mL, i);
        while (rdx < R.size() && f(R[rdx], mL))
            cnt[R[rdx++]]++;
        
        // |a_l - a_r| = min(a_[l, r])
        // a_l - min(a_[l, r]) = a_r or a_l + min(a_[l, r]) = + a_r
        res += (i - mL >= 0 ? cnt[i - mL] : 0) + cnt[i + mL];
    }
    for (auto i : R)
        cnt[i] = 0;
    return res;
}

void dc(int L, int R)
{
    if (L == R)
        return;
    int mid = (L + R) / 2;
    vector<int> left(a + L, a + mid + 1), right(a + mid + 1, a + R + 1);
    reverse(left.begin(), left.end());
    ans += calc(left, right, greater<int>());
    ans += calc(right, left, greater_equal<int>());
    dc(L, mid);
    dc(mid + 1, R);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    dc(1, N);
    cout << ans << '\n';
}
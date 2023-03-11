#include <bits/stdc++.h>
#define ll long long
using namespace std;

string st;
int n, s[2000006], p[2000006];

ll check(int k)
{
    ll ans = 0;
    for (int j = n; j <= 2 * n - 1; j++)
    {
        p[s[j - n]]++;
        if (s[j] >= k)
            ans += p[s[j] - k];
    }
    for (int j = n; j <= 2 * n - 1; j++)
        p[s[j - n]]--;
    // cout << k << ' ' << ans << '\n';
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> st;
    for (int i = 1; i <= 2 * n - 1; i++)
        s[i] = (s[i - 1]) + (st[i - 1] == 'W');

    int L = s[n], R = s[2 * n - 1];
    for (int i = L; i <= R; i++)
        cout << check(i) << " \n"[i == R];
        
    while (L < R)
    {
        int mid = (L + R) / 2;
        if (check(mid) >= check(mid + 1))
            R = mid;
        else
            L = mid + 1;
    }
    assert(check(L) >= n);
    cout << L << '\n';
}
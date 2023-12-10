#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int mod = 1'000'000'007;
int ans = 0;
vector<int> v;
// 10: 5, 4, 6
void solve(int k, int last)
{

    if (k == 0)
    {
        bitset<10> b = 1;
        for (int i : v)
            b |= (b << i);
        if (b[9])
            return;
        if (v.size() >= ans)
            ans = max(ans, (int)v.size());
            
        return;
    }
    for (int i = 1; i <= min(k, last); i++)
    {
        v.emplace_back(i);
        solve(k - i, i);
        v.pop_back();
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if (n <= 41)
    {
        solve(n, n);
        cout << ans << '\n';
    }
    else 
    {
        if (n % 2 == 0)
            cout << (n / 2) % mod;
        else 
            cout << (((n - 11) / 2) + 1) % mod << '\n';
    }
}
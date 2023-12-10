#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int n, d, z[200005];
string s;


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s >> d;
    n = s.size();
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        int mx = j;
        z[j] = 0;
        for (int i = j + 1; i <= j + d && i < s.size(); i++)
        {
            if (i < z[mx] + mx)
                z[i] = min(z[mx] - i + mx, z[j + i - mx]);
            while(z[i] + i < s.size() && s[i + z[i]] == s[j + z[i]])
                z[i]++;
            if (z[i] + i > z[mx] + mx) mx = i;
        }
        ans++;
        j = max(j + d - 1, z[mx] + mx - 1);
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

string s, t;
int N;

vector<int> z(string s)
{
    int n = s.size();
    vector<int> Z(n, 0);
    Z[0] = 0;
    for (int i = 1, mx = 0; i < n; i++)
    {
        if (i < Z[mx] + mx)
            Z[i] = min(Z[mx] - i + mx, Z[i - mx]);
        while (Z[i] + i < n && s[i + Z[i]] == s[Z[i]])
            Z[i]++;
        if (Z[i] + i > Z[mx] + mx)
            mx = i;
    }
    return Z;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    cin >> N;
    while (N--)
    {
        cin >> t;
        string str = t + '$' + s;
        vector<int> Z = z(str);
        int ans = -1;
        for (int i = t.size() + 1; i < str.size(); i++)
            if (Z[i] + i == str.size())
                ans = max(ans, min(Z[i], (int)t.size() - Z[i]));
        cout << ans << '\n';
    }
}
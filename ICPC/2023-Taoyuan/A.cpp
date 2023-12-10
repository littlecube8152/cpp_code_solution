#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int T;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        while (s.size() % 3)
            s.push_back('0');
        int sum = 0;
        int p = 1;
        for (int i = 0; i < s.size(); i += 3, p *= -1)
        {
            string t = s.substr(i, 3);
            reverse(t.begin(), t.end());
            sum = sum + stoi(t) * p;
        }
        cout << abs(sum) << ' ' << (sum % 13 == 0 ? "YES\n" : "NO\n");
    }
}
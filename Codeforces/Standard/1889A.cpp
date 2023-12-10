#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        vector<int> sol;
        cin >> n >> s;
        if (n % 2 == 1)
            cout << -1 << '\n';
        else
        {
            int k = 301;
            while (k--)
            {
                bool flag = 1;
                n = s.size();
                for (int i = 0; i < n; i++)
                    if (s[i] == s[n - 1 - i])
                    {
                        if (s[i] == '1')
                            sol.emplace_back(i);
                        else
                            sol.emplace_back(n - i);
                        flag = 0;
                        break;
                    }
                if (flag)
                    break;
                s.insert(s.begin() + sol.back(), '1');
                s.insert(s.begin() + sol.back(), '0');
            }
            if (sol.size() > 300)
            {
                cout << -1 << '\n';
                continue;
            }
            cout << sol.size() << '\n';
            for (auto i : sol)
                cout << i << ' ';
            cout << '\n';
        }
    }
}
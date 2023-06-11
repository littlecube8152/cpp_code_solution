/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
            cout << -1 << '\n';
        else
        {
            vector<int> sol;
            while(n != 1)
            {
                int a = (n + 1) / 2, b = (n - 1) / 2;
                if(a % 2 == 1)
                {
                    sol.emplace_back(1);
                    n = a;
                }
                else
                {
                    sol.emplace_back(2);
                    n = b;
                }
            }
            reverse(sol.begin(), sol.end());
            int k = (int)sol.size();
            cout << k << '\n';
            for (int i = 0; i < k; i++)
                cout << sol[i] << " \n"[i + 1 == k];
        }
    }
}

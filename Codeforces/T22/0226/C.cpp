//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, c, ans[500005], mdf;
set<int> edit;

signed main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == c)
        {
            ans[c]++;
            vector<int> del;
            for (int j : edit)
            {
                if (ans[j] == 1)
                    del.emplace_back(j);
                ans[j]--;
            }
            for (int j : del)
                edit.erase(j);
        }
        else
        {
            ans[x] = max(1, ans[x] + 1);
            mdf = max(mdf, ans[x]);
            edit.insert(x);
        }
    }
    cout << ans[c] + mdf;
}
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

int cnt[200005], a[200005];
multiset<int> st;


signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
            cnt[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
            st.insert(a[i]);
        }
        for (int i = 1; i <= q; i++)
        {
            int x, y, mx, ans = mx;
            cin >> x >> y;
            cnt[a[x]]--;
            cnt[y]++;
            st.erase(st.find(a[x]));
            st.insert(y);
            a[x] = y;
            mx = *st.begin();
            for (int j = 0; j <= max(mx, 20); j++)
            {
                
            }
        }
    }
}

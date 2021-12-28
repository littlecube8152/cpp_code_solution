//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, r;
set<int> st;

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if (x % 2 == 0)
        {
            if(st.count(x))
            {
                cout << 0;
                return 0;
            }
            r++, st.insert(x);
        }
    }
    cout << r;
}
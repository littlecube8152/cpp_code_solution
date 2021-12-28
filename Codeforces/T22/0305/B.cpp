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

int n, m;
set<pair<int, string>> st;
signed main()
{
    cin >> n >> m;
    while (n--)
    {
        int sum = 0, x;
        string s;
        cin >> s;
        for (int i = 1; i <= m; i++)
        {
            cin >> x;
            sum += x;
        }
        st.insert(make_pair(-sum, s));
    }
    cout << st.begin()->second;
}
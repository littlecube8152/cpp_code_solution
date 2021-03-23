#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n;
stack<pii> st;

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        int x;
        cin >> x;
        while(!st.empty() && x <= st.top().S)
            st.pop();
        if(st.empty())
            cout << 0 << " ";
        else 
            cout << st.top().F << " ";
        st.push(make_pair(i, x));
    }
}
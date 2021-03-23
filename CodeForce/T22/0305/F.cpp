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

int n, m, a[100005], c;

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    { 
         
        cin >> a[i];
        c += a[i];
    }

    for (int i = 0; i < m; i++)
    {
        int k, l;
        cin >> k >> l;
        if (k == 1)
        {
            if (a[l] == 1)
                c--, a[l] = 0;
            else
                c++, a[l] = 1;
        }
        else
        {
            if (c >= l)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}
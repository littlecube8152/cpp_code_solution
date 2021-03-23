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

int n, a, b, k[105];

signed main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= a;i++)
    {
        int x;
        cin >> x;
        k[x] = 1;
    }
    for (int i = 1; i <= b;i++)
    {
        int x;
        cin >> x;
        if(k[x] != 1)
            k[x] = 2;
    }
    for (int i = 1; i <= n;i++)
        cout << k[i] << " ";
}
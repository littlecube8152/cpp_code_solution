//
//
//      Codeforce 842A
//
//
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    ll l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for (int i = x; i <= y;i++)
    if(l<=i * k && i*k<=r){
        cout << "YES\n";
        return 0;
    }
        cout << "NO\n";
        
}
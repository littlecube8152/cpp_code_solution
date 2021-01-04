#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;


int main()
{
    ll m, n, p, q = 9999999999999, r = 1;
    
    cin >> m >> n >> p;
    for (int i = 1; i <= m; i++){
        r *= i;
        r %= p;
    }
    r += (n % p) * (q % p);
    r %= p;
    cout << r << '\n';
}
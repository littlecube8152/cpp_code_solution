#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;
 
ll b[500000];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n;i++)
            cin >> b[i];
        
        ll r = 0;
        for (int j = 0; j < n;j++){
            ll x = 0, y = 0, t;
            for (int i = 0; i < n; i++){
                t = b[i] & b[j];
                x += t;
                x %= MOD;
            }
            for (int k = 0; k < n; k++){
                t = b[k] | b[j];
                y += t;
                y %= MOD;
            }
            r += x * y;
            r %= MOD;
        }
        cout << r << '\n';
    }
}
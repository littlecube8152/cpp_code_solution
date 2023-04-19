#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    for(int B = 1; B <= 20; B++)
        cout << B << ' ' << 4000 + 4000 * ((4000 + B - 1) / B) + 200000 * ((B - 2) / 2) << '\n';
}
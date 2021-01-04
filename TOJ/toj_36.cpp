#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

ll a, b, c;

ll fast(ll base, ll pow)
{
    if (pow == 0)
        return 1;
    else if (pow == 1)
        return base;
    else if (pow % 2)
        return fast(base, pow - 1) * base % c;
    else
    {
        int half = fast(base, pow / 2) % c;
        return half * half % c;
    }
}
int main()
{
    cin >> a >> b >> c;
    a %= c;
    a = fast(a, b) % c;
    cout << a << '\n';
}
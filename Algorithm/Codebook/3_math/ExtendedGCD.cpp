#include <bits/stdc++.h>
#define ll long long
using namespace std;

// beware of negative numbers!
void extgcd(ll a, ll b, ll c, ll &x, ll &y)
{
    if (b == 0)
        x = c / a, y = 0;
    else
    {
        extgcd(b, a % b, c, y, x);
        y -= x * (a / b);
    }
}
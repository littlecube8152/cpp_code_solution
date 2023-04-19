#include <bits/stdc++.h>
using namespace std;

// Notice the sign of a, b 
void extgcd(long long a, long long b, long long c, long long &x, long long &y)
{
    if (b == 0)
        x = c / a, y = 0;
    else
    {
        extgcd(b, a % b, c, y, x);
        y -= x * (a / b);
    }
}

int main()
{
    long long x, y;
    extgcd(175196010, 796754844, __gcd(175196010, 796754844), x, y);
    cout << x * 175196010 + y * 796754844 << " " << __gcd(175196010, 796754844);
}
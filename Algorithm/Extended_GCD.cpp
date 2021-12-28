#include <bits/stdc++.h>
using namespace std;

// Notice the sign of a, b 
void exgcd(int a, int b, int c, int &x, int &y)
{
    if (b == 0)
        x = c / a, y = 0;
    else
    {
        exgcd(b, a % b, c, y, x);
        y -= x * (a / b);
    }
}

int main()
{
    int x, y;
    exgcd(7, 12, -1, x, y);
    cout << x << ' ' << y;
}
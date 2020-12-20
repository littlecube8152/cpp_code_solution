#include <bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a,int b){
    while(b != 0){
        a %= b;
        swap(a, b);
    }
    return a;
}


int main()
{
    int n, a, b, GCD, gear[10010] = {0}, result = 2147483646;

    cin >> n >> a >> b;
    GCD = gcd(a, b);
    a /= GCD;
    b /= GCD;

    for (int i = 0; i < n; i++)
    {
        int speed, money;
        cin >> speed >> money;
        if (gear[speed] != 0)
        {
            gear[speed] = min(gear[speed], money);
        }
        else
        {
            gear[speed] = money;
        }
    }

    if (a == b)
    {
        cout << "0\n";
        return 0;
    }
    for (int i = b; i <= 10000; i += b)
    {
        if (gear[i] != 0 && a * i / b <= 10000)
        {

            if (gear[a * i / b] != 0)
            {

                result = min(result, gear[i] + gear[a * i / b]);
            }
        }
    }
    if (result == 2147483646)
    {
        cout << "-1\n";
    }
    else
    {
        cout << result << '\n';
    }
}
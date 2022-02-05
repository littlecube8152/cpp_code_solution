#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
using namespace std;
#define ll long long

ll N, x;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> x;
    for (int i = 1; i <= N; i++)
    {
        char c1, c2;
        ll b1, b2, r1, r2;
        cin >> c1 >> b1 >> c2 >> b2;
        if (c1 == '+')
            r1 = x + b1;
        else if (c1 == '-')
            r1 = x - b1;
        else if (c1 == '*')
            r1 = x * b1;
        else if (c1 == '/')
            r1 = x / b1;

        if (c2 == '+')
            r2 = x + b2;
        else if (c2 == '-')
            r2 = x - b2;
        else if (c2 == '*')
            r2 = x * b2;
        else if (c2 == '/')
            r2 = x / b2;
        x = max(r1, r2);
        if (x < 0)
        {
            cout << "99% cannot pass this level QQ\n";
            return 0;
        }
        else if(x >= 80000000)
        {
            cout << "ORZCK\n";
            return 0;
        }
        
    }
    cout << x << '\n';
}
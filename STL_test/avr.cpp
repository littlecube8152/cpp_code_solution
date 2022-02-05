#include <bits/stdc++.h>
using namespace std;

double a, b;
string s;
signed main()
{
    for (int i = 1; i <= 10; i++)
        cin >> b >> s, a += b;
    cout << fixed << setprecision(3) << a / 10.0 << '\n';
}
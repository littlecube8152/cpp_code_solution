#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, a1, b1, c1, a2, b2, c2, r = -100000000;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> n;
    for (int i = 0; i <= n; i++)
        r = max(r, a1 * i * i + b1 * i + c1 + a2 * (n - i) * (n - i) + b2 * (n - i) + c2);
    cout << r << '\n';
}
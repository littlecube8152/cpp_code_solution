#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 3; i++)
        cout << 1 << ' ' << fixed << setprecision(20) << double(i) * 1e-20 << '\n';
        cout << "0 1\n-1 0\n";
}
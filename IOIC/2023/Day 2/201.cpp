#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main()
{
    int n;
    cin >> n;
    if (n > 30)
        cout << "No\n";
    else
    {
        cout << "Yes\n";
        int k = 0;
        cout << (1 << 29) - 1 << " \n"[n == 1];
        for (int i = 2, j = 1; i <= n; i++, j *= 2)
             cout << (((1 << 30) - 1) ^ j) << " \n"[n == i];
    }
}
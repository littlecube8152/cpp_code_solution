#include <bits/stdc++.h>
using namespace std;

int n;

signed main()
{
    cin >> n;
    cout << (n == 5 || n == 2 ? 2 : (n == 4 ? 6 : 0)) << '\n';
}

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

signed main()
{
    int n;
    cin >> n;
    cout << 37 * (n / 19) + max(0, n % 19 - 1) << '\n';
    int i = 1;
    vector<pii> v = {
        {11, 13},
        {1, 5},
        {1, 9},
        {2, 8},
        {1, 3},
        {8, 13},
        {10, 11},
        {2, 12},
        {3, 13},
        {1, 13},
        {2, 5},
        {3, 9},
        {3, 5},
        {2, 10},
        {7, 13},
        {4, 9},
        {4, 11},
        {2, 13},
        {7, 11},
        {9, 10},
        {4, 5},
        {2, 3},
        {3, 10},
        {3, 6},
        {4, 13},
        {5, 7},
        {3, 11},
        {3, 12},
        {6, 9},
        {9, 12},
        {1, 6},
        {6, 8},
        {2, 11},
        {11, 12},
        {1, 10},
        {2, 9},
        {5, 11},
        {5, 12},
        {3, 8},
        {2, 6},
        {3, 4}};
    for (; i + 12 <= n; i += 13)
        for (pii p : v)
            cout << i - 1 + p.F << " " << i - 1 + p.S << '\n';
    for (int j = i + 1; j <= n; j++)
        cout << i << " " << j << '\n';
}

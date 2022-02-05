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
    cout << 11 * (n / 6) + max(0, n % 6 - 1) << '\n';
    int i = 1;
    for (; i + 5 <= n; i += 6)
        printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",
               i + 0, i + 1,
               i + 0, i + 2,
               i + 0, i + 3,
               i + 0, i + 5,
               i + 1, i + 4,
               i + 1, i + 5,
               i + 2, i + 4,
               i + 2, i + 5,
               i + 3, i + 4,
               i + 3, i + 5,
               i + 4, i + 5);
    for (int j = i + 1; j <= n; j++)
        cout << i << " " << j << '\n';
}
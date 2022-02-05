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
    cout << 6 * (n / 5) + max(0, n % 5 - 1) << '\n';
    int i = 1;
    for (; i + 4 <= n; i += 5)
        printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", i, i + 1, i + 1, i + 2, i + 2, i + 3, i + 3, i, i, i + 4, i + 4, i + 2);
    for (int j = i + 1; j <= n; j++)
        cout << i << " " << j << '\n';
}
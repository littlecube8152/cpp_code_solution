#include <bits/stdc++.h>
#define ll long long
#define pdd pair<double, double>
#define F first
#define S second
using namespace std;

signed main()
{
    int n, seed;
    cin >> n >> seed;
    mt19937 rd(seed);
    cout << n << '\n';
    for (int i = 1; i <= n; i++)
        cout << rd() % 10000 << ' ' << rd() % 10000 << " " << rd() % 5000 << '\n';
    // cout << "circle" << i << " = plt.Circle((" <<  rd() % 10000 << ',' << rd() % 10000 << ")," << rd() % 5000 << ")\n";
    for (int i = 1; i <= n; i++)
        cout << "ax.add_patch(circle" << i << ")\n";
}
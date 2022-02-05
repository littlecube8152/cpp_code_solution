#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 106;

ll f[N];

int main()
{
    ll n = 100, y, p, m;
    cin >> f[0] >> f[1] >> y >> p >> m;
    for (int i = 2; i <= n; ++i)
    {
        f[i] = (y * f[i - 1] - p * f[i - 2]) % m;
        if (y * f[i - 1] - p * f[i - 2] < 0)
        {
            cout << i << '\n';
            break;
        }
    }
    //cout << f[n] << endl;
}
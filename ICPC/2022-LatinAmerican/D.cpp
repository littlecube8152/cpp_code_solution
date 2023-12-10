#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;

int n, h, w;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> h >> w;
    for (int i = 1; i <= 2 * n; i++)
    {
        char c;
        cin >> c;
        if (c == 'Y')
            h--, w++, cout << 'Y' << "\n "[i % 2];
        else if(c == 'N' && !w)
            h--, w++, cout << 'Y' << "\n "[i % 2];
        else 
            cout << 'N' << "\n "[i % 2];
        swap(h, w);
    }
}
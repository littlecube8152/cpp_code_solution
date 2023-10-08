#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n = 100000, q = 300000;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++)
        cout << rd() % 1000000000 << " \n"[i == n];
    for (int i = 1; i <= q; i++)
    {
        int u = 0, v = 0;
        while (v - u <= 1)
        {
            u = rd() % n + 1, v = rd() % n + 1;
            if (u > v)
                swap(u, v);
        }
        cout << u << ' ' << v << '\n';
    }
}
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

vector<int> l(100), r(100);
void solve(int a, int b, int c, int &n, int &x, int &y, int &z)
{
    if (a + b + c == 2)
    {
        x = 3, y = 4, z = 5;
        n = 5;
        if (a && b)
            l[5] = 3, r[5] = 4;
        else if (b && c)
            l[5] = 4, r[5] = 5;
        else if (a && c)
            l[5] = 3, r[5] = 5;
        else if (a)
            l[5] = 3, r[5] = 3;
        else if (b)
            l[5] = 4, r[5] = 4;
        else if (c)
            l[5] = 5, r[5] = 5;
    }
    else
    {
        if (c % 2 == 0 && b >= a)
        {
            solve(a, (b - a) / 2, c / 2, n, x, y, z);
            l[x] = y, r[x] = ++n;
            x = n;
        }
        else if (c % 2 == 0 && a >= b)
        {
            solve((a - b) / 2, b, c / 2, n, x, y, z);
            l[y] = x, r[y] = ++n;
            y = n;
        }
        else if (b % 2 == 0 && c >= a)
        {
            solve(a, b / 2, (c - a) / 2, n, x, y, z);
            l[x] = z, r[x] = ++n;
            x = n;
        }
        else if (b % 2 == 0 && c <= a)
        {
            solve((a - c) / 2, b / 2, c, n, x, y, z);
            ++n;
            for (int i = 1; i <= n; i++)
            {
                if (l[i] == z)
                    l[i] = n;
                if (r[i] == z)
                    r[i] = n;
            }
            l[n] = x, r[n] = z;
        }
        else if (a % 2 == 0 && b >= c)
        {
            solve(a / 2, (b - c) / 2, c, n, x, y, z);
            ++n;
            for (int i = 1; i <= n; i++)
            {
                if (l[i] == z)
                    l[i] = n;
                if (r[i] == z)
                    r[i] = n;
            }
            l[n] = y, r[n] = z;
        }
        else if (a % 2 == 0 && c >= b)
        {
            solve(a / 2, b, (c - b) / 2, n, x, y, z);
            l[y] = z, r[y] = ++n;
            y = n;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t >> n;
    cerr << '\n';
    while (t--)
    {
        int a, b, c, n, x, y, z;
        cin >> a >> b;
        l.resize(100);
        r.resize(100);
        c = (1LL << (__lg(a + b - 1) + 1)) - a - b;
        solve(a, b, c, n, x, y, z);
        for (int i = 1; i <= n; i++)
        {
            if (l[i] == x)
                l[i] = 1;
            if (l[i] == y)
                l[i] = 2;
            if (r[i] == x)
                r[i] = 1;
            if (r[i] == y)
                r[i] = 2;
        }
        l.erase(l.begin() + x);
        r.erase(r.begin() + x);
        n--;
        if (y > x)
            y--;
        if (z > x)
            z--;
        for (int i = 1; i <= n; i++)
        {
            if (l[i] > x)
                l[i]--;
            if (r[i] > x)
                r[i]--;
        }
        l.erase(l.begin() + y);
        r.erase(r.begin() + y);
        n--;
        if (z > y)
            z--;
        for (int i = 1; i <= n; i++)
        {
            if (l[i] > y)
                l[i]--;
            if (r[i] > y)
                r[i]--;
        }
        cout << n << ' ' << z << '\n';
        for (int i = 3; i <= n; i++)
            cout << l[i] << ' ' << r[i] << '\n';
        cerr << '\n';
    }
}
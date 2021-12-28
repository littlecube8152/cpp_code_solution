#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int n, m, Fmax = 100, Fmin = 1;
    bool b = false;
    cin >> n >> m;
    while (m--)
    {
        int k, f;
        cin >> k >> f;
        if (k < f)
            b = true;
        int i = Fmin;
        for (; i <= Fmax; i++)
        {
            if ((k + i - 1) / i == f)
            {
                Fmin = i;
                break;
            }
        }
        for (; i <= Fmax; i++)
        {
            if ((k + i - 1) / i != f)
            {
                Fmax = i - 1;
                break;
            }
        }
    }
    if (Fmax == 0 || Fmin == 0 || b || Fmax < Fmin)
    {
        cout << -1;
        return 0;
    }
    Fmax = (n + Fmax - 1) / Fmax;
    Fmin = (n + Fmin - 1) / Fmin;
    if (Fmax != Fmin)
        cout << -1;
    else
        cout << Fmax;
}
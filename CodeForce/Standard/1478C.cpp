#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, minx;
        cin >> n;
        minx = n * (n + 1);
        n *= 2;
        set<ll> s;
        map<ll, int> m;
        bool b = true;
        while (n--)
        {
            ll x;
            cin >> x;

            m[x]++;
            s.insert(x);
            if (x % 2)
                b = false;
            if (m[x] > 2)
                b = false;
            if (x < minx)
                b = false;
        }

        ll total = 0, index = 0, olddiff = 0, firsti = 0;
        for (auto i : s)
        {
            if (index == 0)
            {
                firsti = i;
                index++;
                continue;
            }
            i = (i - firsti + total) / index / 2;
            //cout << i << " ";
            if (i <= olddiff)
            {
                b = false;
                break;
            }
            olddiff = i;
            total += 2 * i;
            index++;
        }

        if (((firsti - (total)) / 2) % s.size() != 0 || ((firsti - (total)) / 2) == 0)
            b = false;
        if (b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
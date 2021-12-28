#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, p;
        cin >> n >> k >> p;
        vector<int> c(n, k);
        int time = n;
        p--;
        while (time--)
        {
            vector<int> nc(n, 0);
            for (int i = 0; i < n; i++)
            {
                if (i != p)
                {
                    nc[(i - 1 + n) % n] += floor(c[i] / 2.0);
                    nc[(i + 1) % n] += ceil(c[i] / 2.0);
                }
                else
                    nc[(i + 1) % n] += c[i];
            }

            for (auto i : nc)
                cout
                    << i << " ";
            cout << '\n';
            c = nc;
        }
    }
}

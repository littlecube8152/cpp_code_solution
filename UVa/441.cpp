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
    int n, t = 0;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        if (t)
            cout << '\n';
        t++;

        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.emplace_back(x);
        }

        sort(v.begin(), v.end());

        for (int a = 0; a <= n - 6; a++)
            for (int b = a + 1; b <= n - 5; b++)
                for (int c = b + 1; c <= n - 4; c++)
                    for (int d = c + 1; d <= n - 3; d++)
                        for (int e = d + 1; e <= n - 2; e++)
                            for (int f = e + 1; f <= n - 1; f++)
                                cout << v[a] << " " << v[b] << " " << v[c] << " " << v[d] << " " << v[e] << " " << v[f] << "\n";
    }
}
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
    fast;
    int t;
    string s;
    cin >> t;

    getline(cin, s);
    while (t--)
    {

        getline(cin, s);
        int p = 0, r = 0;
        for (auto i : s)
            switch (i)
            {
            case 'p':
                p++;
                break;
            case 'q':
                if (p)
                {
                    p--;
                    r++;
                }
            }
        cout << r << '\n';
    }
}
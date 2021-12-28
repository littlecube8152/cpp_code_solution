#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t;

signed main()
{
    fast;
    cin >> t;
    while (t--)
    {
        int n;
        string a, b;
        cin >> a >> n;
        while (n--)
        {
            int f[100005] = {0};
            f[0] = -1;
            int r = 0;
            cin >> b;
            if (a.size() < b.size())
            {
                cout << 0 << '\n';
                continue;
            }

            //Failure Function
            for (int i = 1, j = 0; i < b.size() - 1; f[++i] = ++j)
            {
                while (b[j] != b[i] && j != -1)
                    j = f[j];
            }
            //for (int i : f)
            //    cout << i << " ";
            //cout << '\n';
            //Matching
            for (int i = 0, j = 0; i - j <= a.size() - b.size() + 2; j++, i++)
            {
                //cout << "KMP " << i << j << '\n';
                while (j != -1 && a[i] != b[j]) //Keep try until not error
                    j = f[j];
                if (j == b.size() - 1)
                {
                    r++;
                    i = i - j;
                    j = -1;
                }
            }
            cout << r << '\n';
        }
    }
}
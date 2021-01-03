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
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 4*n; i >= 2; i -= 2)
        {
            bool b = true;
            for (auto j : v)
            {
                if (j % i == 0)
                {
                    b = false;
                    break;
                }
            }
            if (b)
                v.emplace_back(i);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i]<< " ";

        }
        cout << '\n';
    }
}

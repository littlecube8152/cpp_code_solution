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
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            if (i % 2)
                cout << -(abs(tmp)) << " ";
            else
                cout << (abs(tmp)) << " ";
        }
        cout << '\n';
    }
}
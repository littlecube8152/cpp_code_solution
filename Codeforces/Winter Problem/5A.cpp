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
    int n, m, r = 10000, r_index = 0;
    string s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i <= m - n; i++)
    {
        int diff = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[j] != t[i + j])
                diff++;
        }
        if (diff < r)
        {
            r = diff;
            r_index = i;
        }
    }
    cout << r << '\n';
    for (int j = 0; j < n; j++)
    {
        if (s[j] != t[r_index + j])
            cout << j + 1 << " ";
    }
}
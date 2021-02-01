#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
bool b[2000][2000] = {{0}};
int main()
{
    int n, m;
    cin >> n >> m;

    int t[2000] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            b[i][j] = c - '0';
            t[j] += b[i][j];
        }
    for (int i = 0; i < n; i++)
    {
        bool exist = true;
        for (int j = 0; j < m; j++)
        {
            if (b[i][j] && t[j] == 1)
                exist = false;
        }
        if (exist)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO";
}
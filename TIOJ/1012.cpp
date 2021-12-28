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
    int n, m;
    stack<int> station, repair, rail, data;

    cin >> n >> m;
    rail.push(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        data.push(x);
    }
    for (int i = 1; i <= n; i++)
    {
        int x = data.top();
        data.pop();
        if (x == rail.top() - 1)
        {
            rail.push(x);
            while (!station.empty() && station.top() == rail.top() - 1)
            {
                rail.push(station.top());
                station.pop();
            }
        }
        else
        {
            for (int i = 0; i <= m; i++)
            {
                if (station.empty() || station.top() < x)
                {
                    station.push(x);
                    break;
                }
                else
                {
                    repair.push(station.top());
                    station.pop();
                }
            }
            if (station.empty() || station.top() != x)
            {
                cout << "no\n";
                return 0;
            }
            while (!repair.empty())
            {
                station.push(repair.top());
                repair.pop();
            }
        }
    }
    cout << "yes\n";
}
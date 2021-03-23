#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int n, m, pdp[100005] = {0}, count;

int gcd(int a, int b)
{
    if (a * b == 0)
        return a + b;
    return gcd(b % a, a);
}

int main()
{
    for (int i = 4; i < 100005; i += 2)
        pdp[i] = 2;
    for (int i = 3; i < 100005; i += 2)
        if (pdp[i] == 0)
            for (int j = i * i; j < 100005; j++)
                pdp[j] = i;
    cin >> n >> m;
    if (m < n - 1)
    {
        cout << "Impossible";
        return 0;
    }
    set<pii> edge;
    for (int i = 1; i < n; i++)
        edge.insert(make_pair(i, i + 1));
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i - 1; j++)
        {
            if (edge.size() == m)
                break;
            if (gcd(i, j) == 1)
                edge.insert(make_pair(i, j));
        }
    }

    if (edge.size() == m)
    {
        cout << "Possible\n";
        for (auto i : edge)
            cout << i.first << " " << i.second << '\n';
    }
    else
        cout << "Impossible";
}
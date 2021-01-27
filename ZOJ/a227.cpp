#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

void solve(int count, int from, int mid, int to)
{
    if (count == 1)
    {
        cout << "Move ring 1 from " << (char)('A' + from) << " to " << (char)('A' + to) << '\n';
        return;
    }
    else
    {
        solve(count - 1, from, to, mid);
        cout << "Move ring " << count << " from " << (char)('A' + from) << " to " << (char)('A' + to) << '\n';
        solve(count - 1, mid, from, to);
        return;
    }
}

int main()
{
    int a;
    while (cin >> a)
    {
        solve(a, 0, 1, 2);
        cout << '\n';
    }
}
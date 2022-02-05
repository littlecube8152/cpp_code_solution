#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int T, N, a, a1, a2;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    for (int i = 1; i <= T && i <= 100; i++)
    {
        cin >> N;
        a1 = a2 = 0;
        for (int i = 1; i <= N && i <= 10000; i++)
        {
            cin >> a;
            a1 ^= (a & 1);
            a2 ^= (a >> 1);
        }
        cout << ((a1 == 0 ? 0 : 1) ^ (a2 == 0 ? 0 : 2)) << '\n';
    }
}

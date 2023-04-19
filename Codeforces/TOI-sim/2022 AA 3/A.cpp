#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, r[200005], x[200005], vis[200005];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> r[i] >> x[i];
        auto check = [&](int j)
        {
            bool valid = 1;
            for (int k = 1; k < i; k++)
                if (abs(j - x[k]) % __gcd(r[i], r[k]) != 0)
                    valid = 0;
            return valid;
        };
        if (check(x[i]))
            continue;
        else
            for (int j = 0; j < r[i]; j++)
                if (check(j))
                {
                    x[i] = j;
                    break;
                }
    }
    for (int i = 1; i <= N; i++)
        cout << r[i] << " " << x[i] << '\n';
}
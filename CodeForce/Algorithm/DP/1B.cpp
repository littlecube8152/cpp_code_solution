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
    int n;
    int r[100005] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = i - 1; j > 0; j--)
            if (r[j])
                if (!(m % (j + 1)))
                {
                    r[j + 1] += r[j];
                    r[j + 1] %= MOD;
                }
        r[1]++;
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += r[i];
        sum %= MOD;
    }
    cout << sum;
    return 0;
}
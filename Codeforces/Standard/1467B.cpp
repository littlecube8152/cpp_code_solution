#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
ll n, a[300005], b[300005] = {0};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll r = 0, dr = 1;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        b[0] = 0;
        b[n - 1] = 0;
        for (int i = 1; i < n - 1; i++)
            if (a[i - 1] > a[i] && a[i] < a[i + 1])
                b[i] = -1;
            else if (a[i - 1] < a[i] && a[i] > a[i + 1])
                b[i] = 1;
            else
                b[i] = 0;

        for (int i = 1; i < n - 1; i++)
            if (b[i] != 0)
                r++;

        for (int i = 1; i < n - 1; i++)
            if (b[i - 1] == b[i + 1] && b[i + 1] != 0)
                dr = max(3LL, dr);
            else if (b[i - 1] == -b[i + 1] && b[i + 1] != 0)
                dr = max(1LL, dr);
            else if (b[i - 1] == -b[i] && b[i] != 0)
                dr = max(2LL, dr);
            else if (b[i + 1] == -b[i] && b[i] != 0)
                dr = max(2LL, dr);
            else if (b[i] != 0)
                dr = max(1LL, dr);
        cout << max(0LL, r - dr) << '\n';
    }
}
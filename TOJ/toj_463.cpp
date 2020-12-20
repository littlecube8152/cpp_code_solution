#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

struct cucumber
{
    ll first;
    ll second;
};

cucumber cuc[100005];
vector<vector<ll>> _dp(405, vector<ll>(405, 0L));
ll result, n, k;

ll max3(ll a, ll b, ll c)
{
    return max(a, max(b, c));
}

bool first_first(cucumber a, cucumber b)
{
    return a.first > b.first;
}
bool second_first(cucumber a, cucumber b)
{
    return a.second > b.second;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> cuc[i].first >> cuc[i].second;
    }

    sort(cuc, cuc + n, first_first);
    sort(cuc + min(n, 2 * k), cuc + n, second_first);

    for (ll i = 0; i < min(4 * k, n); i++)
    {
        for (int j = min(i + 1, 2 * k); j >= 0; j--)
        {
            for (int l = min(i + 1, 2 * k) - j; l >= 0; l--)
            {
                long a = _dp[j][l], b = 0, c = 0;
                if (l != 0)
                {
                    b = _dp[j][l - 1] + cuc[i].second;
                }
                if (j != 0)
                {
                    c = _dp[j - 1][l] + cuc[i].first;
                }

                _dp[j][l] = max3(a, b, c);
            }
        }
        /*
        for (int j = 0; j <= min(i + 1, 2 * k); j++)
        {
            for (int l = 0; l <= min(i + 1, 2 * k) - j; l++)
            {
                cout << _dp[j][l] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
        */
    }
    cout << _dp[k][k] << '\n';
}
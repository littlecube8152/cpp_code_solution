#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, ans;
pii arr[100005];
signed main()
{
    fast;
    ifstream cin("pairup.in");
    ofstream cout("pairup.out");

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i].S >> arr[i].F;
    sort(arr + 1, arr + 1 + N);
    int ldx = 1, rdx = N;
    while (ldx <= rdx)
    {
        ans = max(ans, arr[ldx].F + arr[rdx].F);
        if (arr[ldx].S == arr[rdx].S)
            ldx++, rdx--;
        else if (arr[ldx].S < arr[rdx].S)
        {
            arr[rdx].S -= arr[ldx].S;
            ldx++;
        }
        else
        {
            arr[ldx].S -= arr[rdx].S;
            rdx--;
        }
    }
    cout << ans << '\n';
}
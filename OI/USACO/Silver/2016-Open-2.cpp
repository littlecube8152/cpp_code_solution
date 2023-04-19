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

int N, K, arr[50004], res[50004], suf[50004], ans;
signed main()
{
    fast;
    ifstream cin("diamond.in");
    ofstream cout("diamond.out");

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr + 1, arr + 1 + N);
    int rdx = 1;
    for (int i = 1; i <= N; i++)
    {
        while (rdx <= N && arr[rdx] - arr[i] <= K)
            rdx++;
        res[i] = rdx;
    }
    for (int i = N; i >= 1; i--)
    {
        suf[i] = max(suf[i + 1], res[i] - i);
        ans = max(ans, res[i] - i + suf[res[i]]);
    }
    cout << ans << '\n';
}
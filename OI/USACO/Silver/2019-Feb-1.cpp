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

int N, K, arr[100005], M, m;
signed main()
{
    fast;
    ifstream cin("herding.in");
    ofstream cout("herding.out");

    cin >> N;
    m = N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr + 1, arr + 1 + N);
    int rdx = 1;
    for (int i = 1; i <= N; i++)
    {
        while (rdx <= N && arr[rdx] - arr[i] < N)
            rdx++;
        if(arr[i] + N - 1 == arr[rdx - 1] || (rdx <= N && i - 1 + N - rdx + 1 >= 2))
        m = min(m, N - (rdx - i));
    }
    M = max(M, arr[N] - arr[2] + 2 - N);
    M = max(M, arr[N - 1] - arr[1] + 2 - N);
    sort(arr + 1, arr + 1 + N, greater<>());
    for (int i = 1; i <= N; i++)
        arr[i] = 1e9 - arr[i];
    for (int i = 1; i <= N; i++)
    {
        while (rdx <= N && arr[rdx] - arr[i] < N)
            rdx++;
        if(arr[i] + N - 1 == arr[rdx - 1] || (rdx <= N && i - 1 + N - rdx + 1 >= 2))
        m = min(m, N - (rdx - i));
    }
    cout << m << '\n'
         << M << '\n';
}
//
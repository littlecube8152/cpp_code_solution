#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, arr[1000005], ans;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr + 1, arr + 1 + N);
    int ldx = 1, rdx = 0;
    ll cur = 0;
    while (ldx <= N && rdx <= N)
    {
        if (rdx <= N && (rdx - ldx + 1 <= 1 || arr[rdx + 1] < arr[ldx] + arr[ldx + 1]))
        {
            rdx++;
            cur += arr[rdx];
        }
        else
        {
            cur -= arr[ldx];
            ldx++;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
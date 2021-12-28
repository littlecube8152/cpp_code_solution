#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
int N, arrr[500005];


signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N;i++)
    {
        int a, b;
        cin >> a >> b;
        arrr[a] = max(arrr[a], b);
    }
    long long res = 0;
    for (int i = 1; i <= N;i++)
    {
        res += arrr[i];
    }
    cout << res << '\n';
}
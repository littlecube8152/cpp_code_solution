#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

int N, arr[1000005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    long long t = 0, cnt = 0;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++)
    {
        if (arr[i] > t)
        {
            cnt++;
            t += arr[i];
        }
    }
    cout << cnt << "\n";
}
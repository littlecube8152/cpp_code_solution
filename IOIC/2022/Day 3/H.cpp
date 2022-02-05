#include <algorithm>
#include <iostream>
using namespace std;

int N, arr[1000005], last[1000005], ans;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    sort(arr + 1, arr + 1 + N);
    for (int i = 1; i <= N; i++)
    {
        ans = max(last[arr[i]] + 1, ans);
        last[arr[i]]++;
        if(arr[i] != arr[i + 1])
            for (int j = arr[i] * 2; j <= 1e6; j += arr[i])
                last[j] = max(last[arr[i]], last[j]);
    }
    cout << ans << '\n';
}

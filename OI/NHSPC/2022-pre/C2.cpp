#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, a[1000006], dupe[4], sw;

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i < N; i++)
        if (a[i] != a[i + 1])
            sw++;
        else
            dupe[a[i]]++;
    int cur = a[1];
    cout << cur << ' ';
    if (sw <= 2)
        while (dupe[cur])
        {
            cout << cur << ' ';
            dupe[cur]--;
        }
    for (; sw > 0; sw--)
    {
        cur = cur ^ 3;
        if (dupe[cur])
        {
            cout << cur << ' ';
            dupe[cur]--;
        }
        if (sw <= 2)
            while (dupe[cur])
            {
                cout << cur << ' ';
                dupe[cur]--;
            }
        cout << cur << ' ';
    }
    cout << '\n';
}
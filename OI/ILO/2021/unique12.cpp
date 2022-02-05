#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, arr[150005], L, R, idx, ans;
map<int, int> mp;

signed main()
{
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        if(mp[arr[i]] == 0)
            mp[arr[i]] = ++idx;
        arr[i] = mp[arr[i]];
    }
    for (int i = 1; i <= N; i++)
    {
        int cnt[150005] = {}, uni = 0;
        for (int j = i; j <= N; j++)
        {
            cnt[arr[j]]++;
            if(cnt[arr[j]] == 1)
                uni++;
            else if(cnt[arr[j]] == 2)
                uni--;
            if(L <= uni && uni <= R)
                ans++;
        }
    }
    cout << ans << '\n';
}
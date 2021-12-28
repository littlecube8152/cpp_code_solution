#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, arr[150005], L, R, idx, ans;
map<int, int> mp;
vector<int> cnt[2005];
signed main()
{
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        if (mp[arr[i]] == 0)
            mp[arr[i]] = ++idx;
        arr[i] = mp[arr[i]];
    }
    set<pii> v;
    v.insert(pii{N + 1, 0});
    for (int i = N; i >= 1; i--)
    {
        if (cnt[arr[i]].size() >= 1)
            v.erase(v.find(make_pair(cnt[arr[i]][cnt[arr[i]].size() - 1], 1)));
        if (cnt[arr[i]].size() >= 2)
            v.erase(v.find(make_pair(cnt[arr[i]][cnt[arr[i]].size() - 2], -1)));
        cnt[arr[i]].emplace_back(i);
        if (cnt[arr[i]].size() >= 1)
            v.insert(make_pair(cnt[arr[i]][cnt[arr[i]].size() - 1], 1));
        if (cnt[arr[i]].size() >= 2)
            v.insert(make_pair(cnt[arr[i]][cnt[arr[i]].size() - 2], -1));
        int uni = 0, cur = i;

        for (pii p : v)
        {
            if (L <= uni && uni <= R)
                ans += p.F - cur;
            uni += p.S;
            cur = p.F;
        }
    }
    cout << ans << '\n';
}
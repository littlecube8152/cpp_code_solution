#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200015
using namespace std;
int n, k, arr[N], pos[N], ans[N];
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        set<int> rem;
        vector<pii> sw;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            ans[i] = arr[i];
            pos[arr[i]] = i;
            rem.insert(i);
        }
        int cnt = n - k + 1;
        for (int i = 1; cnt > 0 && i <= n; i++, cnt--)
        {
            auto it = rem.lower_bound(pos[i] - k + 1);
            if(*it == pos[i])
                cnt++;  
            int pi = pos[i], pj = *it, j = arr[pj];
            sw.emplace_back(pii(pj, pi));
            swap(arr[pi], arr[pj]);
            swap(pos[i], pos[j]);
            cout << "swap " << pi << ' ' << pj << '\n';
            rem.erase(*it);
        }
        sort(sw.begin(), sw.end());
        for(auto [i, j] : sw)
            swap(ans[i], ans[j]);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " \n"[i == n];
    }
}
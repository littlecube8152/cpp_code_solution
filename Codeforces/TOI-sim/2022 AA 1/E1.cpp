#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, arr[100005];
ll ans;
vector<int> last[50005];

void solve(int L, int R)
{
    multiset<int, greater<int>> lst;
    multiset<int> rst;
    lst.insert(L);
    rst.insert(R);
    vector<pii> lim;
    int leftL = L, leftR = R;
    for (int i = L; i <= R; i++)
        last[arr[i]].emplace_back(i);
    for (int i = 1; i <= N; i++)
        if (last[i].size() == 3)
        {
            leftL = max(leftL, last[i][0] + 1);
            leftR = max(leftR, last[i][1]);
            lim.emplace_back(pii{last[i][1] + 1, last[i][2]});
        }
        else if (last[i].size() == 2)
            lim.emplace_back(pii{last[i][0] + 1, last[i][1]});
    sort(lim.begin(), lim.end());
    for (auto [a, b] : lim)
    {
        lst.insert(a);
        rst.insert(b);
    }
    int idx = 0, out = 1e9;
    // cout << L << " " << leftL << " " << leftR << '\n';
    for (int i = L + 1; i <= (L + R) / 2; i++)
    {
        while (idx < lim.size() && lim[idx].F <= i)
        {
            lst.erase(lst.find(lim[idx].F));
            rst.erase(rst.find(lim[idx].S));
            out = min(out, lim[idx].S);
            idx++;
        }
        if (i > out)
            break;
        if (leftL <= i && i <= leftR)
        {   
            // cout << L << " " << i << " [" << max({*lst.begin(), i + 1, (L + R + 1) / 2 + 1}) << ", " << min(*rst.begin(), i + (N - 1) / 2) << "]\n";
            ans += max(0LL, min(*rst.begin(), i + (N - 1) / 2) - max({*lst.begin(), i + 1, (L + R + 1) / 2 + 1}) + 1);
        }
    }
    for (int i = 1; i <= N; i++)
        last[i].clear();
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i + N] = arr[i];
    }
    for (int i = 1; i <= N; i++)
        solve(i, i + N - 1);
    cout << ans / 3 << '\n';
}
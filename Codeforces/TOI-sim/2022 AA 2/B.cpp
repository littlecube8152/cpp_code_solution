#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, K;
pii p[9];
vector<int> ans, perm;

int det(int a, int b, int c, int d)
{
    return a * d - b * c;
}

int ori(pii base, pii p1, pii p2)
{
    int res = det(p1.F - base.F, p1.S - base.S, p2.F - base.F, p2.S - base.S);
    if (res > 0)
        return 1;
    else
        return (res == 0 ? 0 : -1);
}

int dot(pii base, pii p1, pii p2)
{
    int res = (p1.F - base.F) * (p2.F - base.F) + (p1.S - base.S) * (p2.S - base.S);
    if (res > 0)
        return 1;
    else
        return (res == 0 ? 0 : -1);
}

int banana(pii p1, pii p2, pii p3, pii p4)
{
    int ans = 0;

    if (ori(p1, p3, p4) == 0 && dot(p1, p3, p4) == -1)
        ans++;
    if (ori(p2, p3, p4) == 0 && dot(p2, p3, p4) == -1)
        ans++;
    if (ori(p3, p1, p2) == 0 && dot(p3, p1, p2) == -1)
        ans++;
    if (ori(p4, p1, p2) == 0 && dot(p4, p1, p2) == -1)
        ans++;
    if ((p1.F - p2.F) * (p3.S - p4.S) != (p1.S - p2.S) * (p3.F - p4.F))
        ans += (ori(p1, p2, p3) * ori(p1, p2, p4) == -1 && ori(p3, p4, p1) * ori(p3, p4, p2) == -1);
    return ans;
}

int solve(vector<int> v)
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (j - i == 1 || j - i == N - 1)
            {
                if (banana(p[v[i]], p[v[(i + 1) % N]], p[v[j]], p[v[(j + 1) % N]]) >= 3)
                    return 1e9;
            }
            else if (banana(p[v[i]], p[v[(i + 1) % N]], p[v[j]], p[v[(j + 1) % N]]) >= 1)
                return 1e9;
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans += det(p[v[i]].F, p[v[i]].S, p[v[(i + 1) % N]].F, p[v[(i + 1) % N]].S);
    ans = abs(ans);
    return ans;
}

signed main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> p[i].F >> p[i].S;
        perm.emplace_back(i);
    }
    do
    {
        ans.emplace_back(solve(perm));
    } while (next_permutation(perm.begin() + 1, perm.end()));
    sort(ans.begin(), ans.end());
    cin >> K;
    cout << ans[2 * K - 1] / 2 << (ans[2 * K - 1] % 2 == 1 ? ".5" : ".0") << '\n';
}

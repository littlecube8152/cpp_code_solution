#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M;
ll ans;

set<int> st[200005];

int merge(set<int> &A, set<int> &B)
{
    int res = 0;
    bool sw = 0;
    if (A.size() < B.size())
    {
        res = B.size();
        A.swap(B);
        sw = 1;
    }

    for (auto i : B)
        if (!A.count(i))
        {
            A.insert(i);
            res += (sw ? 0 : 1);
        }
        else
            res += (sw ? -1 : 0);
    return res;
}

signed main()
{
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        st[u].insert(v);
    }
    for (int i = 1; i <= N; i++)
        if (!st[i].empty())
        {
            int j = *st[i].begin();
            st[i].erase(j);

            ans += merge(st[j], st[i]);
        }
    cout << ans << '\n';
}

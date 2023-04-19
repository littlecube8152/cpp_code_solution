#include <bits/extc++.h>
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;

int N, Q, ans[100005], C;
vector<int> pos;
vector<tuple<int, int, int, int>> queries;
tree<pii, null_type, greater<pii>, rb_tree_tag, tree_order_statistics_node_update> st[800005];

void modify(int p, pii v, int i = 1, int L = 0, int R = C)
{
    st[i].insert(v);
    if (L + 1 < R)
    {
        int mid = (L + R) / 2;
        if (p < pos[mid])
            modify(p, v, i << 1, L, mid);
        else
            modify(p, v, i << 1 | 1, mid, R);
    }
}

int query(int p, int c, int i = 1, int L = 0, int R = C)
{
    if (p <= pos[L])
        return st[i].order_of_key(pii(c, 0));
    else
    {
        int mid = (L + R) / 2;
        if (p < pos[mid])
            return query(p, c, i << 1, L, mid) + query(p, c, i << 1 | 1, mid, R);
        else
            return query(p, c, i << 1 | 1, mid, R);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        int S, T;
        cin >> S >> T;
        pos.emplace_back(T);
        queries.emplace_back(make_tuple(S, Q + i, T, 0));
    }
    for (int i = 1; i <= Q; i++)
    {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        pos.emplace_back(Y);
        queries.emplace_back(make_tuple(X, i, Y, Z));
    }
    pos.emplace_back(1'000'000'000);
    sort(pos.begin(), pos.end());
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
    C = pos.size();
    sort(queries.begin(), queries.end(), greater<>());
    for (auto [a, i, b, c] : queries)
    {
        // cerr << i << ' ' << a << ' ' << b << ' ' << c << '\n';
        if (i > Q)
            modify(b, pii(a + b, i));
        else
            ans[i] = query(b, c);
    }
    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';
}
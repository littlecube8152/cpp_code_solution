#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, m, block, dsu[200005], x, y;

vector<int> e[200005], v;
stack<bool> st;
bool b[200005];

signed main()
{
    function<int(int)> find;
    find = [&](int k) { return (k == dsu[k] ? k : dsu[k] = find(dsu[k])); };
    fast;
    ifstream cin("closing.in");
    ofstream cout("closing.out");
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    for (int i = 1; i <= n; i++)
        dsu[i] = i;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    reverse(v.begin(), v.end());
    for (int i : v)
    {
        block++;
        b[i] = 1;
        for (int j : e[i])
            if (b[j])
                if (find(i) != find(j))
                    dsu[find(j)] = find(i), block--;
        if (block == 1)
            st.push(1);
        else
            st.push(0);
    }
    while (!st.empty())
    {
        if (st.top())
            cout << "YES\n";
        else
            cout << "NO\n";
        st.pop();
    }
}
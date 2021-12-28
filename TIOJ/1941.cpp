#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, s[800005], t[800005], id[800005], bit[800005], ans;

void modify(int L, int R, int val)
{
    for (int i = L; i <= n + 1; i += (i & -i))
        bit[i] += val;
    for (int i = R + 1; i <= n + 1; i += (i & -i))
        bit[i] -= val;
}

int query(int n)
{
    int ans = 0;
    for (int i = n; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

set<int> st;

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> t[i];
    for (int i = 1; i <= n; i++)
        s[i]++, t[i]++;
    st.insert(1);
    st.insert(n + 1);
    modify(n + 1, n + 1, 2 * n);
    for (int i = 1; i <= n; i++)
    {
        st.insert(s[i]);
        st.insert(t[i] + 1);
        int res = query(t[i]) + 1, pos = t[i], val =query(pos + 1);
        auto iter = st.upper_bound(t[i]);

        while (val <= res)
        {
            iter = st.erase(iter);
            if (val < res)
                pos = *iter - 1;
            val = query(*iter);
        }
        modify(s[i], pos, 1);

        //for (int j = 1; j <= n + 1; j++)
        //    cout << query(j) << " ";
        //cout << '\n';
    }
    cout <<query(n) << '\n';
}
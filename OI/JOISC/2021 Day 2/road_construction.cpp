#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

vector<pll> v;
vector<ll> ans;
ll n, k;
signed main()
{
    /* SUBTASK 1
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].F >> v[i].S;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if(i != j)
                ans.emplace_back(abs(v[i].F - v[j].F) + abs(v[i].S - v[j].S));
    sort(ans.begin(), ans.end());
    for (int i = 0; i < k;i++)
        cout << ans[i] << '\n';
    */
    /* SUBTASK 3
    cin >> n >> k;
    ll a = 10000000000000000;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].F >> v[i].S;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            ll res = abs(v[i].F - v[j].F) + abs(v[i].S - v[j].S);
            if (res > a)
                break;
            a = min(a, res);
        }
    for (int i = 0; i < k; i++)
        cout << a << '\n';
    */
    cin >> n >> k;
    set<ll> st;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].F >> v[i].S;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            ll res = abs(v[i].F - v[j].F) + abs(v[i].S - v[j].S);
            if (st.size() > 0 && abs(v[i].F - v[j].F) > *(--st.end()))
                break;
            if (st.size() >= k && res < *(--st.end()))
            {
                st.insert(res);
                st.erase(--st.end());
            }
            else if (st.size() < k)
                st.insert(res);
        }
    for (int i : st)
        cout << i << '\n';
}
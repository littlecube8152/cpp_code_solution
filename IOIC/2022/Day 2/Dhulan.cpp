#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N;
pll a[100005];

ll bs(ll L, ll R)
{
    if (L == R)
        return L;
    ll mid = (L + R + 1) / 2, last = -1e9;
    bool valid = 1;
    priority_queue<ll, vector<ll>, greater<ll>> st;
    for (int i = 1; i <= N; i++)
    {
        while (!st.empty() && st.top() <= a[i].F)
        {
            if (st.top() - last < mid)
                valid = 0;
            last = st.top();
            st.pop();
        }
        if (a[i].F - last < mid)
            st.push(a[i].S);
        else
            last = a[i].F;
    }
    while (!st.empty())
    {
        if (st.top() - last < mid)
            valid = 0;
        last = st.top();
        st.pop();
    }
    if (valid)
        return bs(mid, R);
    else
        return bs(L, mid - 1);
}

int main()
{
    cin >> N;
    if (N == 1)
    {
        cout << 1000000000 << '\n';
        return 0;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i].F >> a[i].S;
        if (a[i].S <= a[i].F)
            swap(a[i].F, a[i].S);
    }
    cout << bs(0, 1e9) << '\n';
}
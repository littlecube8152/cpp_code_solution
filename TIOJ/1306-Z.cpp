#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

void solve()
{
    string s, t, Z;
    vector<int> value;
    int N, cnt, mxMatch = 0, mxPos = 0;
    cin >> s >> N;
    while (N--)
    {
        cin >> t;
        Z = t + '$' + s;
        value = vector<int>(Z.size(), 0);

        cnt = mxMatch = mxPos = 0;

        for (int i = 1; i < Z.size(); i++)
        {
            if (mxMatch < i)
                while (i + value[i] < Z.size() && Z[i + value[i]] == Z[value[i]])
                    value[i]++;
            else if (mxMatch == i + value[i - mxPos] - 1)
            {
                value[i] = value[i - mxPos];
                while (i + value[i] < Z.size() && Z[i + value[i]] == Z[value[i]])
                    value[i]++;
            }
            else if (mxMatch > i + value[i - mxPos] - 1)
                value[i] = value[i - mxPos];
            else
                value[i] = mxMatch - i + 1;

            if (i + value[i] >= mxMatch)
                mxMatch = i + value[i] - 1, mxPos = i;
        }

        //for (int i = 0; i < Z.size(); i++)
        //    cout << Z[i] << " " << value[i] << '\n';

        for (int i = t.size(); i < Z.size(); i++)
            if (value[i] == t.size())
                cnt++;
        cout << cnt << '\n';
    }
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}
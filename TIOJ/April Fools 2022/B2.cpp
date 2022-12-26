#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    while (cin >> s)
    {
        s = " " + s;
        go(s, 0, 1);
    }
    dfs(1, 0);
}

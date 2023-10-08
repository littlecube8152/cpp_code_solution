#include <bits/stdc++.h>
using namespace std;
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define ll long long
#define F first
#define S second

string s = "0123456789";

map<string, int> vis;

void dfs(string &s)
{
    cerr << s << '\n';
    vis[s] = 1;
    int i = min_element(s.begin(), s.end()) - s.begin();
    if (i < 5)
        for (int j = 5; j < 10; j++)
        {
            swap(s[i], s[j]);
            if(!vis[s])
                dfs(s);
            swap(s[i], s[j]);
        }
    else
        for (int j = 0; j < 5; j++)
        {
            swap(s[i], s[j]);
            if(!vis[s])
                dfs(s);
            swap(s[i], s[j]);
        }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    dfs(s);
    cout << vis["5678901234"];
}
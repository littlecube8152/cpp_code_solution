/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
    
string s;
int order[2][400005], n;
vector<int> radix[400005];
vector<int> v;

void ordering(int k)
{
    order[k % 2][v[0]] = 0;
    for (int i = 1, j = 0; i < v.size(); i++)
    {
        if (order[(k + 1) % 2][v[i]] != order[(k + 1) % 2][v[i - 1]] || order[(k + 1) % 2][(v[i] + (1 << k)) % s.length()] != order[(k + 1) % 2][(v[i - 1] + (1 << k)) % s.length()])
            j++;
        order[k % 2][v[i]] = j;
    }
}

signed main()
{
    fast;
    cin >> s;
    s += '$';
    for (int i = 0; i < s.length(); i++)
    {
        v.pb(i);
        if (s[i] == '$')
            order[1][i] = 0;
        else
            order[1][i] = (int)(s[i] - 'a' + 1);
    }
    n = max(27LL, (int)s.length());
    for (int k = 0; k <= __lg(s.length()); k++)
    {
        //sort(v.begin(), v.end(), [&](int a, int b) { return tie(order[(k + 1) % 2][a], order[(k + 1) % 2][(a + (1 << k)) % s.length()]) < tie(order[(k + 1) % 2][b], order[(k + 1) % 2][(b + (1 << k)) % s.length()]); });
        for (int i : v)
            radix[order[(k + 1) % 2][(i + (1 << k)) % s.length()]].pb(i);
        for (int i = 0, j = 0; i <= n; i++)
        {
            for (int l : radix[i])
                v[j++] = l;
            radix[i].clear();
        }
        for (int i : v)
            radix[order[(k + 1) % 2][i]].pb(i);
        for (int i = 0, j = 0; i <= n; i++)
        {
            for (int l : radix[i])
                v[j++] = l;
            radix[i].clear();
        }

        ordering(k);

    }
    for (int i : v)
        cout << i << " ";
}
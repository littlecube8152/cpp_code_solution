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

int n, m, k, ans;
vector<int> a, b;
signed main()
{
    fast;

    cin >> n >> m >> k;
    
    while(n--)
    {
        int x;
        cin >> x;
        a.pb(x);
    }
    
    while(m--)
    {
        int x;
        cin >> x;
        b.pb(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while(!a.empty() && !b.empty())
    {
        if(b.back() > a.back() + k)
            b.pop_back();
        else if(b.back() < a.back() - k)
            a.pop_back();
        else 
        {
            ans++;
            //cout << a.back() << " " << b.back() << '\n';
            a.pop_back();
            b.pop_back();
        }
    }
    cout << ans;
}
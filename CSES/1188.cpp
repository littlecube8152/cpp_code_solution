/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int n, m, x, arr[200005];
string s;

struct B
{
    map<int, int> mp;
    multiset<int, greater<int>> st;
    int ans()
    {
        return (st.size() ? *st.begin() : 0);
    }
    void insert(int pos)
    {
        auto up = mp.upper_bound(pos);
        if (up == mp.begin())
        {
            if (up == mp.end() || pos + 1 != up->F)
            {
                mp[pos] = 1;
                st.insert(1);
            }
            else
            {
                mp[pos] = up->S + 1;
                st.erase(st.find(up->S));
                st.insert(up->S + 1);
                mp.erase(up);
            }
        }
        else
        {
            auto lo = prev(up);
            if (lo->F + lo->S < pos && (up == mp.end() || pos + 1 < up->F))
            {
                mp[pos] = 1;
                st.insert(1);
            }
            else if (lo->F + lo->S == pos && up != mp.end() && pos + 1 == up->F)
            {
                st.erase(st.find(up->S));
                st.erase(st.find(lo->S));
                st.insert(lo->S + 1 + up->S);
                lo->S = lo->S + 1 + up->S;
                mp.erase(up);
            }
            else if (lo->F + lo->S == pos)
            {
                st.erase(st.find(lo->S));
                st.insert(lo->S + 1);
                lo->S = lo->S + 1;
            }
            else
            {
                st.erase(st.find(up->S));
                st.insert(1 + up->S);
                mp[pos] = 1 + up->S;
                mp.erase(up);
            }
        }
    }

    void erase(int pos)
    {
        auto it = prev(mp.upper_bound(pos));
        if (it->F == pos)
        {
            st.erase(st.find(it->S));
            if (it->S > 1)
            {
                st.insert(it->S - 1);
                mp[pos + 1] = it->S - 1;
            }
            mp.erase(it);
        }
        else if (it->F + it->S - 1 == pos)
        {
            st.erase(st.find(it->S));
            st.insert(it->S - 1);
            it->S--;
        }
        else
        {
            st.erase(st.find(it->S));
            st.insert(pos - it->F);
            st.insert(it->F + it->S - 1 - pos);
            mp[pos + 1] = it->F + it->S - 1 - pos;
            it->S = pos - it->F;
        }
    }
    void debug()
    {
        for (auto [p, l] : mp)
            cout << p << "-" << l << "  ";
        cout << '\n';
        for (auto i : st)
            cout << i << " ";
        cout << '\n';
    }
} b[2];

signed main()
{
    fast;
    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; i++)
    {
        arr[i] = s[i - 1] - '0';
        b[arr[i]].insert(i);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        b[arr[x]].erase(x);
        arr[x] ^= 1;
        b[arr[x]].insert(x);
        //cout << "b0 ";
        //b[0].debug();
        //cout << "b1 ";
        //b[1].debug();
        cout << max(b[0].ans(), b[1].ans()) << " \n"[i == m];
    }
}
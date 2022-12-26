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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

string s;

vector<int> sa, cnt, rk, tmp, lcp;
void SA(string s)
{
    int n = s.size();
    sa.resize(n), cnt.resize(n), rk.resize(n), tmp.resize(n);
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&](int i, int j)
         { return s[i] < s[j]; });
    for (int i = 1; i < n; i++)
        rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i - 1]] != s[sa[i]]);
    for (int k = 1; k <= n; k <<= 1)
    {
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++)
            cnt[rk[(sa[i] - k + n) % n]]++;
        for (int i = 1; i < n; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            tmp[--cnt[rk[(sa[i] - k + n) % n]]] = (sa[i] - k + n) % n;
        sa.swap(tmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + (rk[sa[i - 1]] != rk[sa[i]] || rk[(sa[i - 1] + k) % n] != rk[(sa[i] + k) % n]);
        rk.swap(tmp);
    }
}

void LCP(string s)
{
    int n = s.size(), k = 0;
    lcp.resize(n);
    for (int i = 0; i < n; i++)
        if(rk[i] == 0)
            lcp[rk[i]] = 0;
        else
        {
            if(k)
                k--;
            int j = sa[rk[i] - 1];
            while(i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            lcp[rk[i]] = k;
        }
}

signed main()
{
    fast;
    cin >> s;
    ll n = s.size();
    SA(s + '$');
    LCP(s + '$');
    ll ans = n * (n + 1) / 2;
    for(int i : lcp)
        ans -= i;
    cout << ans << '\n';
}

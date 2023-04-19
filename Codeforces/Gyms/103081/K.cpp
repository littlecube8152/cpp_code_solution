#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

vector<int> sa, cnt, rk, tmp, lcp;

void SA(string s)
{
    int n = s.size();
    sa.resize(n);
    cnt.resize(n);
    rk.resize(n);
    tmp.resize(n);
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
        if (rk[i] == 0)
            lcp[rk[i]] = 0;
        else
        {
            if (k)
                k--;
            int j = sa[rk[i] - 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                k++;
            lcp[rk[i]] = k;
        }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    s = s;
    int n = s.size();
    s = s + '$';
    SA(s);
    LCP(s);
    pii ans = pii(n, 0);
    lcp.resize(n + 2);
    for (int i = 0; i < n + 1; i++)
    {
        if(sa[i] == n)
            continue;
        int l = max(lcp[i], lcp[i +1]);
        if(sa[i] + l + 1 <= n)
            ans = min(ans, pii(l + 1, sa[i]));
    }
    cerr << ans.F << ' ' << ans.S << '\n';
    for(int i = ans.S; i < ans.F + ans.S; i++)
        cout << s[i];
    cout << '\n';
}

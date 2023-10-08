#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define double long double
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd complex<double>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int man[2000006];
ll L[2000006], R[2000006];
void manacher(string s)
{
    string t;
    for (int i = 0; i < s.size(); i++)
    {
        t.push_back('$');
        t.push_back(s[i]);
    }
    t.push_back('$');
    int mx = 0, ans = 0;
    for (int i = 0; i < t.size(); i++)
    {
        man[i] = 1;
        if (i < man[mx] + mx)
            man[i] = min(man[mx] + mx - i, man[2 * mx - i]);
        while (man[i] + i < t.size() && i - man[i] >= 0 && t[i + man[i]] == t[i - man[i]])
            man[i]++;
        if (i + man[i] > mx + man[mx])
            mx = i;
    }
    // cout << t << '\n';
    // for (int i = 0; i < t.size(); i++)
    //     cout << man[i] << " \n"[i + 1 == t.size()];
}

signed main()
{
    fast;
    int n, m;
    string s;
    cin >> n;
    cin >> s;
    m = s.size();
    s += s;
    manacher(s);
    for (int i = 0; i < 2 * m; i++)
    {
        // odd length
        // $a$b$a$
        int hl = min((n + 1) / 2, man[i * 2 + 1] / 2);
        L[i - hl + 1]++;
        L[i + 1]--;
        R[i]++;
        R[i + hl]--;
    }
    for (int i = 0; i + 1 < 2 * m; i++)
    {
        // even length (gap btw i, i + 1)
        // $a$b$
        int hl = min(n / 2, (man[i * 2 + 2] - 1) / 2);
        L[i - hl + 1]++;
        L[i + 1]--;
        R[i + 1]++;
        R[i + hl + 1]--;
    }
    for (int i = 1; i < 2 * m; i++)
        L[i] += L[i - 1], R[i] += R[i - 1];
  
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans += R[i];
    for (int i = 0; i < m; i++)
    {
        ans += R[i + n - 1];
        cout << ans << '\n';
        ans -= L[i];
    }
}
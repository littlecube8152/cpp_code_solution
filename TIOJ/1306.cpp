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
    string s, t;
    vector<int> fail;
    cin >> s;
    int N, cnt;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> t;
        fail = {0};
        cnt = 0;
        t = " " + t;
        for (int i = 1; i < t.size(); i++)
        {
            int j = i - 1, curfail = 0;
            while (j > 0)
            {
                if (t[fail[j] + 1] == t[i])
                {
                    curfail = fail[j] + 1;
                    break;
                }
                else
                    j = fail[j];
            }
            fail.emplace_back(curfail);
        }

        //for (int i = 1; i < t.size(); i++)
        //    cout << fail[i] << " \n"[i == t.size() - 1];
        for (int i = 0, j = 0; i < s.size();)
        {
            if (s[i] == t[j + 1])
                i++, j++;
            else if (j == 0)
                i++;
            else
                j = fail[j];
            if (j == t.size() - 1)
                cnt++;
        }
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
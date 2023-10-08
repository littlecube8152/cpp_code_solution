#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0), \
             cin.tie(0), cout.tie(0)
using namespace std;

signed main()
{
    fast;
    int T, N;
    string s, t;
    cin >> T;
    while (T--)
    {
        cin >> N >> s >> t;
        bool flag = 0;
        for (int i = 0; i < N; i++)
            if (t[i] == 'C')
            {
                if (s[i] != 'C')
                    flag = 1;
                s[i] = t[i] = 'D';
            }
        for (int i = 0; i < N; i++)
        {
            if (s[i] == 'D')
                continue;
                
            int j = i;
            while (j + 1 < N && s[j + 1] != 'D')
                j++;

            vector<int> pS[3], pT[3];
            for (int k = i; k <= j; k++)
                pS[s[k] - 'A'].emplace_back(k), pT[t[k] - 'A'].emplace_back(k);

            if (pS[0].size() > pT[0].size() || pS[1].size() > pT[1].size())
                flag = 1;
            else 
            {
                reverse(pS[2].begin(), pS[2].end());
                while (pS[0].size() < pT[0].size())
                {
                    if (pS[2].empty())
                        break;
                    
                    pS[0].emplace_back(pS[2].back());
                    pS[2].pop_back();
                }
                if (pS[0].size() != pT[0].size())
                    flag = 1;
                else 
                {
                    sort(pS[0].begin(), pS[0].end());
                    for (int k = 0; k < pS[0].size(); k++)
                        if (pS[0][k] > pT[0][k])
                            flag = 1;
                }
            }

            i = j;
        }

        if (flag)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}
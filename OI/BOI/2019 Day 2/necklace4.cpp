#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

string s, t;

vector<int> Z(string s)
{
    int N = s.size(), mxZ = 0, mxi = 0;
    vector<int> z(N);
    for (int i = 1; i < N; i++)
    {
        if (i <= mxZ)
            z[i] = min(z[i - mxi], mxZ - i);
        while (i + z[i] >= mxZ && i + z[i] < N && s[i + z[i]] == s[z[i]])
        {
            z[i]++;
            mxZ = i + z[i], mxi = i;
        }
    }
    return z;
}

pair<int, pii> solve(string s, string t)
{
    int ans = 0, N = s.size(), M = t.size();
    pii sol;
    for (int i = 0; i <= N; i++)
    {
        string L, R;
        for (int j = i - 1; j >= 0; j--)
            L.push_back(s[j]);
        for (int j = M - 1; j >= 0; j--)
            L.push_back(t[j]);
        for (int j = i; j < N; j++)
            R.push_back(s[j]);
        for (int j = 0; j < M; j++)
            R.push_back(t[j]);
        vector<int> zL = Z(L), zR = Z(R);
        // cerr << t << '\n';
        // cerr << s.substr(0, i) << ' ' << s.substr(i) << '\n';
        vector<int> lL(M + 1), lR(M + 1);
        for (int j = i; j < i + M; j++)
        {
            int k = M - (j - i) - 1;
            zL[j] = min(zL[j], i);
            if(k - zL[j] + 1 < 0)
                lL[0] = max(lL[0], k + 1);
            else if(zL[j])
                lL[k - zL[j] + 1] = max(lL[k - zL[j] + 1], zL[j]);
        }
        for (int j = 1; j < M; j++)
            lL[j] = max(lL[j], lL[j - 1] - 1);

        for (int j = (N - i); j < (N - i) + M; j++)
        {
            int k = j - (N - i);
            zR[j] = min(zR[j], N - i);
            if(k + zR[j] - 1 > M)
                lR[M] = max(lR[M], M - k + 1);
            else if(zR[j])
                lR[k + zR[j] - 1] = max(lR[k + zR[j] - 1], zR[j]);
        }
        for (int j = M - 1; j >= 0; j--)
            lR[j] = max(lR[j], lR[j + 1] - 1);

        // for (int j = 0; j <= M; j++)
        //     cout << lL[j] << " \n"[j == M];
        // for (int j = 0; j <= M; j++)
        //     cout << lR[j] << " \n"[j == M];
        for (int j = 1; j <= M; j++)
            if(lL[j] + lR[j - 1] > ans)
                ans = lL[j] + lR[j - 1], sol = pii(i - lL[j], j - lR[j - 1]);
    }
    return make_pair(ans, sol);
}

signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0);
    cin >> s >> t;
    pair<int, pii> ans1 = solve(s, t);
    reverse(t.begin(), t.end());
    pair<int, pii> ans2 = solve(s, t);
    ans2.S.S = t.size() - 1 - (ans2.S.S + ans2.F - 1);
    pair<int, pii> ans = max(ans1, ans2);

    cout << ans.F << '\n';
    cout << ans.S.F << " " << ans.S.S << '\n';
}
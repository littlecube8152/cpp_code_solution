#include <bits/stdc++.h>
using namespace std;

int maxvalid(int N, int K)
{
    return N - (N / K);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        vector<int> cnt(30, 0);
        string s, t;
        cin >> s >> K;
        N = s.size();
        bool fail = 0;
        for (int i = 0; i < N; i++)
            cnt[s[i] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (cnt[i] > maxvalid(N, K))
                fail = 1;
        if (fail)
        {
            cout << "OH NO!\n";
            continue;
        }
        int last = -1, cont = 0;
        for (int i = 0; i < N; i++)
        {
            vector<int> p(30, 0), s(30, 0);
            for (int j = 0; j < 26; j++)
                p[j + 1] = max(p[j], cnt[j]);
            for (int j = 25; j >= 0; j--)
                s[j] = max(s[j + 1], cnt[j + 1]);
            for (int j = 0; j < 26; j++)
            {
                if (cnt[j] && p[j] <= maxvalid(N - i - 1, K) && s[j] <= maxvalid(N - i - 1, K) && (last != j || cont + 1 < K))
                {
                    if (last == j)
                        cont++;
                    else
                        last = j, cont = 1;
                    cnt[j]--;
                    t.push_back(char('a' + j));
                    break;
                }
                if (j == 25)
                    assert(false);
            }
        }
        cout << t << '\n';
    }
}
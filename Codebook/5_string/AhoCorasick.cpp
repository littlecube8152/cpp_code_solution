#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define sigma 26
struct AhoCorasick
{
    int ch[500005][sigma] = {{}}, f[500005] = {-1}, cnt[500005];
    int idx = 0;
    int insert(string &s)
    {
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!ch[j][s[i] - 'a'])
                ch[j][s[i] - 'a'] = ++idx;
            j = ch[j][s[i] - 'a'];
        }
        return j;
    }
    void build()
    {
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v = 0; v < sigma; v++)
                if (ch[u][v])
                {
                    int cur = f[u];
                    while (cur >= 0)
                        if (ch[cur][v])
                            break;
                        else
                            cur = f[cur];
                    f[ch[u][v]] = (cur < 0 ? 0 : ch[cur][v]);
                    q.push(ch[u][v]);
                }
        }
    }
    void match(string &s)
    {
        for (int i = 0; i <= idx; i++)
            cnt[i] = 0;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            while (j >= 0)
                if (ch[j][s[i] - 'a'])
                    break;
                else
                    j = f[j];
            j = (j < 0 ? 0 : ch[j][s[i] - 'a']);
            cnt[j]++;
        }
        vector<int> v;
        v.emplace_back(0);
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < sigma; j++)
                if (ch[v[i]][j])
                    v.emplace_back(ch[v[i]][j]);
        reverse(v.begin(), v.end());
        for (int i : v)
            if (f[i] > 0)
                cnt[f[i]] += cnt[i];
    }
};
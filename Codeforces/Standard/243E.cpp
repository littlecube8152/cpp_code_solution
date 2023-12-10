#include <bits/stdc++.h>
using namespace std;

int n, vis[500], sup[500], adj[500][500];
vector<int> sub[500];
string s[500];
bitset<500> b[500];

bitset<500> convert(vector<int> v)
{
    bitset<500> cv;
    for (int i : v)
        cv[i] = 1;
    return cv;
}

vector<int> solve(vector<int> r, vector<int> c, vector<int> p, vector<int> s)
{

    bitset<500> cv = convert(c);

    // reduce
    {
        auto reduce = [&](vector<int> v)
        {
            vector<int> res;
            for (int i : v)
            {
                int cnt = (b[i] & cv).count();
                if (cnt != 0 && cnt != c.size())
                    res.emplace_back(i);
            }
            return res;
        };

        r = reduce(r);
        p = reduce(p);
        s = reduce(s);
    }
    

    if (r.empty() && p.empty() && s.empty())
        return c;

    vector<int> cl, cr;

    // Case 1: if not empty
    if (!p.empty() || !s.empty())
    {
        int m = -1, cnt = n + 1;

        if (!p.empty())
        {
            for (int i : p)
            {
                int nxt = (b[i] & cv).count();
                if (nxt < cnt)
                    m = i, cnt = nxt;
            }
            for (int i : c)
                if (b[m][i])
                    cl.emplace_back(i);
                else
                    cr.emplace_back(i);
        }
        else
        {
            for (int i : s)
            {
                int nxt = (b[i] & cv).count();
                if (nxt < cnt)
                    m = i, cnt = nxt;
            }
            for (int i : c)
                if (b[m][i])
                    cr.emplace_back(i);
                else
                    cl.emplace_back(i);
        }

    }
    else
    {
        // find first
        int f = -1;
        
        for (int i : r)
            sup[i] = 0;
        for (int i : r)
            for (int j : sub[i])
                sup[j] = 1;
        for (int i : r)
            if (!vis[i] && !sup[i])
            {
                int m = -1, cnt = -1;
                vis[i] = 1;
                // find maximal
                for (int j : r)
                    if (!adj[i][j] && !adj[j][i])
                    {
                        int nxt = (b[i] & b[j]).count();
                        if (nxt > cnt)
                            m = j, cnt = nxt;
                    }
                bool flag = 0;
                if (m != -1)
                {
                    auto mx = (b[i] & b[m]);
                    for (int j : r)
                        if (!adj[i][j] && !adj[j][i])
                            if (((b[i] & b[j]) | mx) != mx)
                                flag = 1;
                }
                if (flag)
                    continue;

                f = i;
                break;
            }

        if (f == -1)
            return c;
        // cerr << "pivot " << f << '\n';
        for (int i : c)
            if (b[f][i])
                cl.emplace_back(i);
            else
                cr.emplace_back(i);
    }

    auto clv = convert(cl), crv = convert(cr);
    vector<int> pl = p, pr = p,
                sl = s, sr = s,
                rl, rr;
    for (int i : r)
    {
        int inter = 2 * ((b[i] & clv).count() > 0) + 1 * ((b[i] & crv).count() > 0);
        if (inter == 3)
            sl.emplace_back(i), pr.emplace_back(i);
        else if (inter == 2)
            rl.emplace_back(i);
        else if (inter == 1)
            rr.emplace_back(i);
    }
    vector<int> lsol = solve(rl, cl, pl, sl), rsol = solve(rr, cr, pr, sr);
    lsol.insert(lsol.end(), rsol.begin(), rsol.end());
    return lsol;
}

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < n; j++)
            b[i][j] = s[i][j] == '1';
    }

    vector<int> r, c;

    for (int i = 0; i < n; i++)
        r.emplace_back(i), c.emplace_back(i);

    sort(r.begin(), r.end(), [&](int i, int j)
         { return b[i].count() > b[j].count(); });

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((b[r[i]] & b[r[j]]) == b[r[j]])
                sub[r[i]].emplace_back(r[j]), adj[r[i]][r[j]] = 1;
    for (int i = 0; i < n; i++)
        adj[i][i] = 1;

    vector<int> o = solve(r, c, {}, {});

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            s[i][j] = '0' ^ (b[i][o[j]]);

    bool valid = 1;

    for (int i = 0; i < n; i++)
    {
        string t = "0" + s[i] + "0";
        int sw = 0;
        for (int j = 0; j < n + 1; j++)
            sw += t[j] != t[j + 1];
        if (sw > 2)
            valid = 0;
    }

    if (valid)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << s[i] << '\n';
    }
    else
        cout << "NO\n";
}
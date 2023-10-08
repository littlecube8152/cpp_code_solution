/*
    Remember to turn off all debug flags!
*/
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int sigma = 26;
struct Trie
{
    int ch[3000006][sigma], t;
    int newnode()
    {
        ++t;
        for (int i = 0; i < sigma; i++)
            ch[t][i] = 0;
        return t;
    }
    void init()
    {
        t = -1;
        newnode();
    }
    vector<int> insert(string s)
    {
        int i = 0;
        vector<int> ns = {0};
        for (auto c : s)
        {
            if (!ch[i][c - 'a'])
                ch[i][c - 'a'] = newnode();
            ns.emplace_back(i = ch[i][c - 'a']);
        }
        return ns;
    }
} trie;

int T, N, M, Q, l[600005], r[600005], a[3000006], occ[3000006];
vector<int> ids[600005];
vector<pii> rgs[3000006]; // [, )
vector<int> cnts[3000006];
int res[3000006];

struct Mo
{
    int cL, cR;
    bool inside(int i, int L, int R)
    {
        return L <= l[i] && r[i] <= R;
    }
    void move(int k, int val, int delta)
    {
        cnts[k][val]--;
        cnts[k][val + delta]++;
        if (delta == 1 && !cnts[k][res[k]])
            res[k]++;
        if (delta == -1 && cnts[k][res[k] - 1])
            res[k]--;
    }
    void increase(int k, int v)
    {
        rgs[k][v].S--;
        rgs[k][v + 1].F--;
        move(k, v + N - rgs[k][v].S, +1);
    }
    void decrease(int k, int v)
    {
        move(k, v + N - rgs[k][v].F, -1);
        rgs[k][v].F++;
        rgs[k][v - 1].S++;
    }
    void insert(int i)
    {
        // cerr << "insert " << i << '\n';
        for (int j = 1; j < ids[i].size(); j++)
        {
            increase(j, occ[ids[i][j]]);
            occ[ids[i][j]]++;
        }
    }
    void erase(int i)
    {
        // cerr << "erase " << i << '\n';
        for (int j = 1; j < ids[i].size(); j++)
        {
            decrease(j, occ[ids[i][j]]);
            occ[ids[i][j]]--;
        }
    }
    void incL()
    {
        int i = a[cL];
        if (inside(i, cL, cR) ^ inside(i, cL + 1, cR))
            erase(i);
        cL++;
    }
    void decL()
    {
        int i = a[cL - 1];
        if (inside(i, cL, cR) ^ inside(i, cL - 1, cR))
            insert(i);
        cL--;
    }
    void incR()
    {
        int i = a[cR + 1];
        if (inside(i, cL, cR) ^ inside(i, cL, cR + 1))
            insert(i);
        cR++;
    }
    void decR()
    {
        int i = a[cR];
        if (inside(i, cL, cR) ^ inside(i, cL, cR - 1))
            erase(i);
        cR--;
    }
} mo;

signed main()
{
    fast;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        trie.init();
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            ids[i] = trie.insert(s);
            l[i] = r[i - 1] + 1;
            r[i] = r[i - 1] + (int)s.size();
            for (int j = l[i]; j <= r[i]; j++)
                a[j] = i;
        }
        M = r[N];
        const ll B = max(5, (int)sqrt(M));

        for (int i = 1; i <= M; i++)
        {
            occ[i] = 0;
            rgs[i] = vector(M / i + 1, pii(N + 1, N + 1));
            rgs[i][0].F = 0;
            cnts[i] = vector(M / i + 1, 1);
            res[i] = 0;
        }

        ll sum = 0;

        cin >> Q;
        cerr << t << ' ' << N << ' ' << Q << '\n';
        vector<pair<pii, int>> qu;
        for (int i = 1; i <= Q; i++)
        {
            int L, R, K;
            cin >> L >> R >> K;
            L = l[L];
            R = r[R];
            qu.emplace_back(make_pair(pii(L, R), K));
        }
        sort(qu.begin(), qu.end(), [&](pair<pii, int> p, pair<pii, int> q)
             {
            auto [lp, rp] = p.F;
            auto [lq, rq] = q.F;
            return pii(lp / B, rp) < pii(lq / B, rq); });
        mo.cL = 1, mo.cR = 0;
        for (auto [range, k] : qu)
        {
            auto [L, R] = range;
            while (mo.cL < L)
                mo.incL();
            while (mo.cL > L)
                mo.decL();
            while (mo.cR < R)
                mo.incR();
            while (mo.cR > R)
                mo.decR();
            // for (auto [l, r] : rgs[k])
            //     cerr << "(" << l << ", " << r << ") ";
            // cerr << L << ' ' << R << ' ' << res[k] << '\n';
            sum += res[k];
        }
        fill(res, res + M, 0);
        cout << "Case #" << t << ": " << sum << '\n';
    }
}

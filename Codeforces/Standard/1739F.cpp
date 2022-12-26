/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
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

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int sigma = 12;
ll n, dp[1 << sigma][4005];
pii pre[1 << sigma][4005];

struct node
{
    int child[sigma] = {}, fail = 0, nxt[sigma] = {};
    ll w = 0;
};

vector<node> v(2);

void insert(string &s, int pos, int w, int i = 1)
{
    if (pos == s.size())
    {
        v[i].w += w;
        return;
    }
    if (!v[i].child[s[pos] - 'a'])
    {
        v[i].child[s[pos] - 'a'] = v.size();
        v.emplace_back(node());
    }
    insert(s, pos + 1, w, v[i].child[s[pos] - 'a']);
}

void build_fail()
{
    for (int i = 0; i < sigma; i++)
        v[0].child[i] = 1, v[0].nxt[i] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < sigma; i++)
            if (v[u].child[i])
            {
                int j = v[u].child[i], cur = v[u].fail;
                while (!v[cur].child[i])
                    cur = v[cur].fail;
                v[j].fail = v[cur].child[i];
                q.push(j);
            }
    }
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < sigma; i++)
            if (v[u].child[i])
            {
                int j = v[u].child[i];
                v[u].nxt[i] = j;
                q.push(j);
            }
            else
                v[u].nxt[i] = v[v[u].fail].nxt[i];
        v[u].w += v[v[u].fail].w;
    }
}

void process(string s, int c)
{
    bool use[sigma] = {};
    string t = " ";
    t += s[0];
    t += " ";
    use[s[0] - 'a'] = 1;
    for (int i = 1, j = 1; i < s.size(); i++)
    {
        if (s[i] == t[j - 1])
            j--;
        else if (s[i] == t[j + 1])
            j++;
        else if (use[s[i] - 'a'])
            return;
        else
        {
            if (j == 1)
            {
                t.insert(t.begin() + 1, s[i]);
                use[s[i] - 'a'] = 1;
            }
            else if (j + 2 == t.size())
            {
                t.insert(t.end() - 1, s[i]);
                use[s[i] - 'a'] = 1;
                j++;
            }
            else
                return;
        }
    }
    t.pop_back();
    insert(t, 1, c);
    reverse(t.begin(), t.end());
    t.pop_back();
    insert(t, 0, c);
}

void debug(int i, string s)
{
    cout << i << ' ' << s << ' ' << v[i].fail << ' ' << v[i].w << '\n';
    for (int j = 0; j < sigma; j++)
        if (v[i].child[j])
            debug(v[i].child[j], s + char('a' + j));
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c;
        string s;
        cin >> c >> s;
        process(s, c);
    }
    build_fail();
    // debug(1, "");
    for (int mask = 0; mask < (1 << sigma); mask++)
        for (int state = 1; state < v.size(); state++)
            dp[mask][state] = -1e9;
    dp[0][1] = 0;
    for (int mask = 0; mask < (1 << sigma); mask++)
        for (int state = 1; state < v.size(); state++)
            for (int b = 0; b < sigma; b++)
                if (!((mask >> b) & 1))
                {
                    int val = dp[mask][state] + v[v[state].nxt[b]].w;
                    if (val > dp[mask ^ (1 << b)][v[state].nxt[b]])
                        dp[mask ^ (1 << b)][v[state].nxt[b]] = val, pre[mask ^ (1 << b)][v[state].nxt[b]] = pii(b, state);
                }
    int mask = (1 << sigma) - 1, mx = 1;
    for (int state = 1; state < v.size(); state++)
        if (dp[mask][state] > dp[mask][mx])
            mx = state;
    // cerr << dp[mask][mx] << '\n';
    for (int i = 0; i < sigma; i++)
    {
        cout << char('a' + pre[mask][mx].F);
        tie(mask, mx) = make_tuple(mask ^ (1 << pre[mask][mx].F), pre[mask][mx].S);
    }
    cout << '\n';
}

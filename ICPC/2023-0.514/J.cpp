/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

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

vector<int> sa, cnt, rk, tmp, lcp;
void SA(string s)
{
    int n = s.size();
    sa.resize(n), cnt.resize(n), rk.resize(n), tmp.resize(n);
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

const ll mod = 1234567891, base = 27, ibase = 777320524;
int n;
ll h[200005], bp[200005], ibp[200005], dupe[1000];
string s;

struct sparse
{
    const int P = 20;
    int arr[200005][20];
    void build()
    {
        for (int i = 1; i <= n; i++)
            arr[i][0] = lcp[i];
        for (int p = 0; p + 1 < P; p++)
            for (int i = 1; i + (1 << p) <= n; i++)
                arr[i][p + 1] = min(arr[i][p], arr[i + (1 << p)][p]);
    }
    int query(int L, int R)
    {
        if (L == R)
            return n;
        int p = __lg(R - L);
        return min(arr[L + 1][p], arr[R - (1 << p) + 1][p]);
    }
} table;

struct segment
{
    int seg[800005];
    void init()
    {
        for (int i = 1; i <= 4 * n; i++)
            seg[i] = n + 1;
    }
    void on(int p, int v, int i = 1, int L = 1, int R = n)
    {
        seg[i] = min(seg[i], v);
        if (L == R)
            return;
        int mid = (L + R) / 2;
        if (p <= mid)
            on(p, v, i << 1, L, mid);
        else
            on(p, v, i << 1 | 1, mid + 1, R);
    }
    int query(int mL, int mR, int i = 1, int L = 1, int R = n)
    {
        if (mL <= L && R <= mR)
            return seg[i];
        else if (R < mL || mR < L)
            return n + 1;
        else
        {
            int mid = (L + R) / 2;
            return min(query(mL, mR, i << 1, L, mid), query(mL, mR, i << 1 | 1, mid + 1, R));
        }
    }
} segt;

signed main()
{
    fast;
    cin >> n >> s;

    bp[0] = ibp[0] = 1;
    for (int i = 1; i <= n; i++)
        bp[i] = bp[i - 1] * base % mod,
        ibp[i] = ibp[i - 1] * ibase % mod;
    for (int i = 0; i < n; i++)
        h[i] = s[i] - 'a';
    for (int i = 1; i < n; i++)
        h[i] = (h[i - 1] + h[i] * bp[i]) % mod;

    s += '$';
    SA(s);
    LCP(s);

    // for (int i = 0; i <= n; i++)
    //     cout << sa[i] << " \n"[i == n];
    // for (int i = 0; i <= n; i++)
    //     cout << lcp[i] << " \n"[i == n];

    table.build();
    segt.init();
    int ans = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int m = rk[i], cur = 1, len = 1;
        bool b = 1;
        while (b)
        {
            int rL, rR, l, r;
            // search left
            rL = 1, rR = m;
            while (rL < rR)
            {
                int rM = (rL + rR) / 2;
                if (table.query(rM, m) < len)
                    rL = rM + 1;
                else
                    rR = rM;
            }
            l = rL;

            // search right
            rL = m, rR = n;
            while (rL < rR)
            {
                int rM = (rL + rR + 1) / 2;
                if (table.query(m, rM) >= len)
                    rL = rM;
                else
                    rR = rM - 1;
            }
            r = rL;

            // check best
            int nxt = segt.query(l, r);
            // cerr << "range: " << l << ' ' << r << '\n';
            // cerr << "find increament " << nxt << '\n';
            if (nxt + len > n)
                b = 0;
            else if (nxt <= i + len - 1)
            {
                // [     ]
                //     [     ]
                //       | B |
                // find most B
                int head = i + len, rep = nxt + len - head, cnt = 0;
                dupe[0] = (h[head + rep - 1] - h[head - 1] + mod) * ibp[head] % mod;

                for (int p = 0; rep * (1LL << p) < n; p++)
                    dupe[p + 1] = (1 + bp[rep * (1 << p)]) * dupe[p] % mod;
                for (int p = 20; p >= 0; p--)
                    if (head + (cnt + (1LL << p)) * rep > n)
                        continue;
                    else if (bp[head + cnt * rep] * dupe[p] % mod == (h[head + (cnt + (1 << p)) * rep - 1] - h[head + cnt * rep - 1] + mod) % mod)
                        cnt += (1 << p);
                cur += cnt;
                len += cnt * rep;
                // assert(cnt >= 1);
            }
            else
            {
                cur++;
                len = nxt + len - i;
            }
            // cerr << i << ' ' << cur << ' ' << len << '\n';
        }
        ans = max(ans, cur);
        segt.on(m, i);
    }
    cout << ans << '\n';
}

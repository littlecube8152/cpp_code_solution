#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

#define base ll
#define mxN 1 << 19
const ll mod = 998244353, g = 3;
base omega[mxN], omega_[mxN];
int rev[mxN];

ll fpow(ll b, ll p)
{
    ll a = 1;
    while (p)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

ll inverse(ll a)
{
    return fpow(a, mod - 2);
}

void calcW(int n)
{
    ll r = fpow(g, (mod - 1) / n), invr = inverse(r);
    omega[0] = omega_[0] = 1;
    for (int i = 1; i < n; i++)
    {
        omega[i] = omega[i - 1] * r % mod;
        omega_[i] = omega_[i - 1] * invr % mod;
    }
}

void calcrev(int n)
{
    int k = __lg(n);
    for (int i = 0; i < n; i++)
        rev[i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            if (i & (1 << j))
                rev[i] ^= 1 << (k - j - 1);
}

vector<base> NTT(vector<base> poly, bool inv)
{
    base *w = (inv ? omega_ : omega);
    int n = poly.size();
    for (int i = 0; i < n; i++)
        if (rev[i] > i)
            swap(poly[i], poly[rev[i]]);

    for (int len = 1; len < n; len <<= 1)
    {
        int arg = n / len / 2;
        for (int i = 0; i < n; i += 2 * len)
            for (int j = 0; j < len; j++)
            {
                base odd = w[j * arg] * poly[i + j + len] % mod;
                poly[i + j + len] = (poly[i + j] - odd + mod) % mod;
                poly[i + j] = (poly[i + j] + odd) % mod;
            }
    }
    base invN = inverse(n);
    if (inv)
        for (auto &a : poly)
            a = a * invN % mod;
    return poly;
}

vector<base> mul(vector<base> f, vector<base> g)
{
    int n = f.size() + g.size();
    int sz = 1 << (__lg(n - 1) + 1);
    f.resize(sz), g.resize(sz);
    calcrev(sz);
    calcW(sz);
    f = NTT(f, 0), g = NTT(g, 0);
    for (int i = 0; i < sz; i++)
        f[i] = f[i] * g[i] % mod;
    f = NTT(f, 1);
    f.resize(n);
    return f;
}

int N, off[100005];
ll ans, fac[100005], ifac[100005];
vector<base> dp[100005];

char next(char c)
{
    if (c == 'R')
        return 'P';
    if (c == 'P')
        return 'B';
    if (c == 'B')
        return 'Y';
    return 'R';
}

ll C(int n, int k)
{
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

void solve(string s)
{
    s.push_back(s[0]);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i <= 2 * N; i++)
        off[i] = 0, dp[i].clear();

    // PRY = YRP <=> PR = RP
    // consider PRP contributes both
    // therefore
    // B -> P      P -> R (+1)
    // B -> Y      P -> B
    // R -> Y      Y -> B
    // R -> P (-1) Y -> R
    // (x + 1) ^ N
    // [0B] -> [0Y, 0P] -> [0R, 0B, 1R] -> [-1P, 0Y, 0P, 1Y] -> [-1B, 0R, 0B, 1R, 1B]
    // [0R, 0B] -> [-1P, 0Y, 0P] -> [-1B, 0R, 0B, 1R]
    //         0R  0B
    //      -1P  0Y  0P
    //    -1B  0R  0B  1R
    //  -1Y -1P  0Y  0P  1Y
    //-1R -1B  0R  0B  1R  1B
    // Y:back, P: back+1, R:front-1, B:front

    for (int i = 0, j = 1; j <= 2 * N; i = j++)
    {
        while (s[j] == '?')
            j++;
        int len = j - i;
        deque<int> dq = {0};
        char cur = s[i];
        for (int k = 1; k <= len; k++)
        {
            if (cur == 'Y')
                dq.emplace_back(dq.back() + (dq.size() + 1) % 2);
            else if (cur == 'P')
                dq.emplace_back(dq.back() + dq.size() % 2);
            else if (cur == 'R')
                dq.emplace_front(dq.front() - 1);
            else if (cur == 'B')
                dq.emplace_front(dq.front());
            cur = next(cur);
        }
        off[i] = -dq.front();
        dp[i].resize(dq.back() + off[i] + 1);
        
        for (int k = 0; k <= len; k++)
        {
            if (cur == s[j])
                dp[i][dq[k] + off[i]] = C(len, k);
            cur = next(next(cur));
        }
        pq.push(pii(dp[i].size(), i));
    }
    while (pq.size() >= 2)
    {
        int i = pq.top().S;
        pq.pop();
        int j = pq.top().S;
        pq.pop();
        dp[i] = mul(dp[i], dp[j]);
        off[i] += off[j];
        pq.push(pii(dp[i].size(), i));
    }
    int last = pq.top().S;
    ans = (ans + dp[last][off[last]]) % mod;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;

    cin >> N;
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= 2 * N; i++)
        ifac[i] = inverse(fac[i] = fac[i - 1] * i % mod);
    cin >> s;
    if (s[0] == '?')
    {
        s[0] = 'Y';
        solve(s);
        s[0] = 'P';
        solve(s);
    }
    else
        solve(s);
    cout << ans << '\n';
}
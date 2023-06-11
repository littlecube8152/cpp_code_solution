/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
//using namespace __gnu_pbds;

#define LOCAL

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> val)
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

int n, q, arr[100005][2], ps[100005], pstable[100005][21];
pii table[100005][21], segL[400005], segR[400005], seg[400005];
vector<int> v;

void build(int i, int L, int R)
{
    if (L == R)
        seg[i] = segL[i] = segR[i] = pll{max(0LL, arr[L][0]), min(0LL, arr[L][0])};
    else
    {
        int mid = (L + R) / 2;
        build(i * 2, L, mid);
        build(i * 2 + 1, mid + 1, R);
        seg[i] = pll{max(0LL, segR[i * 2].F) + max(0LL, segL[i * 2 + 1].F), min(0LL, segR[i * 2].S) + min(0LL, segL[i * 2 + 1].S)};
        segL[i] = pll{max(max(0LL, segL[i * 2].F), pstable[mid][0] - pstable[L - 1][0] + max(0LL, segL[i * 2 + 1].F)),
                      min(min(0LL, segL[i * 2].S), pstable[mid][0] - pstable[L - 1][0] + min(0LL, segL[i * 2 + 1].S))};
        segL[i] = pll{max(max(0LL, segR[i * 2 + 1].F), pstable[R][0] - pstable[mid][0] + max(0LL, segR[i * 2].F)),
                      min(min(0LL, segR[i * 2 + 1].S), pstable[R][0] - pstable[mid][0] + min(0LL, segR[i * 2].S))};
    }
}

pair<pair<pll, pll>, pll> query(int i, int L, int R, int qL, int qR)
{
    if (qL <= L && qR <= R)
        return make_pair(make_pair(segL[i], segR[i]), seg[i]);
    if (qR < L || R < qL)
        return make_pair(make_pair(pll{0, 0}, pll{0, 0}), pll{0, 0});
    else
    {
        int mid = (L + R) / 2;
        pair<pair<pll, pll>, pll> left = query(i * 2, L, mid, qL, qR), right = query(i * 2 + 1, mid + 1, R, qL, qR), ans;
        ans.S = pll{max(0LL, left.F.S.F) + max(0LL, right.F.F.F), min(0LL, left.F.S.S) + min(0LL, right.F.F.S)};
        ans.F.F = pll{max(max(0LL, left.F.F.F), pstable[mid][0] - pstable[max(L, qL) - 1][0] + max(0LL, right.F.F.F)),
                      min(min(0LL, left.F.F.S), pstable[mid][0] - pstable[max(L, qL) - 1][0] + min(0LL, right.F.F.S))};
        ans.F.S = pll{max(max(0LL, right.F.S.F), pstable[min(R, qR)][0] - pstable[mid][0] + max(0LL, left.F.S.F)),
                      min(min(0LL, right.F.S.S), pstable[min(R, qR)][0] - pstable[mid][0] + min(0LL, left.F.S.S))};
        return ans;
    }
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i][0];
    for (int i = 1; i <= n; i++)
        cin >> arr[i][1];
    for (int i = 1; i <= n; i++)
        arr[i][0] -= arr[i][1];

    for (int i = 1; i <= n; i++)
        pstable[i][0] = pstable[i - 1][0] + arr[i][0];
    for (int p = 1; p <= 20; p++)
        for (int i = 1; i <= n; i++)
            pstable[i][p] = max(pstable[i][p - 1], pstable[min(n, i + (1 << (p - 1)))][p - 1]);

    for (int i = 1; i <= n; i++)
        if ((arr[i][0] != abs(arr[i][0])) ^ (arr[i - 1][0] != abs(arr[i - 1][0])))
        {
            v.push_back(i - 1);
            table[i][0].F = abs(arr[i][0]);
        }
        else
            table[i][0].F = table[i - 1][0].F + abs(arr[i][0]);

    for (int i = n; i >= 1; i--)
        if ((arr[i][0] != abs(arr[i][0])) ^ (arr[i + 1][0] != abs(arr[i + 1][0])))
            table[i][0].S = abs(arr[i][0]);
        else
            table[i][0].S = table[i + 1][0].S + abs(arr[i][0]);

    for (int p = 1; p <= 20; p++)
        for (int i = 1; i <= n; i++)
        {
            table[i][p].F = max(table[i][p - 1].F, table[min(n, i + (1 << (p - 1)))][p - 1].F);
            table[i][p].S = max(table[i][p - 1].S, table[min(n, i + (1 << (p - 1)))][p - 1].S);
        }

    build(1, 1, n);

    for (int i = 1; i <= q; i++)
    {
        int l, r, lg;
        cin >> l >> r;
        lg = __lg(r - l + 1);
        if (max(pstable[l][lg], pstable[r - (1 << lg) + 1][lg]) - pstable[l - 1][0] > 0 || pstable[r][0] - pstable[l - 1][0] != 0)
            cout << -1 << '\n';
        else
        {
            cout << max(query(1, 1, n, l, r).S.F, -query(1, 1, n, l, r).S.S) << '\n';
        }
    }
}

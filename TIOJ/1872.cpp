#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       using namespace std;

struct SegTree
{
    int L, R, val;
    SegTree *l, *r;
    int mid;
    SegTree(int L, int R, int val, SegTree *l, SegTree *r) : L(L), R(R), val(val), l(l), r(r), mid((L + R) / 2){};
    void pull()
    {
        val = max((l == nullptr ? 0 : l->val), (r == nullptr ? 0 : r->val));
    }
    void build_left()
    {
        if (l == nullptr)
            l = new SegTree(L, mid, 0, nullptr, nullptr);
    }
    void build_right()
    {
        if (r == nullptr)
            r = new SegTree(mid + 1, R, 0, nullptr, nullptr);
    }
    void modify(int id, int val)
    {
        if (L == id && id == R)
        {
            this->val = val;
            return;
        }
        if (id <= mid)
        {
            build_left();
            l->modify(id, val);
        }
        else
        {
            build_right();
            r->modify(id, val);
        }
        pull();
    }
    int query(int L, int R)
    {
        if (L <= this->L && this->R <= R)
            return this->val;
        if (R <= mid)
            return (l == nullptr ? 0 : l->query(L, R));
        if (mid + 1 <= L)
            return (r == nullptr ? 0 : r->query(L, R));
        return max((l == nullptr ? 0 : l->query(L, R)), (r == nullptr ? 0 : r->query(L, R)));
    }
};

ll fastpow(int base, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return base;
    if (p % 2)
    {
        ll res = (fastpow(base, p - 1) * base);
        if (res >= MOD)
            return res % MOD;
        return res;
    }
    ll half = fastpow(base, p / 2), res = half * half;
    if (res >= MOD)
        return res % MOD;
    return res;
}

int n, q;
SegTree *root[80000] = {nullptr};
SegTree *maxmium;
vector<int> prime = {2};
int notprime[1000005] = {1, 1};

signed main()
{
    fast;
    for (int i = 2; i <= 1000000; i++)
    {
        if (!notprime[i])
            prime.emplace_back(i), notprime[i] = i; 
        for (auto j : prime)
        {
            if (i * j > 1000000)
                break;
            notprime[i * j] = j;
            if (!(i % j))
                break;
        }
    }
    cin >> n >> q;
    for (int i = 0; i < 80000; i++)
        root[i] = new SegTree(1, n, 0, nullptr, nullptr);
    maxmium = new SegTree(1, n, 0, nullptr, nullptr);
    for (int i = 1; i <= n; i++)
    {
        int x, maxprime = 1;
        cin >> x;
        for (int j = 0; j < prime.size() && prime[j] <= sqrt(x); j++)
        {
            int cnt = 0;
            if(prime[j] != notprime[j])
                continue;
            while (x > 1 && (x / prime[j]) * prime[j] == x)
                cnt++, x /= prime[j];
            if (cnt)
            {

                maxprime = max(maxprime, prime[j]);
                //printf("Modify %d %d^%d\n", i, prime[j], cnt);
                root[j]->modify(i, cnt);
            }
        }
        if (x > 1)
        {
            root[(lower_bound(prime.begin(), prime.end(), x) - prime.begin())]->modify(i, 1);
            maxprime = max(maxprime, x);
        }
        maxmium->modify(i, maxprime);
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        ll res = 1, maxprime = maxmium->query(x, y);

        for (int j = 0; j < prime.size() && prime[j] <= maxprime; j++)
        {
            int p = root[j]->query(x, y);
            if (p != 0)
                // printf("Query %d-%d %d^%d\n", x, y, prime[j], root[j]->query(x, y));
                res = (res * fastpow(prime[j], p));
            if (res >= MOD)
                res %= MOD;
        }
        cout << res << '\n';
    }
}
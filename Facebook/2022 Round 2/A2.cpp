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

const ll mod = 9267341735543;
ll bit[1000006], A[1000006], B[1000006], h[1000006], N, Q, type[1000006], L[1000006], R[1000006];
vector<ll> v;
bool valid[1000006];

void modify(int pos, ll val)
{
    for (int i = pos; i <= N; i += (i & -i))
        bit[i] = (bit[i] + val + mod) % mod;
}

ll query(int pos)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans = (bit[i] + ans + mod) % mod;
    return ans;
}

int solve()
{
    
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> type[i] >> L[i] >> R[i];

    int t = 8;

    while (t--)
    {
        mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
        v.clear();
        for (int i = 1; i <= 1000000; i++)
        {
            h[i] = rd() % mod;
            v.emplace_back(h[i]);
        }
        sort(v.begin(), v.end());

        for (int i = 1; i <= N; i++)
            bit[i] = 0, B[i] = A[i];
        for (int i = 1; i <= N; i++)
            modify(i, h[B[i]]);

        for (int i = 1; i <= Q; i++)
            if (type[i] == 2)
                valid[i] = 1;
            else
                valid[i] = 0;

        for (int i = 1; i <= Q; i++)
        {
            if (type[i] == 1)
            {
                modify(L[i], (h[R[i]] - h[B[L[i]]]) % mod);
                B[L[i]] = R[i];
            }
            else
            {
                if ((R[i] - L[i]) % 2 == 1)
                {
                    valid[i] = 0;
                    continue;
                }

                int mid = (L[i] + R[i]) / 2;
                if (L[i] == R[i])
                    continue;

                ll diff = ((query(mid) - query(L[i] - 1)) - (query(R[i]) - query(mid)) + 4 * mod) % mod;
                auto iter = lower_bound(v.begin(), v.end(), diff);
                if (iter != v.end() && *iter == diff)
                    continue;

                diff = ((query(R[i]) - query(mid - 1)) - (query(mid - 1) - query(L[i] - 1)) + 4 *  mod) % mod;
                iter = lower_bound(v.begin(), v.end(), diff);
                if (iter != v.end() && *iter == diff)
                    continue;
                else
                    valid[i] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= Q; i++)
        ans += valid[i];

    return ans;
}

signed main()
{
    fast;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        cout << solve() << '\n';
        cerr << "End Case " << t << ".\n";
    }
}

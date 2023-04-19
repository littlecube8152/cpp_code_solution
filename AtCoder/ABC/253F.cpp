/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
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
#define _INFINITY 9223372036854775807
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

ll N, M, Q, bit[200005], ans[200005], out[200005];
pii cover[200005];

vector<tuple<int, int, int, int, ll>> event;

void modify(int pos, ll val)
{
    for (int i = pos; i <= M; i += (i & -i))
        bit[i] += val;
}

ll query(int pos)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

signed main()
{
    //fast;
    cin >> N >> M >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int t, l, r, x;
        cin >> t;
        if(t == 1)
        {
            cin >> l >> r >> x;
            event.emplace_back(make_tuple(i, 1, l, r, x));
        }
        else if(t == 2)
        {
            cin >> l >> x;
            cover[l] = pii(i, x);
        }
        else if(t == 3)
        {
            cin >> l >> r;
            out[i] = 1;
            ans[i] = cover[l].S;
            // cout << cover[l].F << " " << "now" << '\n';
            event.emplace_back(make_tuple(cover[l].F, 3, i, r, -1));
            event.emplace_back(make_tuple(i, 3, i, r, 1));
        }
    }
    sort(event.begin(), event.end());
    for(auto [t, ty, l, r, x] : event)
    {
        if(ty == 1)
        {
            modify(l, x);
            modify(r + 1, -x);
            // cout << "modify\n";
        }
        else if(ty == 3)
        {
            ans[l] += query(r) * x;
            // cout << l << " pos " << r << " " << query(r) <<  " mul " << x << '\n';
        }
        // cout << t << '\n';
        //for (int i = 1; i <= M; i++)
            // cout << query(i) << " \n"[i == M];
    }
    for (int i = 1; i <= Q; i++)
        if(out[i])
             cout << ans[i] << '\n';
}

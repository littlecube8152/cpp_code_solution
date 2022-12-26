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

ll n, sum, ans[100005], b[100005];
vector<int> prime = {1, 1};
bitset<4876300> notprime;
signed main()
{
    fast;
    cin >> n;
    for (int i = 2; prime.size() <= n + 1; i++)
    {
        if (!notprime[i])
            prime.emplace_back(i);
        for (auto j : prime)
        {
            if (i * j >= 4876300)
                break;
            notprime[i * j] = 1;
            if (i % j == 0 && j != 1)
                break;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if(b[i] > 2)
        {
            ans[i] += (b[i] - 1) / 2;
            b[i] -= ans[i] * 2;
        }
        sum += b[i] * prime[i];
    }
    if(sum % 2 == 1)
    {
        cout << "-1\n";
        return 0;
    }
    sum /= 2;
    for (int i = n; i >= 1; i--)
    {
        if(sum >= prime[i] && b[i])
        {
            ll cnt = min(b[i], sum / prime[i]);
            sum -= prime[i] * cnt;
            ans[i] += cnt;
        }
    }
    if(sum)
        cout << -1 << '\n';
    else
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " \n"[i == n];
}

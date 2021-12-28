/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/

#include <bits/stdc++.h>
//#pragma pack(0)
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
#if __has_include("lib2211.h")
#include "lib2211.h"
#else
vector<int> f = {0};
int _n;
int Init()
{
    cout << "Init\n";
    cin >> _n;
    for (int i = 1; i <= _n; i++)
    {
        int fx;
        //cin >> fx;
        //f.emplace_back(fx);
        f.emplace_back(i);
    }
    random_shuffle(f.begin() + 1, f.end());
    return _n;
}

int Query(int a, int b)
{
    //cout << "Query " << a << " " << b << '\n';
    int res = a;
    for (int i = 1; i <= b; i++)
        res = f[res];
    return res;
}

void Report(int k)
{
    if (f[k] == 1)
        cout << "Accepted";
    else
        cout << "Wrong Answer";
}
#endif

vector<ll> p = {0}, op;
map<int, int> fab;
const double eps = 0.4;
bool exists[100005];
ll n, opt = 0, now = 0;
signed main()
{
    mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
    n = Init();
    for (int t = 1; t <= 1; t++)
    {
        for (int i = 1; i <= n; i++)
            exists[i] = 0;
        p.clear();
        p = {0, n};
        for (ll i = 0; i < 798; i++)
        {
            int s = rd();
            //p.push_back((s % 2 ? n - floor(sqrt(rd() % (n * n / 4))) : floor(sqrt(rd() % (n * n / 4)))));
            p.push_back(rd() % n + 1);
        }
        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end()) - p.begin());
        now = 0;
        for (int i : p)
            for (int j : p)
                if (!exists[abs(i - j)])
                    exists[abs(i - j)] = true, now++;
        if (now > opt)
            op.swap(p), opt = now;
    }
    cerr << opt << " / " << n << '\n';
    for (int i = 1; i < op.size(); i++)
    {
        int k = Query(1, op[i]);
        if (fab[k] != 0)
        {
            int ans = Query(1, abs(op[i] - fab[k]) - 1);
            Report(ans);
            return 0;
        }
        else if (k == 1)
        {

            int ans = (op[i] == 1 ? 1 : Query(1, op[i] - 1));
            Report(ans);
            return 0;
        }
        fab[k] = op[i];
    }
    //return 48763;
}

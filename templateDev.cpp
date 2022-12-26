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

class Debugger
{
#define os cerr
    const string yellow = "\033[1;33m";
    const string reset = "\033[0m";
    template <typename T>
    void operator()(T &val)
    {
        os << val;
    }
    template <typename T>
    void operator()(vector<T> &val)
    {
        for (size_t i = 0; i < val.size(); ++i)
        {
            os << (i == 0 ? "[" : ", ");
            this(val[i]);
        }
        os << ']';
    }
    template <typename T, size_t size>
    void operator()(array<T, size> &val)
    {
        for (size_t i = 0; i < val.size(); ++i)
        {
            os << (i == 0 ? "[" : ", ");
            this(val[i]);
        }
        os << ']';
    }
    template <typename T, typename U>
    void operator()(pair<T, U> &val)
    {
        os << '(';
        this(val.first);
        os << ", ";
        this(val.second);
        os << ')';
    }
    template <class T, size_t... S>
    void tupleHelper(const T &val, std::index_sequence<S...>)
    {
        os << "(";
        (..., (os << (S == 0 ? "" : ", ") << std::get<S>(val)));
        os << ")\n";
    }
    template <class... T>
    void operator()(const std::tuple<T...> &val)
    {
        tupleHelper(val, std::make_index_sequence<sizeof...(T)>());
    }
    template <typename T, typename U>
    void operator()(pair<T, U> &val)
    {
        os << '(';
        this(val.first);
        os << ", ";
        this(val.second);
        os << ')';
    }
} debugger;

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

signed main()
{
    fast;
}

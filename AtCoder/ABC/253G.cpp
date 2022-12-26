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

ll N, L, R;
deque<int> dq[2];

signed main()
{
    // fast;
    cin >> N >> L >> R;
    ll acc = 0;
    for (int i = 1; i <= N; i++)
        dq[(i - 1) % 2].emplace_back(i);
    
    for (int i = 1; i < N; i++)
    {

        ll nxt = acc + N - i;
        if (nxt < L || R <= acc)
        {
            cout << dq[0].front() << " ";
            dq[0].pop_front();
            dq[0].swap(dq[1]);
        }
        else if ((acc < L && L <= nxt) || (acc <= R && R < nxt))
        {
            for (int j = i + 1; j <= N; j++)
                if (L <= acc + j - i && acc + j - i <= R)
                    swap(dq[0].front(), dq[(j - i) % 2][(j - i) / 2]);
            cout << dq[0].front() << " ";
            dq[0].pop_front();
            dq[0].swap(dq[1]);
        }
        else
        {
            if ((N - i) % 2 == 1)
            {
                cout << dq[1].back() << " ";
                dq[1].pop_back();
            }
            else
            {
                cout << dq[0].back() << " ";
                dq[0].pop_back();
            }
        }
        acc = nxt;
    }
    cout << dq[0].front() << '\n';
}

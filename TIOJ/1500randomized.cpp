#include <bits/extc++.h>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

struct custom_hash
{
    static uint64_t splitmix64(pll x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x.F += 0x9e3779b97f4a7c15;
        x.S = (x.S ^ (x.F >> 30)) * 0xbf58476d1ce4e5b9;
        x.F = (x.F ^ (x.S >> 27)) * 0x94d049bb133111eb;
        return x.S ^ (x.F >> 31);
    }

    size_t operator()(pll x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(pll{x.F + FIXED_RANDOM, x.S + FIXED_RANDOM});
    }
};

int N;
vector<pll> v;
vector<int> point;
const vector<pll> diff = {{0, 0}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
ld dis(pll p1, pll p2)
{
    return sqrt(double(p1.F - p2.F) * (p1.F - p2.F) + double(p1.S - p2.S) * (p1.S - p2.S));
}

pll point_hash(pll p, ld ans)
{
    return pll{p.F / ans, p.S / ans};
}

pll operator+(pll p1, pll p2)
{
    return pll{p1.F + p2.F, p1.S + p2.S};
}

void solve()
{
    unordered_map<pll, int, custom_hash> table;
    mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
    v.resize(N + 1);
    point.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> v[i].F >> v[i].S;
    shuffle(v.begin() + 1, v.end(), rd);

    ld ans = dis(v[1], v[2]);
    point[1] = table[point_hash(v[1], ans)];
    table[point_hash(v[1], ans)] = 1;
    point[2] = table[point_hash(v[2], ans)];
    table[point_hash(v[2], ans)] = 2;

    for (int R = 3; R <= N; R++)
    {
    start:
        //cout << R << " " << ans << '\n';
        if(ans <= 1e-7)
            break;
        for (pll d : diff)
        {
            int idx = table[point_hash(v[R], ans) + d];
            while (idx != 0)
            {
                if (dis(v[R], v[idx]) < ans)
                {
                    //cout << v[R].F << " " << v[R].S << "  " << v[idx].F << " " << v[idx].S << '\n';
                    ans = dis(v[R], v[idx]);
                    table.clear();
                    for (int i = 1; i < R; i++)
                    {
                        point[i] = table[point_hash(v[i], ans)];
                        table[point_hash(v[i], ans)] = i;
                    }
                    goto start;
                }
                idx = point[idx];
            }
        }
        point[R] = table[point_hash(v[R], ans)];
        table[point_hash(v[R], ans)] = R;
    }
    cout << ans << '\n';
}

signed main()
{
    //fast;
    cout << fixed << setprecision(6);
    while (cin >> N)
    {
        if (N == 1)
            cout << "0.000000" << '\n';
        else
            solve();
    }
}
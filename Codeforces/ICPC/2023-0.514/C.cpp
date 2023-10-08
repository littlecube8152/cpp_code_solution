/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

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

// I am sorry I haven't learned this algo :(
template <typename T>
struct Hungarian
{
    Hungarian() = default;
    Hungarian(int n) : w(n * n), lx(n), ly(n), slack(n), mx(n), my(n), px(n), py(n), sy(n) {}
    int size() const noexcept
    {
        return (int)lx.size();
    }
    T &operator()(int x, int y) noexcept
    {
        return w[x * size() + y];
    }
    T run()
    {
        constexpr T INF = std::numeric_limits<T>::max();
        int const n = size();
        fill(ly.begin(), ly.end(), 0);
        fill(my.begin(), my.end(), -1);
        for (int x = 0; x < n; ++x)
        {
            lx[x] = *max_element(w.cbegin() + x * n, w.cbegin() + (x + 1) * n);
        }
        for (int x = 0; x < n; ++x)
        {
            fill(slack.begin(), slack.end(), INF);
            fill(px.begin(), px.end(), -1);
            fill(py.begin(), py.end(), -1);
            px[x] = -2;
            if (dfs(x))
            {
                continue;
            }
            while (1)
            {
                T d = INF;
                for (int y = 0; y < n; ++y)
                    if (py[y] == -1)
                    {
                        d = std::min(d, slack[y]);
                    }
                for (int x2 = 0; x2 < n; ++x2)
                    if (px[x2] != -1)
                    {
                        lx[x2] -= d;
                    }
                for (int y = 0; y < n; ++y)
                {
                    if (py[y] != -1)
                    {
                        ly[y] += d;
                    }
                    else
                        slack[y] -= d;
                }
                for (int y = 0; y < n; ++y)
                    if (py[y] == -1 && slack[y] == 0)
                    {
                        py[y] = sy[y];
                        if (my[y] == -1)
                        {
                            augment(y);
                            goto next_x;
                        }
                        px[my[y]] = y;
                        if (dfs(my[y]))
                        {
                            goto next_x;
                        }
                    }
            }
        next_x:;
        }
        T res = 0;
        for (int y = 0; y < n; ++y)
        {
            mx[my[y]] = y;
            res += w[my[y] * n + y];
        }
        return res;
    }
    // private:
    std::vector<T> w, lx, ly, slack;
    std::vector<int> mx, my, px, py, sy;
    bool dfs(int x)
    {
        int const n = size();
        for (int y = 0; y < n; ++y)
            if (py[y] == -1)
            {
                T d = lx[x] + ly[y] - w[x * n + y];
                if (d == 0)
                {
                    py[y] = x;
                    if (my[y] == -1)
                    {
                        augment(y);
                        return true;
                    }
                    if (px[my[y]] == -1)
                    {
                        px[my[y]] = y;
                        if (dfs(my[y]))
                        {
                            return true;
                        }
                    }
                }
                else if (slack[y] > d)
                {
                    slack[y] = d;
                    sy[y] = x;
                }
            }
        return false;
    }
    void augment(int y)
    {
        while (y != -2)
        {
            my[y] = py[y];
            y = px[my[y]];
        }
    }
};

int n;
pii p[400];

#define MAXN 800
#define INF 1'000'000'000'000'000

signed main()
{            
    fast;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].F >> p[i].S;
    sort(p, p + n, [&](pii p1, pii p2)
         { return p1.S > p2.S; });

    Hungarian<ll> g(2 * n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g(i, j) = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (p[i].S > p[j].S)
            {
                ll d = round(sqrtl((p[i].F - p[j].F) * (p[i].F - p[j].F) + (p[i].S - p[j].S) * (p[i].S - p[j].S)) * 1e9);
                g(i << 1, j) = INF - d;
                g(i << 1 | 1, j) = INF - d;
            }

    ll ans = g.run();
    // cerr << ans << '\n';
    if (ans <= (n - 2) * INF)
        cout << -1 << '\n';
    else
        cout << fixed << setprecision(10) << (-ans + INF * (n - 1)) / 1e9 << '\n';
}

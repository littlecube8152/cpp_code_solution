/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
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

int n, a, b, p[200005], dis[200005];

struct segTree
{
    pii seg[800005];
    void modify(int pos, pii val, int i = 1, int L = 1, int R = n)
    {
        if (L == R)
            seg[i] = val;
        else
        {
            int mid = (L + R) / 2;
            if (pos <= mid)
                modify(pos, val, i << 1, L, mid);
            else
                modify(pos, val, i << 1 | 1, mid + 1, R);
            seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
        }
    }
    pii query(int qL, int qR, int i = 1, int L = 1, int R = n)
    {
        if (qL <= L && R <= qR)
            return seg[i];
        else if (R < qL || qR < L)
            return pii(-1e9, 0);
        else
        {
            int mid = (L + R) / 2;
            return max(query(qL, qR, i << 1, L, mid),
                       query(qL, qR, i << 1 | 1, mid + 1, R));
        }
    }
    void clear()
    {
        for (int i = 1; i <= 4 * n; i++)
            seg[i] = pii(-1e9, 0);
    }
    void debug(int i = 1, int L = 1, int R = n)
    {
        cout << i << ' ' << L << ' ' << R << ' ' << seg[i].F << ' ' << seg[i].S << '\n';
        if (L != R)
        {
            int mid = (L + R) / 2;

            debug(i << 1, L, mid);
            debug(i << 1 | 1, mid + 1, R);
        }
    }
} seg[2];

void remove(int i)
{
    seg[0].modify(i, pii(-1e9, 0));
    seg[1].modify(i, pii(-1e9, 0));
}

void solve()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
        dis[i] = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        seg[0].modify(i, pii(p[i] + i, i));
        seg[1].modify(i, pii(p[i] - i, i));
    }
    dis[a] = 0;
    queue<int> q;
    q.push(a);
    remove(a);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        if (i == b)
            break;
        pii res;
        do
        {
            res = seg[0].query(max(0, i - p[i]), max(0, i - 1));
            if (res.F >= i)
            {
                dis[res.S] = dis[i] + 1;
                q.push(res.S);
                remove(res.S);
            }
            else
                break;
        } while (1);

        do
        {
            res = seg[1].query(min(n + 1, i + 1), min(n + 1, i + p[i]));
            if (res.F >= -i)
            {
                dis[res.S] = dis[i] + 1;
                q.push(res.S);
                remove(res.S);
            }
            else
                break;
        } while (1);
    }
    cout << dis[b] << '\n';
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}

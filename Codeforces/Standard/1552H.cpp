#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int C = 200;

int L, R, U, D;

int ask_grid(int p, vector<int> r, vector<int> c)
{
    vector<pii> v;
    for (int i = 1; i <= C; i++)
        for (int j = 1; j <= C; j++)
            if (find(r.begin(), r.end(), i % p) != r.end() || find(c.begin(), c.end(), j % p) != c.end())
                v.emplace_back(i, j);
    int k = v.size();
    cout << "? " << k << '\n';
    for (int i = 0; i < k; i++)
        cout << v[i].F << ' ' << v[i].S << " \n"[i == k - 1];
    cout << flush;
    int res = 0;
    // for (auto [x, y] : v)
    //     if (L <= x && x <= R && U <= y && y <= D)
    //         res++;
    // cerr << res << endl;
    cin >> res;
    return res;
}

/*
the thing is, since lcm(1*1, 2*2, ..., 7*7) > 200 * 200
therefore at least one of them (call it k) is not a factor of the area A
let the two sides be x, y
we can obtain the information of (floor/ceil)(x/k) * y, and what it is (the floor or ceil)
there are only

let a = x/k (floor), if every of 1, 3, 5, 7 misses then
let the query answer be q and Q (q < Q), we know that (k-1)q + Q = A, so Q is solved.

assume k | x,
if we mark m both side, it is equivlant to a rectangle of xm/k times y marked.
therefore if we sought to recover them, the actual should be
query - Am / k +

ask 0123456
ask 0
ask 0 2 4 6 (if none, then the answer is the rest - some 0)
ask 0   4   (if none, then the answer is the rest - some 0)
(if yes, the answer is the current - 0)

*/

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    fast;
    // cin >> L >> R >> U >> D;

    int A = ask_grid(1, {0}, {});
    int k = 8;
    for (auto p : {2, 3, 5, 7})
        if (A % (p * p) != 0)
            k = p;
    assert(k <= 7);

    int x, y;
    if (A % k == 0) // both side
    {
        vector<int> even, quad;
        for (int i = 0; i < k; i += 2)
            even.emplace_back(i);
        for (int i = 0; i < k; i += 4)
            quad.emplace_back(i);

        int E = even.size(), Q = quad.size();
        int zero = (ask_grid(k, {0}, {0}) - A * 1 / k) * k / (k - 1),
            one = 0,
            two = (ask_grid(k, even, even) - A * E / k) * k / (k - E),
            four = (ask_grid(k, quad, quad) - A * Q / k) * k / (k - Q);

        if (two == zero * E)
            one = A - (k - 1) * zero;
        else if (four == zero * Q)
            one = two - (E - 1) * zero;
        else
            one = four - zero;

        y = abs(zero - one);
    }
    else // single side
    {
        vector<int> even, quad;
        for (int i = 0; i < k; i += 2)
            even.emplace_back(i);
        for (int i = 0; i < k; i += 4)
            quad.emplace_back(i);
        int zero = ask_grid(k, {0}, {}), one = 0, two = ask_grid(k, even, {}), four = ask_grid(k, quad, {});

        int E = even.size(), Q = quad.size();
        if (two == zero * E)
            one = A - (k - 1) * zero;
        else if (four == zero * Q)
            one = two - (E - 1) * zero;
        else
            one = four - zero;

        y = abs(zero - one);
    }
    x = A / y;
    cerr << k << ' ' << x << ' ' << y << '\n';
    cerr << "result: " << 2 * (x + y) - 4 << " answer: " << 2 * (R - L + D - U) << '\n';
    cout << "! " << 2 * (x + y) - 4 << endl;
}

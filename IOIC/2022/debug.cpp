//#define _GLIBCXX_DEBUG
// Knapsack DP is harder than FFT.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define ff first
#define ss second
#define pb emplace_back
#define AI(x) begin(x), end(x)
template <class I>
bool chmax(I &a, I b)
{
    return a < b ? (a = b, true) : false;
}
template <class I>
bool chmin(I &a, I b) { return b < a ? (a = b, true) : false; }
#ifdef OWO
#define debug(args...) SDF(#args, args)
#define OIU(args...) ostream &operator<<(ostream &O, args)
#define LKJ(S, B, E, F)                  \
    template <class... T>                \
    OIU(S<T...> s)                       \
    {                                    \
        O << B;                          \
        int c = 0;                       \
        for (auto i : s)                 \
            O << (c++ ? ", " : "") << F; \
        return O << E;                   \
    }
LKJ(vector, '[', ']', i)
LKJ(deque, '[', ']', i) LKJ(set, '{', '}', i) LKJ(multiset, '{', '}', i) LKJ(unordered_set, '{', '}', i) LKJ(map, '{', '}', i.ff << ':' << i.ss) LKJ(unordered_map, '{', '}', i.ff << ':' << i.ss) template <class... T>
void SDF(const char *s, T... a)
{
    int c = sizeof...(T);
    if (!c)
    {
        cerr << "\033[1;32mvoid\033[0m\n";
        return;
    }
    (cerr << "\033[1;32m(" << s << ") = (", ..., (cerr << a << (--c ? ", " : ")\033[0m\n")));
}
template <class T, size_t N>
OIU(array<T, N> a) { return O << vector<T>(AI(a)); }
template <class... T>
OIU(pair<T...> p) { return O << '(' << p.ff << ',' << p.ss << ')'; }
template <class... T>
OIU(tuple<T...> t)
{
    return O << '(', apply([&O](T... s)
                           {
                               int c = 0;
                               (..., (O << (c++ ? ", " : "") << s));
                           },
                           t),
           O << ')';
}
#else
#pragma GCC optimize("Ofast")
#define debug(...) ((void)0)
#endif

struct vec
{
    ll x, y;
    vec(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    vec operator+(vec &oth) { return vec(x + oth.x, y + oth.y); }
    vec operator-(vec &oth) { return vec(x - oth.x, y - oth.y); }
};
ll dot(vec a, vec b) { return a.x * b.x + a.y * b.y; }
ll cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
ll abs2(vec a) { return dot(a, a); }
double abs(vec a) { return sqrt(dot(a, a)); }
int sign(ll a) { return (a > 0) - (a < 0); }
int ori(vec a, vec b, vec c) { return sign(cross(b - a, c - a)); }
bool contribute(vec a, vec b, vec c) { return cross(a - c, b - c) == 0; }
bool btw(vec a, vec b, vec c) { return cross(a - c, b - c) == 0 and dot(a - c, b - c) <= 0; }
istream &operator>>(istream &I, vec &a) { return I >> a.x >> a.y; }
ostream &operator<<(ostream &O, vec &a) { return O << '(' << a.x << ',' << a.y << ')'; }
typedef array<vec, 2> seg;
bool flip(vec &a)
{
    if (a.y > 0 or (a.y == 0 and a.x > 0))
        return false;
    a.x = -a.x;
    a.y = -a.y;
    return true;
}
bool cmp(vec a, vec b)
{
    return cross(a, b) > 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<seg> segs(N);
    for (auto &[p1, p2] : segs)
        cin >> p1 >> p2;

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        for (vec o : segs[i])
        {
            int cnt = 0;
            vector<seg> tmp;
            vector<int> isFlipped;
            for (int j = 0; j < N; ++j)
            {
                if (btw(segs[j][0], segs[j][1], o))
                {
                    ++cnt;
                    continue;
                }
                tmp.push_back({segs[j][0] - o, segs[j][1] - o});
                isFlipped.push_back(0);
                for (vec &v : tmp.back())
                    isFlipped.back() ^= flip(v);
            }
            int n = tmp.size();

            debug(tmp);

            vector<int> id(n * 2);
            iota(AI(id), 0);
            sort(AI(id), [&](int u, int v)
                 { return cmp(tmp[u >> 1][u & 1], tmp[v >> 1][v & 1]); });
            vector<array<int, 2>> pos(n);
            int k = 0;
            for (int j = 0; j < n * 2; ++j)
            {
                pos[id[j] >> 1][id[j] & 1] = k;
                if (j < n * 2 - 1 and cmp(tmp[id[j] >> 1][id[j] & 1], tmp[id[j + 1] >> 1][id[j + 1] & 1]))
                    ++k;
            }
            //debug(pos);
            //debug(isFlipped);

            vector<int> pre(k + 2, 0);
            for (int j = 0; j < n; ++j)
            {
                if (pos[j][0] > pos[j][1])
                    swap(pos[j][0], pos[j][1]);
                if (isFlipped[j])
                {
                    ++pre[pos[j][1]];
                    ++pre[0];
                    --pre[pos[j][0] + 1];
                }
                else
                {
                    ++pre[pos[j][0]];
                    --pre[pos[j][1] + 1];
                }
            }

            int mx = 0;
            for (int j = 0; j < k; ++j)
            {
                mx = max(mx, pre[j]);
                pre[j + 1] += pre[j];
            }

            //debug(pre);
            ans = max(ans, mx + cnt);
        }
    }

    cout << ans << '\n';

    return 0;
}

/*
4
100000000 100000000 -300000000 400000000
700000000 -500000000 700000000 100000000
-300000000 600000000 900000000 -800000000
200000000 300000000 -200000000 400000000
*/
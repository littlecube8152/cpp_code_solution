#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

// dp[i][U/D/R/L]: walk to i and last operation is U/D/R/L
// 1
//   2  : RD or DR
// dp[i][j] = dp[i - 1][j'] + (j' != j) or so
// merge dp: dp[l][r][i][j] => segment [l, r] starts with i ends with j

struct node
{
    int dp[4][4];
    int calc()
    {
        int res = 1e9;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                res = min(res, dp[i][j]);
        return res;
    }
} seg[400005], res;

node merge(node L, node R)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            res.dp[i][j] = 1e9;
    for (int i = 0; i < 4; i++)
        for (int k = 0; k < 4; k++)
        {
            int lm = 1e9, rm = 1e9;
            for (int j = 0; j < 4; j++)
            {
                lm = min(lm, L.dp[i][j]);
                rm = min(rm, R.dp[j][k]);
                res.dp[i][k] = min(res.dp[i][k], L.dp[i][j] + R.dp[j][k]);
            }
            res.dp[i][k] = min(res.dp[i][k], lm + rm + 1);
        }
    return res;
}

int N, x[100005], y[100005], pos[400005];
int tmx = 1000'0000;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

double chance(double delta, int t)
{
    return rd() % 1'000'000 <= exp(delta * t / tmx) * 1'000'000;
}

node convert(int x1, int y1, int x2, int y2)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            res.dp[i][j] = 1e9;
#define L 0
#define R 1
#define U 2
#define D 3
    if (x1 > x2 && y1 > y2)
        res.dp[L][D] = res.dp[D][L] = 1;
    else if (x1 > x2 && y1 < y2)
        res.dp[L][U] = res.dp[U][L] = 1;
    else if (x1 < x2 && y1 > y2)
        res.dp[R][D] = res.dp[D][R] = 1;
    else if (x1 < x2 && y1 < y2)
        res.dp[R][U] = res.dp[U][R] = 1;
    return res;
#undef L
#undef R
#undef U
#undef D
}

void build(int i = 1, int L = 1, int R = N)
{
    if (L == R)
        pos[L] = i;
    else
    {
        int mid = (L + R) / 2;
        build(i << 1, L, mid);
        build(i << 1 | 1, mid + 1, R);
    }
}

void modify(int i, node &res)
{
    seg[i] = res;
    while (i /= 2)
        seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
}

vector<int> order;

void update(int i)
{
    // cerr << "update " << i << '\n';
    if (i < 1 || i > N)
        return;
    int l = order[i - 1], r = order[i];
    node res = convert(x[l], y[l], x[r], y[r]);
    modify(pos[i], res);
}

pii nxt(int x1, int y1, int x2, int y2, char mov)
{
    if (mov == 'L' || mov == 'R')
        return pii(x2, y1);
    else
        return pii(x1, y2);
}

string sol[100005], ops = "LRUD";

void construct(int l, int r, int i = 1, int L = 1, int R = N)
{
    // cerr << ops[l] << ' ' << L << ' ' << R << ' ' << ops[r] << '\n';
    if (L == R)
    {
        assert(seg[i].dp[l][r] <= 1);
        sol[L].push_back(ops[l]), sol[L].push_back(ops[r]);
    }
    else
    {
        int mid = (L + R) / 2;
        int opl = 0, opr = 0, opm = 0;
        for (int k = 0; k < 4; k++)
        {
            if (seg[i << 1].dp[l][k] < seg[i << 1].dp[l][opl])
                opl = k;
            if (seg[i << 1 | 1].dp[k][r] < seg[i << 1 | 1].dp[opr][r])
                opr = k;
            if (seg[i << 1].dp[l][k] + seg[i << 1 | 1].dp[k][r] <
                seg[i << 1].dp[l][opm] + seg[i << 1 | 1].dp[opm][r])
                opm = k;
        }
        if (seg[i].dp[l][r] == seg[i << 1].dp[l][opm] + seg[i << 1 | 1].dp[opm][r])
        {
            construct(l, opm, i << 1, L, mid);
            construct(opm, r, i << 1 | 1, mid + 1, R);
        }
        else
        {
            construct(l, opl, i << 1, L, mid);
            construct(opr, r, i << 1 | 1, mid + 1, R);
        }
    }
}

int type(int x, int y)
{
    x -= 5e8, y -= 5e8;
    if (abs(x - y) <= 5e7)
        return 1;
    if (abs(x + y) <= 5e7)
        return 2;
    if (abs(x) <= 5e7)
        return 3;
    return 4;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    build();
    order.emplace_back(0);
    for (int i = 1; i <= N; i++)
    {
        order.emplace_back(i);
        cin >> x[i] >> y[i];
    }

    // general case:
    // shuffle(order.begin() + 1, order.end(), rd);
    // diagonal case:
    sort(order.begin() + 1, order.end(), [&](int i, int j)
         { return make_tuple(type(x[i], y[i]), 2 * y[i] + x[i]) < make_tuple(type(x[j], y[j]), 2 * y[j] + x[j]); });
    for (int i = 1; i <= N; i++)
        update(i);

    int ans = seg[1].calc();

    for (int t = tmx; t >= 0; t--)
    {
        int l = rd() % N + 1, r = l + (rd() % 20 - 10);
        while (r <= 0 || N < r)
            l = rd() % N + 1, r = l + (rd() % 20 - 10);
        swap(order[l], order[r]);
        update(l);
        update(l + 1);
        update(r);
        update(r + 1);
        if (seg[1].calc() > ans + sqrt(N) * pow(double(t / tmx), 2)) //
        {
            swap(order[l], order[r]);
            update(l + 1);
            update(l);
            update(r + 1);
            update(r);
        }
        ans = seg[1].calc();
        if (t % 1'000'000 == 0)
            cerr << ans << '\n';
    }
    int opi = 0, opj = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (seg[1].dp[i][j] < seg[1].dp[opi][opj])
                opi = i, opj = j;
    construct(opi, opj);
    vector<pii> output;
    for (int i = 0; i <= N; i++)
    {
        // if (i > 0)
        //     cerr << sol[i];
        // cerr << "(" << x[order[i]] << ", " << y[order[i]] << ") ";
        if (i > 0)
            output.emplace_back(nxt(x[order[i - 1]], y[order[i - 1]], x[order[i]], y[order[i]], sol[i][0]));
        if (i == 0 || i == N || sol[i][1] != sol[i + 1][0])
            output.emplace_back(pii(x[order[i]], y[order[i]]));
    }
    // cerr << '\n';
    cerr << output.size() << '\n';
    cout << output.size() << '\n';
    for (auto [x, y] : output)
        cout << x << ' ' << y << '\n';
}
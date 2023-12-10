#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int h, w, n, k;
ll ans;
vector<int> row[3005], col[3005], iter[3005];
int f[7005], b[7005], bb[7005], last, jump[7005];
pii r[7005];

int node(int x)
{
    ++last;
    f[last] = last - 1;
    b[last] = last + 1;
    r[last] = pii(0, x);
    jump[last] = last;
    return last;
}

ll decrement(int x)
{
    ll o = r[jump[x]].S;
    do
    {
        jump[x] = f[jump[x]];
    } while (r[jump[x]].F != 0);
    return (o - r[jump[x]].S) * (r[x].S - r[x].F + 1);
}

int remove(int x)
{
    int p = f[x], q = b[x];
    b[p] = q, f[q] = p;
    return q;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> h >> w >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        row[x].emplace_back(y);
    }
    for (int d = 1; d <= h; d++)
    {
        for (int y : row[d])
            col[y].emplace_back(d);

        last = 0;
        for (int i = 1; i <= 20; i++)
            node(0);

        for (int i = 1; i <= d; i++)
            iter[i].clear();

        ll sum = 0;
        for (int i = 1; i <= w; i++)
        {
            for (int j : col[i])
                iter[j].emplace_back(node(i));

            if (r[last].F != 0)
                r[last].S = i;
            else
            {
                node(i);
                r[last].F = i;
                for (int j = 1; j <= k; j++)
                    decrement(last);
            }
            sum += i - r[jump[last]].S;
        }
        node(0);

        int imp = last + 1;
        for (int i = last; i >= 1; i--)
        {
            bb[i] = imp;
            if (r[i].F)
                imp = i;
        }

        for (int u = 1; u <= d; u++)
        {
            // cerr << u - 1 << ' ' << d << ' ' << sum << '\n';
            ans += sum;
            for (int i : iter[u])
            {
                int j = bb[i];
                while (j <= last)
                {
                    assert(r[j].F);
                    if (jump[j] <= i)
                        sum += decrement(j);
                    else
                        break;
                    j = bb[j];
                }

                i = remove(i);
                if (r[f[i]].F && r[i].F)
                {
                    bb[f[i]] = bb[i];
                    r[f[i]].S = r[i].S;
                    remove(i);
                }
            }
        }
    }
    cout << (ll)h * (h + 1) / 2 * w * (w + 1) / 2 - ans << '\n';
}
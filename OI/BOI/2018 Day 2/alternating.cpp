#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, ans[100005], a[100005], b[100005];
vector<int> E[100005];

struct segTree
{
    int seg[400005], lazy[400005];

    int getval(int i)
    {
        return seg[i] + lazy[i];
    }

    void push(int i)
    {
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
        seg[i] += lazy[i];
        lazy[i] = 0;
    }

    void pull(int i)
    {
        seg[i] = min(getval(i << 1), getval(i << 1 | 1));
    }

    void modify(int mL, int mR, int val, int i = 1, int L = 1, int R = N)
    {
        if (mL <= L && R <= mR)
            lazy[i] += val;
        else if (R < mL || mR < L)
            return;
        else
        {
            int mid = (L + R) / 2;
            push(i);
            modify(mL, mR, val, i << 1, L, mid);
            modify(mL, mR, val, i << 1 | 1, mid + 1, R);
            pull(i);
        }
    }

    int query(int qL, int qR, int i = 1, int L = 1, int R = N)
    {
        if (qL <= L && R <= qR)
            return getval(i);
        else if (R < qL || qR < L)
            return 1e9;
        else
        {
            int mid = (L + R) / 2;
            push(i);
            return min(query(qL, qR, i << 1, L, mid), query(qL, qR, i << 1 | 1, mid + 1, R));
        }
    }
} seg;

bool dfs(int u)
{
    bool r = 1;
    for (int v : E[u])
        if (ans[v] == 0)
        {
            ans[v] = ans[u] ^ 3;
            r &= dfs(v);
        }
        else
            r &= (ans[u] ^ ans[v]) == 3;
    return r;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    set<int> sweep;
    vector<pii> event;
    for (int i = 1; i <= M; i++)
    {
        cin >> a[i] >> b[i];
        if (b[i] < a[i])
        {
            sweep.insert(i);
            event.emplace_back(pii(b[i] + 1, -i));
            event.emplace_back(pii(a[i], i));
        }
        else
        {
            event.emplace_back(pii(a[i], i));
            event.emplace_back(pii(b[i] + 1, -i));
        }
    }
    sort(event.begin(), event.end());
    for (int i = 1, j = 0; i <= N; i++)
    {
        while (j < event.size() && event[j].F == i)
        {
            auto [t, k] = event[j];
            if (k > 0)
                sweep.insert(k);
            else
                sweep.erase(-k);
            j++;
        }
        if (sweep.size() <= 1)
        {
            cout << "impossible\n";
            return 0;
        }
        else if (sweep.size() == 2)
        {
            int u = *sweep.begin(), v = *next(sweep.begin());
            E[u].emplace_back(v);
            E[v].emplace_back(u);
        }
    }
    for (int i = 1; i <= M; i++)
        if (ans[i] == 0 && !E[i].empty())
        {
            ans[i] = 1;
            if (!dfs(i))
            {
                cout << "impossible\n";
                return 0;
            }
        }
    for (int i = 1; i <= M; i++)
    {
        if (ans[i] <= 1)
        {
            if (b[i] < a[i])
            {
                seg.modify(a[i], N, 1);
                seg.modify(1, b[i], 1);
            }
            else
                seg.modify(a[i], b[i], 1);
        }
    }
    for (int i = 1; i <= M; i++)
        if (ans[i] == 0)
        {
            int rem = 0;
            if (b[i] < a[i])
                rem = min(seg.query(a[i], N), seg.query(1, b[i]));
            else
                rem = seg.query(a[i], b[i]);

            assert(rem > 0);
            if (rem >= 2)
            {
                ans[i] = 2;
                if (b[i] < a[i])
                {
                    seg.modify(a[i], N, -1);
                    seg.modify(1, b[i], -1);
                }
                else
                    seg.modify(a[i], b[i], -1);
            }
            else
                ans[i] = 1;
        }
    for (int i = 1; i <= M; i++)
        cout << ans[i] - 1;
    cout << '\n';
}
/*
5 6
1 3
2 4
3 5
4 1
5 2
1 3
*/
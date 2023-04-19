#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int N, Q;
vector<int> cur;
int seg[800005];
vector<int> range[800005];

void init()
{
    for (int i = 0; i <= 4 * N; i++)
        seg[i] = N + 1;
}
void modify(int pos, int val, int i = 1, int L = 1, int R = N)
{
    if (L == R)
        seg[i] = min(seg[i], val);
    else
    {
        int mid = (L + R) / 2;
        if (pos <= mid)
            modify(pos, val, i << 1, L, mid);
        else
            modify(pos, val, i << 1 | 1, mid + 1, R);
        seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
    }
}
int query(int qL, int qR, int i = 1, int L = 1, int R = N)
{
    if (qL <= L && R <= qR)
        return seg[i];
    else if (R < qL || qR < L)
        return N + 1;
    else
    {
        int mid = (L + R) / 2;
        return min(query(qL, qR, i << 1, L, mid), query(qL, qR, i << 1 | 1, mid + 1, R));
    }
}
void get(int pos, int i = 1, int L = 1, int R = N)
{
    while (!range[i].empty())
    {
        cur.emplace_back(range[i].back());
        range[i].pop_back();
    }
    if (L == R)
        return;
    int mid = (L + R) / 2;
    if (pos <= mid)
        get(pos, i << 1, L, mid);
    else
        get(pos, i << 1 | 1, mid + 1, R);
}
void split(int qL, int qR, int val, int i = 1, int L = 1, int R = N)
{
    if (qL <= L && R <= qR)
        range[i].emplace_back(val);
    else if (R < qL || qR < L)
        return;
    else
    {
        int mid = (L + R) / 2;
        split(qL, qR, val, i << 1, L, mid);
        split(qL, qR, val, i << 1 | 1, mid + 1, R);
    }
}

int L[200005], R[200005], A[200005], B[200005], ans[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> L[i] >> R[i];
    init();
    modify(1, 0);
    for (int i = 2; i <= N; i++)
    {
        A[i] = 1 + query(L[i], i);
        modify(i, A[i]);
    }
    init();
    modify(N, 0);
    for (int i = N - 1; i >= 1; i--)
    {
        B[i] = 1 + query(i, R[i]);
        modify(i, B[i]);
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    init();
    for (int i = 1; i <= N; i++)
        modify(i, A[i]);
    for (int i = 1; i <= N; i++)
        ans[i] += 1 + query(L[i], R[i]);
    init();
    for (int i = 1; i <= N; i++)
        modify(i, B[i]);
    for (int i = 1; i <= N; i++)
        ans[i] += query(L[i], R[i]);
   
    for (int i = 1; i <= N; i++)
    {
        ans[i] = min(ans[i], A[i] + B[i]);
        pq.push(pii(ans[i], i));
        split(L[i], R[i], i);
    }
    while (!pq.empty())
    {
        auto [d, i] = pq.top();
        pq.pop();
        if (d > ans[i])
            continue;
        cur.clear();
        get(i);
        for (int j : cur)
            if (ans[j] > ans[i] + 1)
            {
                ans[j] = ans[i] + 1;
                pq.push(pii(ans[j], j));
            }
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int q;
        cin >> q;
        cout << (ans[q] > N ? -1 : ans[q]) << '\n';
    }
}
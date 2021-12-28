#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, K, C, arr[505][7], idx = 0, sel[20005][7], ans[20005];
signed char frac[20005][505];
priority_queue<pii> pq;

void compute(int i)
{
    ans[i] = 0;
    for (int j = 1; j <= N; j++)
        if (frac[i][j] > 0)
            sel[i][frac[i][j]] = j;
    for (int j = 1; j <= K; j++)
        if (!sel[i][j])
        {
            for (int k = 1; k <= N; k++)
                if (frac[i][k] == 0 && arr[k][j] >= arr[sel[i][j]][j])
                    sel[i][j] = k;
            frac[i][sel[i][j]] = -10;
        }
    for (int j = 1; j <= K; j++)
        if (frac[i][sel[i][j]] < -1)
            frac[i][sel[i][j]] = 0;
    for (int j = 1; j <= K; j++)
    {
        int cur = 0;
        for (int k = 1; k <= K; k++)
            cur = max(cur, arr[sel[i][k]][j]);
        ans[i] += cur;
    }
    for (int k = 1; k <= K; k++)
        if (sel[i][k] == 0)
            ans[i] = -1e9;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K >> C;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++)
            cin >> arr[i][j];
    compute(0);
    pq.push(pii{ans[0], 0});
    for (int i = 1; i <= C; i++)
    {
        pii top = pq.top();
        pq.pop();
        //for (int j = 1; j <= N; j++)
        //    cout << (int)frac[top.S][j] << " ";
        //cout << " | ";
        int j = 1;
        for (int k = 1; k <= N; k++)
            j = max(j, frac[top.S][k] + 1);
        for (; j <= K; j++)
        {
            idx++;
            for (int k = 1; k <= N; k++)
                frac[idx][k] = frac[top.S][k];
            for (int k = 1; k < j; k++)
                frac[idx][sel[top.S][k]] = k;
            frac[idx][sel[top.S][j]] = -1;
            compute(idx);
            pq.push(pii{ans[idx], idx});
        }
        if (i == C)
            cout << top.F << '\n';
    }
}

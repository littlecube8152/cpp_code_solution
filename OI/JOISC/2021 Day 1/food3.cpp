#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M, Q, seg[300005];
deque<int> dq[65005];

void modify(int mL, int mR, int K, int i = 1, int L = 1, int R = N)
{
    if (R < mL || mR < L)
        return;
    if (L == R)
    {
        while (!dq[L].empty() && K--)
            dq[L].pop_front();
        seg[i] = !dq[L].empty();
    }
    else if (seg[i])
    {
        int mid = (L + R) / 2;
        modify(mL, mR, K, i * 2, L, mid);
        modify(mL, mR, K, i * 2 + 1, mid + 1, R);
        seg[i] = seg[i * 2] | seg[i * 2 + 1];
    }
}

void insert(int pos, int C, int i = 1, int L = 1, int R = N)
{
    if (L == R)
    {
        dq[L].emplace_back(C);
        seg[i] = !dq[L].empty();
    }
    else
    {
        int mid = (L + R) / 2;
        if (pos <= mid)
            insert(pos, C, i * 2, L, mid);
        else
            insert(pos, C, i * 2 + 1, mid + 1, R);
        seg[i] = seg[i * 2] | seg[i * 2 + 1];
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> Q;
    for (int i = 1; i <= Q; i++)
    {
        ll T, L, R, C, K;
        cin >> T >> L >> R;
        if (T == 1)
        {
            cin >> C >> K;
            for (int j = L; j <= R; j++)
                insert(j, C);
        }
        else if (T == 2)
        {
            cin >> K;
            modify(L, R, K);
        }
        else if (T == 3)
            cout << (dq[L].size() >= R ? dq[L][R - 1] : 0) << '\n';
        
    }
}
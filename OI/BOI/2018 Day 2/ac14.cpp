#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M;
vector<pair<int, pii>> v;
int side[100005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        v.emplace_back(make_pair(i, pii{a, b}));
    }
    if (N <= 15)
    {
        for (int mask = 0; mask < (1 << M); mask++)
        {
            bool valid[2] = {1, 1};
            for (int i = 1; i <= N; i++)
            {
                bool exist[2] = {0, 0};
                for (int j = 0; j < M; j++)
                {
                    pii p = v[j].S;
                    if ((p.F <= p.S && p.F <= i && i <= p.S) || (p.F > p.S && !(p.S < i && i < p.F)))
                        exist[(mask >> j) & 1] = 1;
                }
                valid[0] &= exist[0];
                valid[1] &= exist[1];
            }
            if (valid[0] && valid[1])
            {
                for (int j = 0; j < M; j++)
                    cout << ((mask >> j) & 1);
                cout << '\n';
                return 0;
            }
        }
        cout << "impossible\n";
    }
    else
    {
        int top[3] = {}, idx[3] = {};
        priority_queue<pii> pq[3];
        sort(v.begin(), v.end(), [](pair<int, pii> p1, pair<int, pii> p2)
             { return p1.S.F < p2.S.F; });
        while(top[1] < N || top[2] < N)
        {
            int cur = (top[1] <= top[2] ? 1 : 2);
            while(idx[cur] < M && v[idx[cur]].S.F <= top[cur] + 1)
            {
                pq[cur].push(make_pair(v[idx[cur]].S.S, v[idx[cur]].F));
                idx[cur]++;
            }
            while(!pq[cur].empty() && side[pq[cur].top().S] != 0)
                pq[cur].pop();
            if(pq[cur].empty() || pq[cur].top().F <= top[cur])
            {
                cout << "impossible\n";
                return 0;
            }
            else
            {
                top[cur] = pq[cur].top().F;
                //cout << cur << "use " << pq[cur].top().S << '\n';
                side[pq[cur].top().S] = cur;
                pq[cur].pop();
            }
        }
        for (int i = 1; i <= M; i++)
            cout << side[i] % 2;
        cout << '\n';
    }
}


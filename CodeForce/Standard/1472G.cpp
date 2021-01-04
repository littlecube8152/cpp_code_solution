#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

bool comp(pii p1, pii p2)
{
    return p1.second > p2.second;
}

vector<int> to[200005], from[200005];
int dis[200005] = {0}, res[200005], color[200005] = {0};
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n, m;
        vector<pii> update;
        queue<int> q;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            to[i] = {};
            from[i] = {};
            update = {};
            color[i] = 0;
            res[i] = 400000;
        }

        while (m--)
        {
            int a, b;
            cin >> a >> b;
            to[a].emplace_back(b);
            from[b].emplace_back(a);
        }
        q.push(1);
        color[1] = 1;
        dis[1] = 0;
        while (!q.empty())
        {
            color[q.front()] = 2;
            for (auto i : to[q.front()])
            {
                if (color[i] == 0)
                {
                    q.push(i);
                    color[i] = 1;
                    dis[i] = dis[q.front()] + 1;
                }
            }
            q.pop();
        }
        for (int i = 1; i <= n; i++)
            update.emplace_back(make_pair(i, dis[i]));

        sort(update.begin(), update.end(), comp);

        for (int i = 0; i < update.size(); i++)
            cout << update[i].first << " " << dis[update[i].first] << "  ";
        for (int i = 0; i < update.size(); i++)
        {
            res[update[i].first] = min(res[update[i].first], dis[update[i].first]);
            for (auto j : from[update[i].first])
            {
                if (dis[j] <= dis[update[i].first])
                    res[j] = min(res[j], res[update[i].first]);
                else
                    res[j] = min(res[j], dis[update[i].first]);
            }
        }
        for (int i = 1; i <= n; i++)
            cout << res[i] << " \n"[i == n];
    }
}
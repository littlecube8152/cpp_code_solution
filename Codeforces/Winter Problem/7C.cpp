#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, x, disa[200005] = {0}, disb[200005] = {0}, color[200005] = {0}, r = 0;
vector<int> path[200005];
queue<int> q;

int main()
{
    fast;

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        path[a].emplace_back(b);
        path[b].emplace_back(a);
    }
    q.push(1);
    color[1] = 1;
    while (!q.empty())
    {
        color[q.front()] = 2;
        for (auto i : path[q.front()])
        {
            if (color[i] == 0)
            {
                q.push(i);
                disa[i] = disa[q.front()] + 1;
                color[i] = 1;
                //cout << "FROM " << q.front() << "TO " << i << '\n';
            }
        }
        q.pop();
    }
    q.push(x);
    color[q.front()] = 3;
    while (!q.empty())
    {
        color[q.front()] = 4;
        if (disa[q.front()] > disb[q.front()])
        {

            for (auto i : path[q.front()])
            {
                if (disb[q.front()] + 1 <= disa[i] && color[i] == 2)
                {
                    q.push(i);
                    disb[i] = disb[q.front()] + 1;
                    color[i] = 3;
                    // cout << "FROM " << q.front() << "TO " << i << '\n';
                }
            }
        }
        q.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        //cout << disb[i] << " ";
        if (disb[i] <= disa[i] && color[i] == 4)
            r = max(r, disa[i]);
    }
    cout << r * 2;
    return 0;
}
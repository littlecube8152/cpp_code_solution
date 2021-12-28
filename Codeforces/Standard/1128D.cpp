//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<int> v[100005], leaf;
set<int> s;
queue<int> q;
int n, p[100005], dis[100005], vis[100005], im[100005], t[100005];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if (v[i].size() == 1)
            leaf.emplace_back(i);
    for (int i : leaf)
    {
        vis[i] = 1;
        q.push(i);
    }
    while (!q.empty())
    {
        for (int i : v[q.front()])
        {
            if (vis[i] == 1 && i != p[q.front()] && im[i] != q.front())
            {
                //cout << q.front() << " to " << i << " But Failed\n";
                s.insert(i);
                im[q.front()] = i;
            }
            else if (vis[i] == 0)
            {
                //cout << q.front() << " to " << i << '\n';
                dis[i] = dis[q.front()] + 1;
                vis[i] = 1;
                p[i] = q.front();
                q.push(i);
            }
        }
        q.pop();
    }
    int maxdis = 0;
    vector<int> maxp;
    for (int i : s)
    {
        if (dis[i] > maxdis)
        {
            maxdis = dis[i];
            maxp.clear();
        }
        if (dis[i] == maxdis)
            maxp.emplace_back(i);
    }

    if (maxp.size() != 1)
    {
        memset(p, 0, sizeof(int) * 100005);
        memset(vis, 0, sizeof(int) * 100005);
        memset(dis, 0, sizeof(int) * 100005);
        memset(im, 0, sizeof(int) * 100005);
        for (int i : t)
        {
            vis[i] = 1;
            q.push(i);
        }
        while (!q.empty())
        {
            for (int i : v[q.front()])
            {
                if (vis[i] == 1 && i != p[q.front()] && im[i] != q.front())
                {
                    //cout << q.front() << " to " << i << " But Failed\n";
                    s.insert(i);
                    im[q.front()] = i;
                }
                else if (vis[i] == 0)
                {
                    //cout << q.front() << " to " << i << '\n';
                    dis[i] = dis[q.front()] + 1;
                    vis[i] = 1;
                    p[i] = q.front();
                    q.push(i);
                }
            }
            q.pop();
        }
        maxdis = 0;
        maxp = {};
        for (int i : t)
        {
            if (dis[i] > maxdis)
            {
                maxdis = dis[i];
                maxp.clear();
            }
            if (dis[i] == maxdis)
                maxp.emplace_back(i);
        }
        if (maxp.size() > 1)
        {
            cout << -1;
            return 0;
        }
    }

    memset(p, 0, sizeof(int) * 100005);
    memset(vis, 0, sizeof(int) * 100005);
    memset(dis, 0, sizeof(int) * 100005);
    memset(im, 0, sizeof(int) * 100005);
    memset(t, 0, sizeof(int) * 100005);

    map<int, int> disdeg;
    q.push(maxp.front());
    vis[maxp.front()] = 1;
    while (!q.empty())
    {
        for (int i : v[q.front()])
            if (vis[i] == 0)
            {
                //cout << q.front() << " to " << i << '\n';
                dis[i] = dis[q.front()] + 1;
                vis[i] = 1;
                p[i] = q.front();
                q.push(i);
                t[i] = t[q.front()];

                if (!disdeg[dis[i]])
                    disdeg[dis[i]] = v[i].size();
                else if (disdeg[dis[i]] != v[i].size())
                    t[i] = 1;
            }
        q.pop();
    }
    int distance = 0, index = 0, counter = 0, allequal = 0;
    for (int i : leaf)
        if (distance == 0)
            distance = dis[i];
        else if (distance != dis[i])
        {
            allequal++;
            index = i;
        }

    if (!allequal)
    {
        for (int i : leaf)
            if (t[i])
                counter++;

        if (counter == 0)
        {
            cout << maxp.front();
            return 0;
        }
        if (counter == 1)
            for (int i : leaf)
                if (t[i])
                {
                    cout << i;
                    return 0;
                }
        if (counter == leaf.size() - 1)
            for (int i : leaf)
                if (!t[i])
                {
                    cout << i;
                    return 0;
                }
    }
    if (allequal == 1)
    {
        memset(p, 0, sizeof(int) * 100005);
        memset(vis, 0, sizeof(int) * 100005);
        memset(dis, 0, sizeof(int) * 100005);
        memset(im, 0, sizeof(int) * 100005);
        memset(t, 0, sizeof(int) * 100005);

        q.push(index);
        vis[index] = 1;
        disdeg.empty();

        while (!q.empty())
        {
            for (int i : v[q.front()])
                if (vis[i] == 0)
                {
                    //cout << q.front() << " to " << i << '\n';
                    dis[i] = dis[q.front()] + 1;
                    vis[i] = 1;
                    p[i] = q.front();
                    q.push(i);
                    t[i] = t[q.front()];

                    if (!disdeg[dis[i]])
                        disdeg[dis[i]] = v[i].size();
                    else if (disdeg[dis[i]] != v[i].size())
                        t[i] = 1;
                }
            q.pop();
        }

        distance = 0, index = 0, counter = 0, allequal = 0;

        for (int i : leaf)
            if (distance == 0)
                distance = dis[i];
            else if (distance != dis[i] || t[i])
                allequal++;
        if (!allequal)
            cout << index;
    }
}
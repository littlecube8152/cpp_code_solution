#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, ans[1000001], maxv[1000001];
bitset<1000001> pre;
vector<int> e[1000001];

inline void merge(deque<int> &d1, deque<int> &d2, int &maxval, int &maxid)
{
    for (int i = 0; i < d2.size(); i++)
    {
        d1[i] += d2[i];
        if (d2[i] != 0)
            if (d1[i] > maxval)
                maxid = i, maxval = d1[i];
    }
}

inline deque<int> dfs(int n)
{
    vector<deque<int>> v;
    int maxid = 0, maxval = 0;

    int id = -1;
    for (auto i : e[n])
        if (!pre[i])
        {
            pre[i] = 1;
            id = i;
            if(maxv[i] > maxval)
                maxid = ans[i], maxval = maxv[i];
            v.emplace_back(dfs(i));
        }
    if (v.size() == 0)
    {
        maxv[n] = 1;
        return deque<int>{1};
    }
    else if (v.size() == 1)
    {
        v[0].push_front(1);
        if (id < 1 || maxv[id] <= 1)
            maxv[n] = 1;
        else
        {
            maxv[n] = maxv[id];
            ans[n] = ans[id] + 1;
        }
        return v[0];
    }
    else
    {
        sort(v.begin(), v.end(), [](deque<int> &d1, deque<int> &d2) { return d1.size() > d2.size(); });
        for (; v.size() > 1;)
        {
            merge(v[v.size() - 2], v.back(), maxval, maxid);
            v.pop_back();
        }

        v[0].push_front(1);

        maxid++;

        for (int i = 0; i < v[0].size(); i++)
           if (v[0][i] > maxval)
               maxid = i, maxval = v[0][i];

        ans[n] = maxid;
        maxv[n] = maxval;
        return v[0];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    pre[1] = -1;
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}
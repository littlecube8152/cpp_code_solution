#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
int L, N;
gp_hash_table<int, int> d1, d2;
gp_hash_table<int, vector<pair<int, int>>> e;
set<pair<int, int>> st;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> L >> N;
    vector<int> point = {0, L};
    for (int i = 1; i <= N; i++)
    {
        int x, d;
        cin >> x >> d;
        if (x - d >= 0)
        {
            point.push_back(x - d);
            e[x].push_back(make_pair(x - d, 0));
        }
        point.push_back(x);
        if (x + d <= L)
        {
            point.push_back(x + d);
            e[x].push_back(make_pair(x + d, 0));
        }
    }
    sort(point.begin(), point.end());
    point.resize(unique(point.begin(), point.end()) - point.begin());
    for (int i = 1; i < point.size(); i++)
    {
        e[point[i]].push_back(make_pair(point[i - 1], point[i] - point[i - 1]));
        e[point[i - 1]].push_back(make_pair(point[i], point[i] - point[i - 1]));
    }
    for (int i = 0; i < point.size(); i++)
    {
        d1[point[i]] = 100000000000;
        d2[point[i]] = 100000000000;
    }
    st.insert(make_pair(0, 0));
    d1[0] = 0;
    while (!st.empty())
    {
        pair<int, int> p = *st.begin();
        st.erase(st.begin());

        for (auto i : e[p.second])
        {
            if (d1[i.first] > p.first + i.second)
            {
                auto it = st.find(make_pair(d1[i.first], i.first));
                if (it != st.end())
                    st.erase(it);
                d1[i.first] = p.first + i.second;
                st.insert(make_pair(d1[i.first], i.first));
            }
        }
    }

    st.insert(make_pair(0, L));
    d2[L] = 0;
    while (!st.empty())
    {
        pair<int, int> p = *st.begin();
        st.erase(st.begin());
        for (auto i : e[p.second])
        {
            if (d2[i.first] > p.first + i.second)
            {
                auto it = st.find(make_pair(d2[i.first], i.first));
                if (it != st.end())
                    st.erase(it);
                d2[i.first] = p.first + i.second;
                st.insert(make_pair(d2[i.first], i.first));
            }
        }
    }

    int ans = 100000000000;
    for (int i = 0; i < point.size(); i++)
    {
        //cout << point[i] << " " << d1[point[i]] << " " << d2[point[i]] << '\n';
        ans = min(ans, max(d1[point[i]], d2[point[i]]));
    }
    for (int i = 1; i < point.size(); i++)
    {
        int imid = (point[i] + point[i - 1] - d1[point[i - 1]] + d2[point[i]]) / 2;
        for (int mid = imid - 100; mid <= imid + 100; mid++)
            ans = min(ans, max(d1[point[i - 1]] + abs(mid - point[i - 1]), d2[point[i]] + abs(point[i] - mid)));
    }
    for (int i = 1; i < point.size(); i++)
    {
        int imid = (point[i] + point[i - 1] - d2[point[i - 1]] + d1[point[i]]) / 2;
        for (int mid = imid - 100; mid <= imid + 100; mid++)
            ans = min(ans, max(d2[point[i - 1]] + abs(mid - point[i - 1]), d1[point[i]] + abs(point[i] - mid)));
    }
    cout << ans << '\n';
}
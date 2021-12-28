#include <bits/stdc++.h>
using namespace std;
const unsigned long long INF = 4611686018427387904;

unsigned long long n, m, a, b, s;
vector<pair<long long, long long>> e[100001];
unsigned long long dis[100001];
bool fin[100001];
set<pair<long, long>> st;

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> a >> b >> s;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = (i == s ? 0 : INF);
        st.insert(make_pair(dis[i], i));
    }

    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e[x].emplace_back(make_pair(y, a + b * w));
        e[y].emplace_back(make_pair(x, a + b * w));
    }
    while (!st.empty())
    {
        auto top = st.begin()->second;
        st.erase(st.begin());

        if (fin[top])
            continue;
        fin[top] = 1;

        for (auto i : e[top])
            if (!fin[i.first])
                if (dis[top] + i.second < dis[i.first])
                {
                    auto iter = st.find(make_pair(dis[i.first], i.first));
                    if (iter != st.end())
                        st.erase(iter);

                    dis[i.first] = dis[top] + i.second;
                    st.insert(make_pair(dis[i.first], i.first));
                }
    }

    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    cout << '\n';
}
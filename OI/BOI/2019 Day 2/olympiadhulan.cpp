#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, K, C;
multiset<int, greater<int>> st;
vector<int> score[505];
map<int, int> rk[6];

const int mul = 500;
const int least = 200000;
void dfs(int cnt, int i, vector<int> v)
{
    if (st.size() >= max(least, mul * C))
        return;
    if (cnt == K)
    {
        int tot = 0;
        for (int i = 0; i < K; i++)
            tot += v[i];
        st.insert(tot);
        return;
    }
    for (int j = i + 1; j <= N; j++)
    {
        vector<int> u(K, 0);
        for (int i = 0; i < K; i++)
            u[i] = max(v[i], score[j][i]);
        dfs(cnt + 1, j, u);
        if (st.size() >= max(least, mul * C))
            return;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K >> C;
    for (int i = 1; i <= N; i++)
    {
        score[i].resize(K);
        for (int j = 0; j < K; j++)
        {
            cin >> score[i][j];
            rk[j][score[i][j]] = 1;
        }
    }
    for (int i = 0; i < K; i++)
    {
        int counter = 0;
        for (auto &p : rk[i])
            p.S = ++counter;
    }
    random_shuffle(score + 1, score + 1 + N);
    /*stable_sort(score + 1, score + 1 + N, [&](vector<int> v1, vector<int> v2)
                {
                    int rk1 = 1e9, rk2 = 1e9;
                    for (int i = 0; i < K; i++)
                        rk1 = min(rk1, rk[i][v1[i]]);
                    for (int i = 0; i < K; i++)
                        rk2 = min(rk2, rk[i][v2[i]]);
                    return rk1 < rk2;
                });*/
    dfs(0, 0, vector<int>(K, 0));
    auto iter = st.begin();
    for (int i = 2; i <= C; i++)
        iter = next(iter);
    cout << *iter << '\n';
}
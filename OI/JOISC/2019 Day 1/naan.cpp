#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const bool LittleCubeIsBurningChicken = true;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

ll N, L, v[2005][2005], sum[2005];
bool vis[2005];
pll d[2005][2005];

int abtodc(int a, int b, int c)
{
    return (b * c + a - 1) / a;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> L;
    // why divide by N?
    // how to solve using only fractions? -> we can discard leftovers (things cannot be converted to current fraction) from last person
    // is it guarnteed to always have a solution? -> yes (at least for N <= 6)
    // why?
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            cin >> v[i][j];
            // sum >= sum of v / N
            // sum * N >= sum of v
            sum[i] += v[i][j];
            v[i][j] *= N;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        pll last = {0, 1};
        int nxt = 1;
        for (int j = 1; j <= N; j++)
        {
            ll tmp = sum[i];
            while (nxt < L && tmp >= v[i][nxt] - last.F)
                tmp -= v[i][nxt] - last.F, last = {0, 1}, nxt++;
            last = {last.F, v[i][nxt]};
            last.F += tmp;
            d[i][j] = pll(last.F + (nxt - 1) * last.S, last.S);
            
        }
    }
    vector<int> p;
    for (int i = 1; i <= N; i++)
    {
        pll cur = {1e9, 1};
        int nxt = 0;
        for (int j = 1; j <= N; j++)
            if (!vis[j] && (__int128)d[j][i].F * cur.S < (__int128)d[j][i].S * cur.F)
                nxt = j, cur = d[j][i];
        vis[nxt] = 1;
        if (i < N)
            cout << cur.F << ' ' << cur.S << '\n';
        p.emplace_back(nxt);
    }
    for (int i = 0; i < N; i++)
        cout << p[i] << " \n"[i == N - 1];
}
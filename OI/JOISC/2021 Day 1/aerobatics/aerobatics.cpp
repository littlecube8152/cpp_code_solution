#include "aerobatics.h"
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

double GetAngle(pii a, pii b, pii c)
{
    return GetAngle(a.F, a.S, b.F, b.S, c.F, c.S);
}

void solve(ifstream cin, ofstream cout)
{
    int N, Z, ans[2005], best[2005];
    pii p[2005];
    cin >> N >> Z;
    for (int i = 1; i <= N; i++)
        cin >> p[i].F >> p[i].S;
    for (int i = 1; i <= N; i++)
        ans[i] = best[i] = i;
    srand(time(0));
    for (int t = 1; t <= 2000; t++)
    {
        random_shuffle(ans + 1, ans + 1 + N);
        for (int t = 1; t <= 20; t++)
            for (int i = 2; i <= N - 1; i++)
                for (int j = i + 1; j <= N - 1; j++)
                    if (GetAngle(p[ans[i - 1]], p[ans[i]], p[ans[i + 1]]) +
                            GetAngle(p[ans[j - 1]], p[ans[j]], p[ans[j + 1]]) <
                        GetAngle(p[ans[i - 1]], p[ans[j]], p[ans[i + 1]]) +
                            GetAngle(p[ans[j - 1]], p[ans[i]], p[ans[j + 1]]))
                        swap(ans[i], ans[j]);
        double cur = 180, the = 180;
        for (int i = 2; i <= N - 1; i++)
            the = min(the, GetAngle(p[best[i]], p[best[i - 1]], p[best[i + 1]]));
        for (int i = 2; i <= N - 1; i++)
            cur = min(cur, GetAngle(p[ans[i]], p[ans[i - 1]], p[ans[i + 1]]));
        if (cur > the)
        {
            for (int i = 1; i <= N; i++)
                best[i] = ans[i];
            cerr << cur << '\n';
        }
    }

    for (int i = 1; i <= N; i++)
        cout << best[i] << '\n';
}

signed main()
{
    solve(ifstream("input_02.txt"), ofstream("output_02.txt"));
    solve(ifstream("input_03.txt"), ofstream("output_03.txt"));
    // solve(ifstream("input_04.txt"), ofstream("output_04.txt"));
    // solve(ifstream("input_05.txt"), ofstream("output_05.txt"));
    // solve(ifstream("input_06.txt"), ofstream("output_06.txt"));
}
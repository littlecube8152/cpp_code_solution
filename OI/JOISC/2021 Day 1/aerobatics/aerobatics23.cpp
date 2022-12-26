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
    return GetAngle(b.F, b.S, a.F, a.S, c.F, c.S);
}

int N, Z, best[2005], ans[2005];
pii p[16], point[2005];

double calc(int ans[])
{
    double cur = 180;
    for (int i = 2; i <= N - 1; i++)
        cur = min(cur, GetAngle(point[ans[i - 1]], point[ans[i]], point[ans[i + 1]]));
    return cur;
}

void solve(string in, string out)
{
    ifstream cin(in);
    cin >> N >> Z;
    for (int t = 1; t <= 1; t++)
    {
        ifstream cout(out);
        for (int i = 1; i <= N; i++)
            cout >> best[i];
    }
    ofstream cout(out);

    for (int i = 1; i <= N; i++)
        cin >> point[i].F >> point[i].S;
    for (int i = 1; i <= N; i++)
        ans[i] = best[i] = i;
    srand(time(0));
    for (int t = 1; t <= 30; t++)
    {
        for (int i = 1; i <= N; i++)
            ans[i] = i;
        random_shuffle(ans + 1, ans + 1 + N);

        double cur = 180, the = 180;
        int tries = 100000;
        while (tries--)
        {
            bool found = false;
            for (int i = 1; i <= N - 2; i++)
            {
                for (int j = 2; i <= N - 2; i++)
                {
                    double old = calc(ans);
                    swap(ans[i + 1], ans[j + 1]);
                    double now = calc(ans);
                    if (old < now)
                        found = 1;
                    else
                        swap(ans[i + 1], ans[j + 1]);
                }
            }
            for (int j = 2; j <= N - 2; j++)
            {
                double old = calc(ans);
                swap(ans[1], ans[j]);
                double now = calc(ans);
                if (old < now)
                    found = 1;
                else
                    swap(ans[1], ans[j]);
            }
            if (!found)
                break;
            reverse(ans + 1, ans + 1 + N);
        }
        for (int i = 2; i <= N - 1; i++)
            the = min(the, GetAngle(point[best[i - 1]], point[best[i]], point[best[i + 1]]));
        for (int i = 2; i <= N - 1; i++)
            cur = min(cur, GetAngle(point[ans[i - 1]], point[ans[i]], point[ans[i + 1]]));
        cerr << in << " " << cur << '\n';
        if (cur > the)
            for (int i = 1; i <= N; i++)
                best[i] = ans[i];
    }

    for (int i = 1; i <= N; i++)
        cout << best[i] << '\n';
}

signed main()
{
    // solve(ifstream("sample-01.txt"), ofstream("outputsample_01.txt"));
    solve("input_02.txt", "output_02.txt");
    solve("input_03.txt", "output_03.txt");
    solve("input_04.txt", "output_04.txt");
    solve("input_05.txt", "output_05.txt");
    solve("input_06.txt", "output_06.txt");
}
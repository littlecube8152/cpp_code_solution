#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, vis[81], exclude[81][81], remain = 81;
vector<int> cur;
vector<vector<int>> sol;

void brute(int i)
{
    if (cur.size() == 20)
    {
        sol.emplace_back(cur);
        for (int j : cur)
            cerr << j << ' ';
        cerr << ' ';
        cerr << sol.size() << '\n';
        return;
    }
    if (remain + cur.size() < 20)
        return;
    int tmp = remain;

    for (int j = i + 1; j < min(81, i + 28); j++)
        if (!vis[j])
        {
            remain--;
            int ttmp = remain;
            for (auto k : cur)
                if (exclude[j][k] > j && vis[exclude[j][k]]++ == 0)
                    remain--;
            cur.emplace_back(j);
            brute(j);
            cur.pop_back();
            for (auto k : cur)
                if (exclude[j][k] > j && vis[exclude[j][k]]-- == 1)
                    remain++;
        }
    remain = tmp;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0; i < 81; i++)
        for (int j = 0; j < 81; j++)
            if (i != j)
            {
                int k = 0;
                for (int b = 1; b <= 27; b *= 3)
                    k += (6 - (i / b % 3) - (j / b % 3)) % 3 * b;
                exclude[i][j] = k;
            }
    brute(-1);
}
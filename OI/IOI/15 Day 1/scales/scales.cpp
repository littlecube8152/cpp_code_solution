#include "scales.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int p[7];
void getInit(vector<int> &v)
{
    for (int i = 0; i < 6; i++)
        p[v[i]] = i;
}
int getM(int A, int B, int C, vector<int> &v)
{
    getInit(v);
    int mx = max({p[A], p[B], p[C]}), mi = min({p[A], p[B], p[C]});
    if (mi < p[A] && p[A] < mx)
        return A;
    if (mi < p[B] && p[B] < mx)
        return B;
    return C;
}
int getH(int A, int B, int C, vector<int> &v)
{
    getInit(v);
    int mx = max({p[A], p[B], p[C]});
    if (p[A] == mx)
        return A;
    if (p[B] == mx)
        return B;
    return C;
}
int getL(int A, int B, int C, vector<int> &v)
{
    getInit(v);
    int mi = min({p[A], p[B], p[C]});
    if (p[A] == mi)
        return A;
    if (p[B] == mi)
        return B;
    return C;
}
int getNL(int A, int B, int C, int D, vector<int> &v)
{
    int mi = getL(A, B, C, v),
        me = getM(A, B, C, v),
        mx = getH(A, B, C, v);
    if (p[D] < p[mi])
        return mi;
    if (p[D] < p[me])
        return me;
    if (p[D] < p[mx])
        return mx;
    return mi;
}

/*
int getMedian(int A, int B, int C);
int getHeaviest(int A, int B, int C);
int getLightest(int A, int B, int C);
int getNextLightest(int A, int B, int C, int D);
*/
struct op
{
    int type, a, b, c, d, out;
} tree[800][6];

bool brute(vector<pair<vector<int>, int>> &state, int dep)
{
    // cout << "brute " << sz << '\n';
    int sz = state.size();
    if (sz <= 1)
        return 1;

    for (int D = 1; D <= 6; D++)
        for (int A = 1; A <= 6; A++)
            for (int B = A + 1; B <= 6; B++)
                for (int C = B + 1; C <= 6; C++)
                    if (A != D && B != D && C != D)
                    {
                        vector<pair<vector<int>, int>> space[7];
                        for (auto [v, i] : state)
                            space[getNL(A, B, C, D, v)].emplace_back(make_pair(v, i));
                        bool good = 1;
                        for (int k = 1; k <= 6; k++)
                            if (space[k].size() > (sz + 2) / 3)
                                good = 0;
                        if (good)
                        {
                            bool solve = 1;
                            for (int k = 1; k <= 6; k++)
                                if (!space[k].empty())
                                    solve &= brute(space[k], dep + 1);
                            if (solve)
                            {
                                for (int k = 1; k <= 6; k++)
                                    for (auto [v, i] : space[k])
                                        tree[i][dep] = {2, A, B, C, D, k};
                                return 1;
                            }
                        }
                    }

    for (int A = 1; A <= 6; A++)
        for (int B = A + 1; B <= 6; B++)
            for (int C = B + 1; C <= 6; C++)
            {
                vector<pair<vector<int>, int>> space[7];
                for (auto [v, i] : state)
                {
                    for (int i = 0; i < 6; i++)
                        p[i + 1] = v[i];
                    space[getM(A, B, C, v)].emplace_back(make_pair(v, i));
                }
                bool good = 1;
                for (int k = 1; k <= 6; k++)
                    if (space[k].size() > (sz + 2) / 3)
                        good = 0;
                if (good)
                {
                    bool solve = 1;
                    for (int k = 1; k <= 6; k++)
                        if (!space[k].empty())
                            solve &= brute(space[k], dep + 1);
                    if (solve)
                    {
                        for (int k = 1; k <= 6; k++)
                            for (auto [v, i] : space[k])
                                tree[i][dep] = {1, A, B, C, 0, k};
                        return 1;
                    }
                }
            }
    return 0;
}

vector<pair<vector<int>, int>> allp;
void init(int T)
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 720; i++)
    {
        allp.emplace_back(make_pair(v, i));
        next_permutation(v.begin(), v.end());
    }
    brute(allp, 0);
}

void orderCoins()
{
    vector<int> remain, tmp;
    for (int i = 0; i < 720; i++)
        remain.emplace_back(i);
    for (int i = 0; i < 6; i++)
    {
        int j = remain.back(), res;
        auto [t, a, b, c, d, o] = tree[j][i];
        if (t == 1)
            res = getMedian(a, b, c);
        else
            res = getNextLightest(a, b, c, d);
        tmp.clear();
        for (auto k : remain)
            if (tree[k][i].out == res)
                tmp.emplace_back(k);
        swap(tmp, remain);
    }
    int ans[6];
    for (int i = 0; i < 6; i++)
        ans[i] = allp[remain[0]].first[i];
    answer(ans);
}
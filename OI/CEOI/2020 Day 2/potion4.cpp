#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, d, h[100005], u, hdx;
vector<pair<int, pii>> v[100005];
map<int, int> exist[100005];

void init(int N, int D, int H[])
{
    n = N;
    d = D;
    for (int i = 0; i < N; i++)
        h[i] = H[i];
    for (int i = 0; i < N; i++)
        v[i].emplace_back(pair<int, pii>{0, {0, 0}});
}

void curseChanges(int U, int A[], int B[])
{
    for (int i = 0; i < U; i++)
    {

        if (exist[A[i]].find(B[i]) != exist[A[i]].end())
        {
            if (h[B[i]] == 0)
                v[A[i]].emplace_back(pair<int, pii>{i + 1, pii{v[A[i]].back().S.F - 1, v[A[i]].back().S.S}});
            else
                v[A[i]].emplace_back(pair<int, pii>{i + 1, pii{v[A[i]].back().S.F, v[A[i]].back().S.S - 1}});
            exist[A[i]].erase(exist[A[i]].find(B[i]));

            if (h[A[i]] == 0)
                v[B[i]].emplace_back(pair<int, pii>{i + 1, pii{v[B[i]].back().S.F - 1, v[B[i]].back().S.S}});
            else
                v[B[i]].emplace_back(pair<int, pii>{i + 1, pii{v[B[i]].back().S.F, v[B[i]].back().S.S - 1}});
            exist[B[i]].erase(exist[B[i]].find(A[i]));
        }
        else
        {

            exist[A[i]][B[i]] = 1;
            if (h[B[i]] == 0)
                v[A[i]].emplace_back(pair<int, pii>{i + 1, pii{v[A[i]].back().S.F + 1, v[A[i]].back().S.S}});
            else
                v[A[i]].emplace_back(pair<int, pii>{i + 1, pii{v[A[i]].back().S.F, v[A[i]].back().S.S + 1}});

            exist[B[i]][A[i]] = 1;
            if (h[A[i]] == 0)
                v[B[i]].emplace_back(pair<int, pii>{i + 1, pii{v[B[i]].back().S.F + 1, v[B[i]].back().S.S}});
            else
                v[B[i]].emplace_back(pair<int, pii>{i + 1, pii{v[B[i]].back().S.F, v[B[i]].back().S.S + 1}});
        }
    }
}

int question(int x, int y, int V)
{

    ll ans = 1e9;
    pii X = prev(upper_bound(v[x].begin(), v[x].end(), pair<int, pii>{V, pii{100000000, 100000000}}))->S,
        Y = prev(upper_bound(v[y].begin(), v[y].end(), pair<int, pii>{V, pii{100000000, 100000000}}))->S;
    if(X.F && Y.F)
        return 0;
    if(X.S && Y.S)
        return 0;
    if(X.F + X.S == 0 || Y.F + Y.S == 0)
        return 1e9;
    return 1;
}

/*
6 5 11 4
2 42 1000 54 68 234
0 1
2 0
3 4
3 5
3 5
1 3
5 3
0 5
3 0
1 3
3 5
0 3 4 26
3 0 8 0
0 5 5 1000000000
3 0 11 14
*/
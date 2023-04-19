#include "monster.h"
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define piii tuple<int, int, int>
using namespace std;

vector<int> merge(vector<int> v)
{
    int n = v.size();
    if (n == 1)
        return v;

    vector<int> l, r;
    for (int i = 0; i < n; i++)
        if (i < n / 2)
            l.push_back(v[i]);
        else
            r.push_back(v[i]);

    v.clear();
    l = merge(l);
    r = merge(r);
    int ldx = 0, rdx = 0;
    while (ldx < l.size() || rdx < r.size())
    {
        if (ldx >= l.size())
            v.push_back(r[rdx++]);
        else if (rdx >= r.size())
            v.push_back(l[ldx++]);
        else if (Query(l[ldx], r[rdx]))
            v.push_back(r[rdx++]);
        else
            v.push_back(l[ldx++]);
    }
    return v;
}

vector<int> Solve(int N)
{
    vector<int> v;
    for (int i = 0; i < N; i++)
        v.push_back(i);
    v = merge(v);
    // for (int i = 0; i < N; i++)
    //     cerr << v[i] << " \n"[i == N - 1];
    int start = 0;
    if (Query(v[0], v[1]))
        start = 1;
    else if (Query(v[2], v[0]))
    {
        if (Query(v[3], v[1]))
            start = 2;
        else
            start = 1;
    }
    else if (Query(v[3], v[1]))
        for (int j = 3; j < N; j++)
        {
            if (Query(v[2], v[j]))
            {
                start = 2;
                break;
            }
            else if (Query(v[0], v[j]))
            {
                start = 3;
                break;
            }
            else if (Query(v[1], v[j]))
            {
                start = 1;
                break;
            }
        }
    else
    {
        for (int i = 2; i < N - 2; i++)
            if (Query(v[i + 2], v[i]))
            {
                start = i + 2;
                break;
            }
    }
    // cerr << start << '\n';
    reverse(v.begin(), v.begin() + start);
    for (int i = start; i < N;)
    {
        int j = i;
        while (Query(v[j], v[i - 1]))
            j++;
        j++;
        reverse(v.begin() + i, v.begin() + j);
        i = j;
    }
    // for (int i = 0; i < N; i++)
    //     cerr << v[i] << " \n"[i == N - 1];
    vector<int> T(N);
    for (int i = 0; i < N; i++)
        T[v[i]] = i;
    return T;
}

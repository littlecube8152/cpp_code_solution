#include "scales.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void init(int T)
{
}

/*
int getMedian(int A, int B, int C);
int getHeaviest(int A, int B, int C);
int getLightest(int A, int B, int C);
int getNextLightest(int A, int B, int C, int D);
*/

void ans(int a, int b, int c, int d, int e, int f)
{
    int ret[6] = {a, b, c, d, e, f};
    answer(ret);
}

void orderCoins()
{
    int a, b, c, d, e, f;
    b = getMedian(1, 2, 3);
    a = (b == 1 ? 2 : 1);
    c = (b == 3 ? 2 : 3);
    d = 4;
    e = 5;
    f = 6;
    int res;
    res = getNextLightest(a, c, d, b);
    if (res == a)
    {
        res = getMedian(c, d, a);
        if (res == a)
            tie(a, b, c, d) = make_tuple(c, b, a, d);
        else if (res == c)
            tie(a, b, c, d) = make_tuple(d, c, b, a);
        else
            tie(a, b, c, d) = make_tuple(c, d, b, a);
    }
    else if (res == c)
    {
        res = getMedian(a, b, d);
        if (res == a)
            tie(a, b, c, d) = make_tuple(d, a, b, c);
        else if (res == b)
            tie(a, b, c, d) = make_tuple(a, b, c, d);
        else
            tie(a, b, c, d) = make_tuple(a, d, b, c);
    }
    else
    {
        res = getHeaviest(a, b, c);
        if (res == c)
            tie(a, b, c, d) = make_tuple(a, b, d, c);
        else
            tie(a, b, c, d) = make_tuple(c, b, d, a);
    }
    vector<int> v = {a, b, c, d};
    int pos = 0;
    res = getMedian(b, c, e);
    if (res == e)
        pos = 2;
    else if (res == b)
    {
        res = getMedian(a, b, e);
        if (res == a)
            pos = 0;
        else
            pos = 1;
    }
    else
    {
        res = getMedian(c, d, e);
        if (res == e)
            pos = 3;
        else
            pos = 4;
    }
    v.insert(v.begin() + pos, e);
    tie(a, b, c, d, e) = make_tuple(v[0], v[1], v[2], v[3], v[4]);

    res = getMedian(b, d, f);
    if (res == f)
    {
        res = getMedian(b, c, f);
        if (res == f)
            pos = 2;
        else
            pos = 3;
    }
    else if (res == b)
    {
        res = getMedian(a, b, f);
        if (res == a)
            pos = 0;
        else
            pos = 1;
    }
    else
    {
        res = getMedian(d, e, f);
        if (res == f)
            pos = 4;
        else
            pos = 5;
    }
    v.insert(v.begin() + pos, f);
    ans(v[0], v[1], v[2], v[3], v[4], v[5]);
}
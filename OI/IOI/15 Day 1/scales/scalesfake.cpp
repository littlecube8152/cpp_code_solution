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

void solveBDEF_C(int a, int b, int c, int d, int e, int f)
{
    int res = getNextLightest(b, c, e, a);
    if (res == b)
    {
        // abd efc b
        // abd cef b
        if (getLightest(c, e, f) == e)
            ans(a, b, d, e, f, c);
        else
            ans(a, b, d, c, e, f);
    }
    else if (res == c)
    {
        // cbdeaf c
        // cbdefa c
        if (getMedian(e, a, f) == a)
            ans(c, b, d, e, a, f);
        else
            ans(c, b, d, e, f, a);
    }
    else
    {
        // cbadef e
        // cbdaef e
        if (getNextLightest(d, e, f, a) == d)
            ans(c, b, a, d, e, f);
        else
            ans(c, b, d, a, e, f);
    }
}

void solveBDEC_F(int a, int b, int c, int d, int e, int f)
{
    // abd ecf
    // fec bad
    // fec bda
    int res = getLightest(a, b, d);
    if (res == a)
        ans(a, b, d, e, c, f);
    else
    {
        res = getHeaviest(a, b, d);
        if (res == d)
            ans(f, e, c, b, a, d);
        else
            ans(f, e, c, b, d, a);
    }
}

void solveBCEF_D(int a, int b, int c, int d, int e, int f)
{
    int res = getNextLightest(b, d, f, a);
    if (res == b)
    {
        // da b c e f b   daf
        //  a b cde f b   adf
        //  d e fab c b   dfa
        res = getMedian(a, d, f);
        if (res == a)
            ans(d, a, b, c, e, f);
        else if (res == d)
            ans(a, b, c, d, e, f);
        else
            ans(d, e, f, a, b, c);
    }
    else if (res == d)
    {
        //  adb c e f  d
        // ad e f b c  d
        res = getHeaviest(b, c, e);
        if (res == e)
            ans(a, d, b, c, e, f);
        else
            ans(a, d, e, f, b, c);
    }
    else
    {
        //  dae f b c f
        //  d eaf b c f
        res = getHeaviest(d, a, e);
        if (res == e)
            ans(d, a, e, f, b, c);
        else
            ans(d, e, a, f, b, c);
    }
}

void solveBED_CF(int a, int b, int c, int d, int e, int f)
{
    // afb e dc
    // fab e dc
    // cfb e da
    // fcb e da
    // fce b da
    //cf e b da
    // fce bad
    //cf e bad
    //af e b dc
    // fae b dc
    // f eab dc
    int res = getNextLightest(b, d, f, a);
    if (res == b)
    {
        // da b c e f b   daf
        //  a b cde f b   adf
        //  d e fab c b   dfa
        res = getMedian(a, d, f);
        if (res == a)
            ans(d, a, b, c, e, f);
        else if (res == d)
            ans(a, b, c, d, e, f);
        else
            ans(d, e, f, a, b, c);
    }
    
}

void orderCoins()
{
    int a, b, c, d, e, f;
    b = getMedian(1, 2, 3);
    a = (b == 1 ? 2 : 1);
    c = (b == 3 ? 2 : 3);
    e = getMedian(4, 5, 6);
    d = (e == 4 ? 5 : 4);
    f = (e == 6 ? 5 : 6);
    int cdf_b = getNextLightest(c, d, f, b),
        cdf_e = getNextLightest(c, d, f, e);
    if (cdf_b == d && cdf_e == f)
        solveBDEF_C(a, b, c, d, e, f);
    else if (cdf_b == d && cdf_e == c)
        solveBDEC_F(a, b, c, d, e, f);
    else if (cdf_b == f && cdf_e == c)
        solveBDEC_F(a, b, c, f, e, d);
    else if (cdf_b == f && cdf_e == d)
        solveBDEF_C(a, b, c, f, e, d);
    else if (cdf_b == c && cdf_e == d)
        solveBCEF_D(a, b, c, f, e, d);
    else if (cdf_b == c && cdf_e == f)
        solveBCEF_D(a, b, c, d, e, f);
    else
        assert(0);
}
/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
/*
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
//#pragma pack(0)
*/
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 640000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll H, W, tmpmat[64][64], dp[64];

void copy(ll a[64][64], ll b[64][64])
{
    for (int i = 0; i <= 64; i++)
        for (int j = 0; j <= 64; j++)
            b[i][j] = a[i][j];
}

void mul(ll a[64][64], ll b[64][64], ll c[64][64])
{
    for (int i = 0; i <= 64; i++)
        for (int j = 0; j <= 64; j++)
            c[i][j] = 0;
    for (int i = 0; i <= 64; i++)
        for (int j = 0; j <= 64; j++)
            for (int p = 0; p <= 64; p++)
                if (a[i][p] != 0)
                    if (b[p][j] != 0)
                        c[i][j] = (c[i][j] + a[i][p] * b[p][j]) % MOD;
}

void mtxfastpow(ll base[64][64], ll res[64][64], ll p)
{
    while (p > 0)
    {
        if (p & 1)
        {
            mul(res, base, tmpmat);
            copy(tmpmat, res);
        }
        p >>= 1;
        mul(base, base, tmpmat);
        copy(tmpmat, base);
    }
}

ll cal()
{
    ll base[64][64] = {{0}}, res[64][64] = {{0}};

    for (int i = 0; i < (1 << H); i++)
    {
        int ri = ((1 << H) - 1) ^ i;
        for (int s = ri;; s = (s - 1) & ri)
        {
            base[i][s] = dp[i | s];
            if (s == 0)
                break;
        }
    }
    mtxfastpow(base, res, W);
    return res[0][0];
}

signed main()
{
    for (int i = 63; i >= 0; i++)
        cin >> H >> W;
    cout << cal() % MOD << '\n';
}

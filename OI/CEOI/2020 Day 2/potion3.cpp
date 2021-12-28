#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, d, h[100005], u, hdx;
multiset<ll> st[100005];
map<int, int> exist[100005];

void init(int N, int D, int H[])
{
    n = N;
    d = D;
    for (int i = 0; i < N; i++)
        h[i] = H[i];
    for (int i = 0; i < N; i++)
    {
        st[i].insert(-2e9);
        st[i].insert(2e9);
    }
}

void curseChanges(int U, int A[], int B[])
{
    for (int i = 0; i < U; i++)
    {

        int a = A[i], b = B[i];
        if (exist[A[i]].find(B[i]) != exist[A[i]].end())
        {
            st[A[i]].erase(st[A[i]].find(h[B[i]]));
            exist[A[i]].erase(exist[A[i]].find(B[i]));

            st[B[i]].erase(st[B[i]].find(h[A[i]]));
            exist[B[i]].erase(exist[B[i]].find(A[i]));
        }
        else
        {

            exist[A[i]][B[i]] = 1;
            st[A[i]].insert(h[B[i]]);

            exist[B[i]][A[i]] = 1;
            st[B[i]].insert(h[A[i]]);
        }
    }
}

int question(int x, int y, int v)
{

    ll ans = 1e9;
    for (ll i : st[x])
    {
        if(i <= -1.5e9 || i >= 1.5e9)
            continue;
        auto iter = st[y].lower_bound(i);
        ans = min({ans, abs(i - *iter), abs(i - *prev(iter))});
    }
    return ans;
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
3 0 11 14*/
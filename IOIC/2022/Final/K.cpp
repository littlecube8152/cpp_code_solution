#include <bits/stdc++.h>
using namespace std;

#define maxn 100005

string s;
int sa[maxn], tmp[maxn], lcp[maxn], rk[maxn], rklcp[maxn], lcptable[21][maxn], rktable[21][maxn];

void GetSA()
{
    vector<int> v;
    int N = s.size();
    for (int i = 0; i < N; i++)
        v.emplace_back(i);
    sort(v.begin(), v.end(), [&](int i, int j)
         { return make_pair(s[i], i) < make_pair(s[j], j); });
    sa[0] = 0;
    for (int i = 1; i < N; i++)
        sa[v[i]] = sa[v[i - 1]] + (s[v[i]] != s[v[i - 1]]);
    for (int k = 1; k <= N; k *= 2)
    {
        sort(v.begin(), v.end(), [&](int i, int j)
             { return make_pair(sa[i], sa[(i + k) % N]) < make_pair(sa[j], sa[(j + k) % N]); });
        tmp[0] = 0;
        for (int i = 1; i < N; i++)
            tmp[v[i]] = tmp[v[i - 1]] + (make_pair(sa[v[i]], sa[(v[i] + k) % N]) != make_pair(sa[v[i - 1]], sa[(v[i - 1] + k) % N]));
        for (int i = 0; i < N; i++)
            sa[i] = tmp[i];
    }
}

void GetLCP()
{

    int N = s.size();
    for (int i = 0; i < N; i++)
        rk[sa[i]] = i;
    int k = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int j = rk[sa[i] - 1];
        while (s[i + k] == s[j + k])
            k++;
        lcp[i] = k;
        rklcp[sa[i] - 1] = k;
        k = max(0, k - 1);
    }
}

//[L, R)
int queryLCP(int L, int R)
{
    //cout << L << " " << R << '\n';
    int p = __lg(R - L);
    return min(lcptable[p][L], lcptable[p][R - (1 << p)]);
}

//[L, R]
int queryID(int L, int R)
{
    int p = __lg(R - L + 1);
    return min(rktable[p][L], rktable[p][R - (1 << p) + 1]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    cin >> s;
    s += '$';
    N = s.size();
    GetSA();
    GetLCP();
    for (int i = 1; i < N - 1; i++)
        lcptable[0][i] = rklcp[i];
    for (int p = 1; p <= 20; p++)
        for (int i = 1; i < N - 1; i++)
            lcptable[p][i] = min(lcptable[p - 1][i], lcptable[p - 1][min(N - 2, i + (1 << (p - 1)))]);

    for (int i = 1; i < N; i++)
        rktable[0][i] = rk[i];
    for (int p = 1; p <= 20; p++)
        for (int i = 1; i < N; i++)
            rktable[p][i] = min(rktable[p - 1][i], rktable[p - 1][min(N - 1, i + (1 << (p - 1)))]);

    for (int i = 1; i <= Q; i++)
    {
        int l, r, rank;
        cin >> l >> r;
        rank = sa[l - 1];
        int LL = 1, LR = rank, RL = rank, RR = N - 1;
        assert(LL <= LR);
        assert(RL <= RR);
        while (LL != LR)
        {
            //cout << "Lbs " << LL << " " << LR << '\n';
            int mid = (LL + LR) / 2;
            if (queryLCP(mid, rank) < r - l + 1)
                LL = mid + 1;
            else
                LR = mid;
        }
        while (RL != RR)
        {
            //cout << "Rbs " << RL << " " << RR << '\n';
            int mid = (RL + RR + 1) / 2;
            if (queryLCP(rank, mid) < r - l + 1)
                RR = mid - 1;
            else
                RL = mid;
        }
        //cout << LL << " " << RR << " ";
        cout << queryID(LL, RR) + 1 << '\n';
    }
}
/*
ittmcsvmoa 0 
ittmcsvmoa 1
ittmcsvmoa 2
ittmcsvmoa 3
ittmcsvmoa 4
ittmcsvmoa 5
ittmcsvmoa 6
ittmcsvmoa 7 
ittmcsvmoa 8
ittmcsvmoa 10

*/
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define F first
#define S second
#define ll long long
using namespace std;

int N;
pll p[500005];

ll dis(int i, int j)
{
    return -((p[i].F - p[j].F) * (p[i].F - p[j].F) + (p[i].S - p[j].S) * (p[i].S - p[j].S));
}

ll A(int i, int j)
{
    if (j < i)
        return i - j;
    else if (i + N <= j)
        return j - i;
    else
        return dis(i, (j - 1) % N + 1);
}

int opt[500005];
void smawk(vector<int> &r, vector<int> &c);
void interpolate(vector<int> &r, vector<int> &c)
{
    int n = (int)r.size();
    vector<int> er;
    for (int i = 1; i < n; i += 2)
        er.emplace_back(r[i]);
    smawk(er, c);
    for (int i = 0, j = 0; j < c.size(); j++)
    {
        if (A(r[i], c[j]) < A(r[i], opt[r[i]]))
            opt[r[i]] = c[j];
        if (i + 2 < n && c[j] == opt[r[i + 1]])
            j--, i += 2;
    }
}

void reduce(vector<int> &r, vector<int> &c)
{
    int n = (int)r.size();
    vector<int> nc;
    for (int i : c)
    {
        int j = (int)nc.size();
        while (j && A(r[j - 1], nc[j - 1]) > A(r[j - 1], i))
            nc.pop_back(), j--;
        if (nc.size() < n)
            nc.emplace_back(i);
    }
    smawk(r, nc);
}

void smawk(vector<int> &r, vector<int> &c)
{
    if (r.size() == 1 && c.size() == 1)
        opt[r[0]] = c[0];
    else if (r.size() >= c.size())
        interpolate(r, c);
    else
        reduce(r, c);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;

    while (T--)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> p[i].F >> p[i].S;
        for (int i = 1; i <= N; i++)
            opt[i] = 0;
        // for (int i = 1; i <= N; i++)
        //     for (int j = 1; j <= 2 * N; j++)
        //         cout << A(i, j) << " \n"[j == 2 * N];

        vector<int> r, c;
        for (int i = 1; i <= N; i++)
            r.emplace_back(i);
        for (int i = 1; i <= 2 * N; i++)
            c.emplace_back(i);
        smawk(r, c);

        for (int i = 1; i <= N; i++)
            cout << (opt[i] - 1) % N + 1 << "\n";
    }
}

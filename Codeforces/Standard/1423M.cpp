#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define F first
#define S second
#define ll long long
using namespace std;

int N, M;
map<pll, ll> mp;

ll A(int i, int j)
{
    if (j == 0)
        return 2e9;
    if (mp[pll(i, j)] == 0)
    {
        cout << "? " << i << " " << j << endl;
        cin >> mp[pll(i, j)];
    }
    return mp[pll(i, j)];
}

int opt[1000005];
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

    cin >> N >> M;

    vector<int> r, c;
    for (int i = 1; i <= N; i++)
        r.emplace_back(i);
    for (int i = 1; i <= M; i++)
        c.emplace_back(i);
    smawk(r, c);
    ll ansi = 1;
    for (int i = 1; i <= N; i++)
        if (A(i, opt[i]) < A(ansi, opt[ansi]))
            ansi = i;
    cout << "! " << A(ansi, opt[ansi]) << endl;
}

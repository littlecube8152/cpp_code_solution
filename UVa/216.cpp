#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct State
{
    bitset<8> b = 0;
    vector<int> v = {};
    double val = 0;
    bool operator<(State &s)
    {
        return this->val < s.val;
    }
};

struct Point
{
    double x, y;
};

double distance(Point a, Point b)
{
    return sqrt((abs(a.x - b.x) * abs(a.x - b.x)) + (abs(a.y - b.y) * abs(a.y - b.y)));
}

Point p[10];

State dfs(State s, int n, int k)
{
    if (k == n)
        return s;

    vector<State> v;

    for (int i = 0; i < n; i++)
    {
        if (!s.b[i])
        {
            State t = s;
            t.b |= (1 << i);
            if (!t.v.empty())
                t.val += distance(p[t.v.back()], p[i])+ 16.0;

            t.v.emplace_back(i);
            v.emplace_back(dfs(t, n, k + 1));
        }
    }
    State r;
    r.val = 1000000000000;
    for (auto i : v)
        if (i < r)
            r = i;
    return r;
}

int main()
{
    int n, t = 1;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;
        State s;
        s = dfs(s, n, 0);
        cout << "**********************************************************\n";
        cout << "Network #" << t << '\n';
        for (int i = 0; i < s.v.size() - 1; i++)
            cout << fixed << setprecision(0) << "Cable requirement to connect (" << p[s.v[i]].x << ',' << p[s.v[i]].y << ") to (" << p[s.v[i + 1]].x << ',' << p[s.v[i + 1]].y << ") is " << setprecision(2) << distance(p[s.v[i]], p[s.v[i + 1]]) + 16.0 << " feet.\n";
        cout << "Number of feet of cable required is " << s.val << ".\n";
        t++;
    }
}
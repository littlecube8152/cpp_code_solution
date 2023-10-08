#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, q;
ll a, b, dsu[100005], l[100005], r[100005];
map<ll, ll> coin;

int find(int k)
{
    return dsu[k] == k ? k : dsu[k] = find(dsu[k]);
}

void merge(int x, int y)
{
    x = find(x), y = find(y);
    b -= r[x] - l[x] + r[y] - l[y];
    a--;
    dsu[x] = y;
    l[y] = min(l[x], l[y]), r[y] = max(r[x], r[y]);
    b += r[y] - l[y];
}

signed main()
{
    cin >> n >> q;
    a = n;
    vector<ll> v(n);
    vector<pair<ll, int>> ev;
    for (int i = 0; i < n; i++)
    {
        dsu[i] = i;
        cin >> v[i] >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        l[i] = r[i] = v[i];
    for (int i = 0; i + 1 < n; i++)
        ev.emplace_back(pii(v[i + 1] - v[i], i));
    sort(ev.begin(), ev.end());
    int e = 0;
    for (int i = 1; i <= q; i++)
    {
        ll tmp = 0, t;
        cin >> t;
        vector<int> op;
        while (e < ev.size() && ev[e].F <= t)
        {
            if (ev[e].F == t)
            {
                op.emplace_back(ev[e].S);
                tmp++;
            }
            else
                merge(ev[e].S, ev[e].S + 1);
            e++;
        }
        if (t == 0)
            cout << n << '\n';
        else
            cout << a * 4 * t + 2 * b - (t + 1) * tmp << '\n';
        for (int i : op)
            merge(i, i + 1);
    }
}
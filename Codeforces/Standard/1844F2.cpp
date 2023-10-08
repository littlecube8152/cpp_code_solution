/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t;

void solve(vector<int> v, int c)
{
    if (v.size() == 1)
        cout << v[0] << ' ';
    else
    {
        set<pii> remain, can;
        auto check = [&](int i) -> bool
        {
            auto iter = remain.lower_bound(pii(i, 0));
            if (iter == remain.begin() || next(iter) == remain.end())
                return false;
            return prev(iter)->S + c <= next(iter)->S;
        };
        vector<int> p;
        p.emplace_back(v[0]);

        for (int i = 1; i < v.size(); i++)
            remain.insert(pii(i, v[i]));
        for (int i = 1; i + 1 < v.size(); i++)
            if (check(i))
                can.insert(pii(v[i], i));
        while (!remain.empty())
        {
            auto iter = can.lower_bound(pii(p.back() + c, 0));
            if (iter == can.end())
            {
                p.emplace_back(remain.begin()->S);
                remain.erase(remain.begin());
                if (!remain.empty())
                {
                    int i = remain.begin()->F;
                    if (!check(i))
                        can.erase(pii(v[i], i));
                }
            }
            else
            {
                p.emplace_back(iter->F);
                int i = iter->S;
                can.erase(iter);
                iter = remain.find(pii(i, v[i]));
                int j = -1, k = -1;
                if (next(iter) != remain.end())
                    j = next(iter)->F;
                if (iter != remain.begin())
                    k = prev(iter)->F;

                remain.erase(pii(i, v[i]));
                if (j >= 0 && !check(j))
                    can.erase(pii(v[j], j));

                if (k >= 0 && !check(k))
                    can.erase(pii(v[k], k));
            }
        }
        for (int i : p)
            cout << i << ' ';
    }
}

signed main()
{
    fast;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        if (c >= 0)
        {
            sort(v.begin(), v.end());
            for (int i = 0; i < n; i++)
                cout << v[i] << " \n"[i == n - 1];
            continue;
        }
        sort(v.begin(), v.end(), greater<>());
        for (int l = 0; l < n;)
        {
            int r = l + 1;
            while (r < n && v[r - 1] + c <= v[r])
                r++;
            vector<int> p(v.begin() + l, v.begin() + r);
            solve(p, c);
            l = r;
        }
        cout << '\n';
    }
}

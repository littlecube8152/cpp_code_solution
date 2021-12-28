//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, c[505], ans;
set<int> leaf, mid;
set<pii> edge;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if (c[i] == 1)
            leaf.insert(i);
        else
            mid.insert(i);
    }
    ans = min(mid.size() + 2, mid.size() + leaf.size());

    for (int i : mid)
        c[i] -= 2;

    if (leaf.size() >= 2)
    {
        int x = *leaf.begin();
        leaf.erase(leaf.begin());
        for (int i : mid)
        {
            edge.insert(make_pair(x, i));
            x = i;
        }
        edge.insert(make_pair(x, *leaf.begin()));
        leaf.erase(leaf.begin());

        for (int i : leaf)
        {
            for (int j : mid)
                if (c[j] > 0)
                {
                    c[j]--, c[i]--;
                    edge.insert(make_pair(i, j));
                    break;
                }
            if (c[i] > 0)
            {
                cout << "NO";
                return 0;
            }
        }
    }
    else if (leaf.size() >= 1)
    {
        int x = *leaf.begin();
        leaf.erase(leaf.begin());
        for (int i : mid)
        {
            edge.insert(make_pair(x, i));
            x = i;
        }
    }
    else
    {
        int x = *mid.begin();
        mid.erase(mid.begin());
        for (int i : mid)
        {
            edge.insert(make_pair(x, i));
            x = i;
        }
    }
    cout << "YES " << ans - 1 << "\n";
    cout << edge.size() << '\n';
    for (auto i : edge)
        cout << i.first << " " << i.second << '\n';
}
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int cross(pii p1, pii p2)
{
    return p1.first * p2.second - p1.second * p2.first;
}

signed main()
{
    int n, res = 0;
    vector<pair<int, int>> v;
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            pair<int, int> vec1 = make_pair(v[j].first - v[i].first, v[j].second - v[i].second);
            int pos = 0, neg = 0;
            for (int k = 0; k < n; k++)
            {
                pair<int, int> vec2 = make_pair(v[k].first - v[i].first, v[k].second - v[i].second);
                if (cross(vec1, vec2) > 0)
                    pos++;
                else if (cross(vec1, vec2) < 0)
                    neg++;
            }
            res += (pos * neg);
        }
    cout << res << '\n';
}
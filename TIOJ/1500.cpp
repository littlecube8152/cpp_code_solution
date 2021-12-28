#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sort_first(type) [](pair<type, type> p1, pair<type, type> p2) {if(p1.first != p2.first)return p1.first < p2.first; return p1.second < p2.second; }
#define sort_second(type) [](pair<type, type> p1, pair<type, type> p2) {if(p1.second != p2.second)return p1.second < p2.second; return p1.first < p2.first; }
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<pll> v;
ll n, x, y;

long double dis(pll p1, pll p2)
{
    return sqrt(double(p1.first - p2.first) * (p1.first - p2.first) + double(p1.second - p2.second) * (p1.second - p2.second));
}

long double dc(int L, int R)
{
    if (abs(L - R) == 1)
        return dis(v[L], v[R]);
    if (abs(L - R) == 2)
        return min({dis(v[L], v[R]), dis(v[L + 1], v[R]), dis(v[L], v[L + 1])});
    int mid = (L + R) / 2;
    long double res = min(dc(L, mid), dc(mid + 1, R));
    if (res == 0.0)
        return 0.0;
    int Lmid = max((int)(lower_bound(v.begin(), v.end(), make_pair(v[mid].first - (ll)ceil(res), 0), sort_first(ll)) - v.begin()), L),
        Rmid = min((int)(upper_bound(v.begin(), v.end(), make_pair(v[mid + 1].first + (ll)ceil(res), _INFINITY), sort_first(ll)) - v.begin()), R);

    sort(v.begin() + Lmid, v.begin() + Rmid + 1, sort_second(ll)); // sort by Y

    for (int i = Lmid; i <= Rmid; i++)
        for (int j = i + 1; j <= Rmid; j++)
        {
            if ((long double)abs(v[i].second - v[j].second) > res)
                break;
            res = min(res, dis(v[i], v[j]));
        }

    sort(v.begin() + Lmid, v.begin() + Rmid + 1, sort_first(ll)); // sort by X to reverse to original state

    return res;
}

signed main()
{
    fast;
    while (cin >> n)
    {
        v.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            v.emplace_back(make_pair(x, y));
        }
        if (n == 1)
        {
            cout << "0\n";
            continue;
        }

        sort(v.begin(), v.end(), sort_first(ll));
        double res = dc(0, n - 1);
        cout << fixed << setprecision(6) << res << '\n';
    }
}
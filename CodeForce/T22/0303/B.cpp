#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int n, c;

bool COMP(pair<pii, int> p1, pair<pii, int> p2)
{
    if (p1.F.F != p2.F.F)
        return p1.F.F > p2.F.F;
    return p1.F.S < p2.F.S;
}

set<pair<pii, int>, decltype(COMP)*> pri(COMP);
set<pair<int, pii>> arr;
stack<pii> s;
pair<pii, int> arr_to_pri(pair<int, pii> p)
{
    return make_pair(make_pair(p.S.F, p.F), p.S.S);
}

pair<int, pii> pri_to_arr(pair<pii, int> p)
{
    return make_pair(p.F.S, make_pair(p.F.F, p.S));
}

signed main()
{
    //fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (!s.empty() && s.top().S == x)
            s.top().F++;
        else
            s.push(make_pair(1, x));
    }
    //cout << "Cin Finish\n";
    while (!s.empty())
    {
        pri.insert(arr_to_pri(make_pair(s.size(), s.top()))), arr.insert(make_pair(s.size(), s.top()));
        s.pop();
    }
    //cout << "Stack Finish\n";
    while (!arr.empty())
    {
        auto iter = arr.find(pri_to_arr(*pri.begin())), pre = prev(iter), nxt = next(iter);
        //if(iter == arr.end())
        //cout << "End Error\n";
        //cout << "Del " << iter->S.F << " of number " << iter->S.S << '\n';
        if (iter == arr.begin() || nxt == arr.end())
            arr.erase(iter), pri.erase(pri.begin());
        else
        {
            if (pre->S.S == nxt->S.S)
            {
                pair<int, pii> p = *pre;
                p.S.F += nxt->S.F;
                auto previt = *pre, it = *iter, nextit = *nxt;
                arr.erase(arr.find(previt)), arr.erase(arr.find(it)), arr.erase(arr.find(nextit));
                pri.erase(pri.find(arr_to_pri(previt))), pri.erase(pri.begin()), pri.erase(arr_to_pri(nextit));
                arr.insert(p), pri.insert(arr_to_pri(p));
            }
            else
                arr.erase(iter), pri.erase(pri.begin());
        }
        c++;
    }
    cout << c;
}
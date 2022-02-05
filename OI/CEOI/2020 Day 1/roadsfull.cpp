#include <bits/extc++.h>
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;

int N, vis[200005];
pll p[100005][2];
pii ans[100005];
vector<pii> v;

int curx = -1e8;
struct sort_by_y
{
    double intersect(int a, int x) const
    {
        if (p[a][0].F == p[a][1].F)
            return (p[a][0].S + p[a][1].S) / 2;
        
        return p[a][0].S + double(p[a][1].S - p[a][0].S) * double(x - p[a][0].F) / double(p[a][1].F - p[a][0].F);
    }
    bool operator()(int a, int b) const
    {
        int curx = max(p[a][0].F, p[b][0].F);
        if (p[a][0].F == p[a][1].F)
            curx = p[a][0].F;
        if (p[b][0].F == p[b][1].F)
            curx = p[b][0].F;
        return intersect(a, curx) < intersect(b, curx);
    }
};

map<int, pii, sort_by_y> sweep;

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i][0].F >> p[i][0].S >> p[i][1].F >> p[i][1].S;
    for (int i = 1; i <= N; i++)
        if (p[i][0] > p[i][1])
            swap(p[i][0], p[i][1]);
    for (int i = 1; i <= N; i++)
    {
        v.emplace_back(pii{i, 0});
        v.emplace_back(pii{i, 1});
    }
    p[0][0] = pii{-1e8, 1e8}, p[0][1] = pii{1e8, 1e8};
    sort(v.begin(), v.end(), [&](pii p1, pii p2)
         {/*
             if (p[p1.F][p1.S].F == p[p2.F][p2.S].F)
             {
                 if (p1.F == p2.F)
                     return p1.S < p2.S;
                 return p1.S > p2.S;
             }
             else*/
                 return p[p1.F][p1.S]/*.F*/ < p[p2.F][p2.S]/*.F*/;
         });
    sweep[0] = {0, 0};
    for (int i = 0; i < v.size(); i++)
    {
        
        if (v[i].S == 1)
        {
            //cout << "remove " << v[i].F << '\n';
            auto iter = sweep.erase(sweep.find(v[i].F));
            sweep[iter->F] = v[i];
        }
        else
        {
            //cout << "insert " << v[i].F << '\n';
            auto iter = sweep.upper_bound(v[i].F);
            ans[v[i].F] = sweep[iter->F];
            //cout << "...with answer " << ans[v[i].F].F << " " << ans[v[i].F].S << '\n';
            sweep[v[i].F] = v[i];
            iter = sweep.upper_bound(v[i].F);
            sweep[iter->F] = v[i];
        }
    }

    for (int i = 1; i <= N; i++)
        if(ans[i] != pii{0, 0})
            cout << p[i][0].F << " " << p[i][0].S << " " << p[ans[i].F][ans[i].S].F << " " << p[ans[i].F][ans[i].S].S << "\n";
}

/*
4 
1 1 3 2
1 3 5 3
6 1 5 5
1 4 4 5
*/
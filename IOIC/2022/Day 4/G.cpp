#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second

pll operator-(pll p1, pll p2)
{
    return pll{p1.F - p2.F, p1.S - p2.S};
}

pll operator+(pll p1, pll p2)
{
    return pll{p1.F + p2.F, p1.S + p2.S};
}
const pll inf = {1e9 + 1, -1};

int quadurant(pll p)
{
    if (p.F > 0 && p.S >= 0)
        return 1;
    else if (p.F <= 0 && p.S > 0)
        return 2;
    else if (p.F < 0 && p.S <= 0)
        return 3;
    else
        return 4;
}

bool angle_sort(pll p1, pll p2)
{
    if (quadurant(p1) != quadurant(p2))
    {
        if (quadurant(p1) < quadurant(p2))
            return true;
        else
            return false;
    }
    else
        // p1.S / p1.F < p2.S / p2.F
        return p2.F * p1.S < p2.S * p1.F;
}

bool half_angle_sort(pll p1, pll p2)
{
    pll O = {0, 0};
    if (p1.S < 0)
        p1 = O - p1;
    if (p2.S < 0)
        p2 = O - p2;
    return angle_sort(p1, p2);
}

int ori(pll p1, pll p2)
{
    // | p1.F p1.S |
    // | p2.F p2.S |
    ll res = p1.F * p2.S - p1.S * p2.F;
    if (res > 0)
        return 1;
    else if (res == 0)
        return 0;
    return -1;
}

bool through_xplus(pll p1, pll p2)
{
    pll O = {0, 0}, farx = {1e9 + 1, 0};
    if (ori(O - p1, p2 - p1) * ori(farx - p1, p2 - p1) < 0 && ori(p1 - O, farx - O) * ori(p2 - O, farx - O) < 0)
        return 1;
    else if ((p1.F > 0 && p1.S == 0 && p2.S < 0) || (p2.F > 0 && p2.S == 0 && p1.S < 0))
        return 1;
    else
        return 0;
}

bool through_xneg(pll p1, pll p2)
{
    pll O = {0, 0}, farx = {-1e9 - 1, 0};
    if (ori(O - p1, p2 - p1) * ori(farx - p1, p2 - p1) < 0 && ori(p1 - O, farx - O) * ori(p2 - O, farx - O) < 0)
        return 1;
    else if ((p1.F < 0 && p1.S == 0 && p2.S > 0) || (p2.F < 0 && p2.S == 0 && p1.S > 0))
        return 1;
    else
        return 0;
}

bool through_O(pll p1, pll p2)
{
    pll O = {0, 0};
    if (p1 == O || p2 == O)
        return 1;
    if (ori(O - p1, p2 - p1) == 0 && quadurant(p1) != quadurant(p2))
        return 1;
    else
        return 0;
}

int N, ans;
pair<pll, pll> line[1505];

int solve(pll O, int ex)
{
    vector<pair<pll, int>> v;
    int cnt = 1, cur = 0, ans = 0;
    for (int i = 1; i <= N; i++)
        if (i != ex)
        {
            line[i].F = line[i].F - O;
            line[i].S = line[i].S - O;
        }

    for (int i = 1; i <= N; i++)
        if (i != ex)
        {
            if (through_O(line[i].F, line[i].S))
            {
                cnt++;
                continue;
            }
            else if (through_xplus(line[i].F, line[i].S))
            {
                //cout << i << " is through x+\n";
                if (quadurant(line[i].F) > quadurant(line[i].S))
                    swap(line[i].F, line[i].S);
                v.emplace_back(pair<pll, int>{pll{1, 0}, 1});
                v.emplace_back(pair<pll, int>{line[i].F, -1});
                v.emplace_back(pair<pll, int>{pll{0, 0} - line[i].S, 1});
                v.emplace_back(pair<pll, int>{pll{-1, 0}, -1});
            }
            else if (through_xneg(line[i].F, line[i].S))
            {
                //cout << i << " is through x-\n";
                if (quadurant(line[i].F) > quadurant(line[i].S))
                    swap(line[i].F, line[i].S);
                v.emplace_back(pair<pll, int>{line[i].F, 1});
                v.emplace_back(pair<pll, int>{pll{-1, 0}, -1});
                v.emplace_back(pair<pll, int>{pll{1, 0}, 1});
                v.emplace_back(pair<pll, int>{pll{0, 0} - line[i].S, -1});
            }
            else
            {
                if (!angle_sort(line[i].F, line[i].S))
                    swap(line[i].F, line[i].S);
                if (line[i].F.S + line[i].S.S > 0)
                {
                    v.emplace_back(pair<pll, int>{line[i].F, 1});
                    v.emplace_back(pair<pll, int>{line[i].S, -1});
                }
                else
                {
                    v.emplace_back(pair<pll, int>{pll{0, 0} - line[i].F, 1});
                    v.emplace_back(pair<pll, int>{pll{0, 0} - line[i].S, -1});
                }
            }
        }
    sort(v.begin(), v.end(), [&](pair<pll, int> p1, pair<pll, int> p2)
         {
             assert(quadurant(p1.F) <= 3);
             assert(quadurant(p2.F) <= 3);
             if (!angle_sort(p1.F, p2.F) && !angle_sort(p2.F, p1.F))
                 return p1.S > p2.S;
             else
                 return angle_sort(p1.F, p2.F);
         });
    for (auto [p, w] : v)
    {
        cur += w;
        ans = max(ans, cur);
        //cout << "(" << (p).F << ", " << (p).S << ")" << cur << " " << w << "\n";
    }
    for (int i = 1; i <= N; i++)
        if (i != ex)
        {
            line[i].F = line[i].F + O;
            line[i].S = line[i].S + O;
        }
    // cout << ex << " " << ans + cnt << '\n';
    return ans + cnt;
}

int32_t main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> line[i].F.F >> line[i].F.S >> line[i].S.F >> line[i].S.S;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, solve(line[i].F, i));
        ans = max(ans, solve(line[i].S, i));
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, K, A[505], B[505], mxC;
double ans = 1e15;

signed main()
{
    cin >> N >> K;
    mxC = N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
        if (B[i] == -1)
            mxC--, B[i] = 1e15;
    }
    for (int i = 0; i <= min(K, mxC); i++)
    {
        vector<pll> coor;
        vector<ll> vote;
        for (int j = 1; j <= N; j++)
        {
            coor.emplace_back(pll{B[j], A[j]});
            sort(coor.begin(), coor.end());
            ll best = 0;
            double bestans = 1e15;
            if (coor.size() > i)
            {
                for (int k = 0; k <= i; k++)
                {
                    double pre = 1, cur = 0;
                    for (int l = 0; l <= i; l++)
                        if (l != k)
                        {
                            cur += double(coor[l].F) / pre;
                            pre++;
                        }
                    cur += double(coor[k].S) / pre;
                    if (cur < bestans)
                        best = k, bestans = cur;
                }
                vote.emplace_back(coor[best].S);
                coor.erase(coor.begin() + best);
            }
        }
        sort(vote.begin(), vote.end());
        double pre = 1, cur = 0;
        for (int j = 0; j < i; j++)
        {
            cur += double(coor[j].F) / pre;
            pre++;
        }
        for (int j = 0; j < K - i; j++)
            cur += double(vote[j]) / pre;
        ans = min(cur, ans);
    }
    cout << fixed << setprecision(10) << ans << '\n';
}
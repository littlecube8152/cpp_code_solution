#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, ans;
pair<pii, int> p[100005];

signed main()
{
    fast;
    ifstream cin("triangles.in");
    ofstream cout("triangles.out");
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i].F.F >> p[i].F.S;
    sort(p + 1, p + 1 + N);
    for (int i = 1; i <= N;)
    {
        vector<int> v = {0};
        int sum = 0;
        int j = i;
        for (; j <= N; j++)
            if (p[j].F.F == p[i].F.F)
                v.emplace_back(p[j].F.S);
            else
                break;
        j--;
        for (int j : v)
            sum = (sum + j) % MOD;
        for (int j = 1; j < v.size(); j++)
            v[j] = (v[j - 1] + v[j]) % MOD;
        for (int k = i; k <= j; k++)
            p[k].S = ((sum - v[k - i + 1] - (j - k) * p[k].F.S + (k - i) * p[k].F.S - v[k - i]) % MOD + MOD) % MOD;
        i = j + 1;
    }
    

    for (int i = 1; i <= N; i++)
        swap(p[i].F.F, p[i].F.S);
    sort(p + 1, p + 1 + N);
    for (int i = 1; i <= N;)
    {
        vector<int> v = {0};
        int sum = 0;
        int j = i;
        for (; j <= N; j++)
            if (p[j].F.F == p[i].F.F)
                v.emplace_back(p[j].F.S);
            else
                break;
        j--;
        for (int j : v)
            sum = (sum + j) % MOD;
        for (int j = 1; j < v.size(); j++)
            v[j] = (v[j - 1] + v[j]) % MOD;
        for (int k = i; k <= j; k++)
            ans = (ans + (p[k].S * (sum - v[k - i + 1] - (j - k) * p[k].F.S + (k - i) * p[k].F.S - v[k - i]) % MOD) + MOD) % MOD;
        i = j + 1;
    }
    cout << ans << '\n';
}
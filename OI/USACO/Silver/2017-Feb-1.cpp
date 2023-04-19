#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, C, T[20005], ans;
pii a[20005];

signed main()
{
    fast;
    ifstream cin("helpcross.in");
    ofstream cout("helpcross.out");
    cin >> C >> N;
    for (int i = 1; i <= C; i++)
        cin >> T[i];
    for (int i = 1; i <= N; i++)
        cin >> a[i].F >> a[i].S;
    sort(T + 1, T + 1 + C);
    sort(a + 1, a + 1 + N);
    int idx = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= C; i++)
    {
        while(idx <= N && a[idx].F <= T[i])
            pq.push(a[idx++].S);
        while(!pq.empty() && pq.top() < T[i])
            pq.pop();
        if(!pq.empty())
            pq.pop(), ans++;
    }
    cout << ans << '\n';
}
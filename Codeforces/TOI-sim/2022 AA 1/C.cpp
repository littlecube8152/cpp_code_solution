#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, h[400005], v[400005];

void solve()
{
    cin >> N;
    // We build an edge i -> j if hj >= hi + vi, since we can't put j earlier than i
    // Therefore, the point u without in-edge satisfies hi + vi > hu for all i
    // What we'll do is just maintain a set with all the u and update when some hi got deleted
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    multiset<int> hv;
    multiset<int> u;
    hv.insert(1e9);
    for (int i = 1; i <= N; i++)
    {
        cin >> h[i] >> v[i];
        pq.push(pii{h[i], i});
        hv.insert(h[i] + v[i]);
    }
    for (int i = 1; i <= N; i++)
    {
        while(!pq.empty() && pq.top().F < *hv.begin())
        {
            u.insert(pq.top().S);
            pq.pop();
        }
        int cur = *u.begin();
        u.erase(u.begin());
        cout << cur << " \n"[i == N];
        hv.erase(hv.find(h[cur] + v[cur]));
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}
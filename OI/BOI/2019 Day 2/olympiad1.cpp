#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, K, C;
pii arr[505];
vector<int> v;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K >> C;
    assert(K <= 2);
    if(K == 1)
        for (int i = 1; i <= N; i++)
            cin >> arr[i].F;
    else
        for (int i = 1; i <= N; i++)
            cin >> arr[i].F >> arr[i].S;
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N;j++)
            v.emplace_back(max(arr[i].F, arr[j].F) + max(arr[i].S, arr[j].S));
    sort(v.begin(), v.end() ,greater<int>());
    cout << v[C - 1] << '\n';
}
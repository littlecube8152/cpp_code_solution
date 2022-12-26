#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, ans[505];
vector<int> pre[505];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        pre[i].resize(N + 1);
        for (int j = 1; j <= N; j++)
            cin >> pre[i][j];
    }
    vector<int> v = {0};
    for (int i = 1; i <= N; i++)
    {
        ans[i] = i;
        v.emplace_back(i);
    }
    for (int i = 1; i <= N; i++)
    {
    }
}

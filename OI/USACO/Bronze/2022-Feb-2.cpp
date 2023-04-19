#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, a[100005], b[100005], vis[100005] ,ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    int j = 1;
    for (int i = 1; i <= N; i++)
    {
        cin >> b[i];
        while(vis[a[j]])
            j++;
        if(a[j] != b[i])
            ans++;
        vis[b[i]] = 1;
    }
    cout << ans << '\n';
}
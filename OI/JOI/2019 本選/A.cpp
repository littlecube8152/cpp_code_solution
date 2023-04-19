#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int H, W;
ll ans;
char c[3005][3005];
int O[3005][3005], I[3005][3005];

signed main()
{
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> c[i][j];
    for (int i = 1; i <= H; i++)
        for (int j = W; j >= 1; j--)
            O[i][j] = O[i][j + 1] + (c[i][j] == 'O');
    for (int i = H; i >= 1; i--)
        for (int j = 1; j <= W; j++)
            I[i][j] = I[i + 1][j] + (c[i][j] == 'I');
    
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            if(c[i][j] == 'J')
                ans += I[i][j] * O[i][j];
    cout << ans << '\n';
}
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

ll N, M, K;
string s[4105];
bitset<4105> b[4105];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        cin >> s[i];
    if (N <= 100)
    {
        for (int i = 1; i <= N; i++)
        {
            bool valid = true;
            for (int j = 1; j <= N; j++)
                if (j != i)
                {
                    int cnt = 0;
                    for (int k = 0; k < M; k++)
                        cnt += (s[i][k] != s[j][k]);
                    if (cnt != K)
                        valid = false;
                }
            if (valid)
                cout << i << '\n';
        }
    }
    else
    {
        for (int i = 1; i <= N; i++)
            for (int j = 0; j < M; j++)
                b[i][j] = (s[i][j] == 'A');
        for (int i = 1; i <= N; i++)
        {
            bool valid = true;
            for (int j = 1; j <= N; j++)
                if (j != i)
                {
                    int cnt = (b[i] ^ b[j]).count();
                    if (cnt != K)
                        valid = false;
                }
            if (valid)
                cout << i << '\n';
        }
        
    }
}
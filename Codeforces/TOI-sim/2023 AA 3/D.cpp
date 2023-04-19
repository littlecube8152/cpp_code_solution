#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, M;
char c[5005][5005];
pii range[5005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> M;
    pii ji = pii(0, M + 1), jx = pii(0, 0);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '#')
            {
                if (j < ji.S)
                    ji = pii(i, j);
                if (j > jx.S)
                    jx = pii(i, j);
            }
        }

    range[0] = range[N + 1] = pii(M + 1, 0);

    for (int i = 1; i <= ji.F; i++)
    {
        range[i].F = range[i - 1].F;
        for (int j = 1; j <= range[i].F; j++)
            if (c[i][j] == '#')
            {
                range[i].F = j;
                break;
            }
    }
    for (int i = N; i >= ji.F; i--)
    {
        range[i].F = range[i + 1].F;
        for (int j = 1; j <= range[i].F; j++)
            if (c[i][j] == '#')
            {
                range[i].F = j;
                break;
            }
    }

    for (int i = 1; i <= jx.F; i++)
    {
        range[i].S = range[i - 1].S;
        for (int j = M; j >= range[i].S; j--)
            if (c[i][j] == '#')
            {
                range[i].S = j;
                break;
            }
    }
    for (int i = N; i >= jx.F; i--)
    {
        range[i].S = range[i + 1].S;
        for (int j = M; j >= range[i].S; j--)
            if (c[i][j] == '#')
            {
                range[i].S = j;
                break;
            }
    }
    for (int i = min(ji.F, jx.F); i <= max(ji.F, jx.F); i++)
        if(range[i].F > range[i].S)
            range[i].F = range[i].S;
    for (int i = 1; i <= N; i++)
    {
        // cout << range[i].F << ' ' << range[i].S << '\n';
        if (range[i].F > range[i].S)
            continue;
        if (range[i + 1].F <= range[i + 1].S)
        {
            if (range[i].S <= range[i + 1].F)
                range[i].S = range[i + 1].F;
            if (range[i + 1].S <= range[i].F)
                range[i].F = range[i + 1].S;
        }
        for (int j = range[i].F; j <= range[i].S; j++)
            c[i][j] = '#';
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cout << c[i][j];
        cout << '\n';
    }
}
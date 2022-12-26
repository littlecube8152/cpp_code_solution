#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

int N, cnt;
const int B = 13;
char c[4005][4005];
bool sw[4005];
int l[4005], r[4005];

void draw(int i, int j)
{
    if (c[i][j] == '.')
        c[i][j] = 'O', cnt++;
}

// ...P.. x1 y1
// ...O..
// POOOOP x2 y2

void connect(int x1, int y1, int x2, int y2)
{
    // cerr << "connect " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    for (int i = x1; i <= x2; i++)
        draw(i, y1);
    for (int i = min(y1, y2); i <= max(y1, y2); i++)
        draw(x2, i);
}

deque<pii> dq[400];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> c[i][j];
    if (N <= 200)
    {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                draw(i, j);
        goto output;
    }

    for (int i = 1; i <= N; i++)
        draw(1, i);
    for (int i = 1; i <= N; i++)
        for (int j = B / 2 + 1; j <= N; j += B)
        {
            draw(i, j);
            sw[j] = 1;
        }
    l[1] = -1e9, r[N] = 1e9;
    for (int i = 2; i <= N; i++)
        if (sw[i])
            l[i] = i;
        else
            l[i] = l[i - 1];

    for (int i = N - 1; i >= 1; i--)
        if (sw[i])
            r[i] = i;
        else
            r[i] = r[i + 1];

    for (int i = 2; i <= N; i++)
        for (int j = 1, k = 1; j <= N; j++)
            if (sw[j])
                k++;
            else if(c[i][j] == 'P')
            {
                int m = min(j - l[j], r[j] - j);
                for (auto [x, y] : dq[k])
                    m = min(m, abs(i - x) + abs(j - y));
                if (m == j - l[j])
                    connect(i, j, i, l[j]);
                else if (m == r[j] - j)
                    connect(i, j, i, r[j]);
                else
                    for (auto [x, y] : dq[k])
                        if (m == abs(i - x) + abs(j - y))
                        {
                            connect(x, y, i, j);
                            break;
                        }
                dq[k].push_back(pii(i, j));
                if (dq[k].size() >= 10)
                    dq[k].pop_front();
            }

output:
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << c[i][j];
        cout << '\n';
    }
    cerr << cnt << '\n';
}
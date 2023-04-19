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

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    srand(time(0));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            c[i][j] = '.';
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (rand() % 75 == 0 && cnt < 200000)
                c[i][j] = 'P', cnt++;
    c[1][1] = 'X';
    cout << N << '\n';
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << c[i][j];
        cout << '\n';
    }
}
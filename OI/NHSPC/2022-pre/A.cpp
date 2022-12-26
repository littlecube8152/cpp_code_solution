#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N;
double L, w[300005];

signed main()
{
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
        cin >> w[i];
    sort(w + 1, w + 1 + N);
    double len = 0, sumW = 0, sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sumW += w[i];
        sum -= w[i] * L / 2.0;
        // add * sumW + sum = 0
        double add = -sum / sumW;
        len += add;
        sum += sumW * add;
    }
    cout << fixed << setprecision(10) << len << '\n';
}
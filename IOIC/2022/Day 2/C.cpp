#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N;
double a[100005], b[100005], ans;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
    {
        cin >> b[i];
        b[i] = 1.0 / b[i];
    }
    sort(a + 1, a + 1 + N);
    sort(b + 1, b + 1 + N);
    for (int i = 1; i <= N; i++)
        ans += a[i] * b[i];
    cout << fixed << setprecision(10) << ans << '\n';
}
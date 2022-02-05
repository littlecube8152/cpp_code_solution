#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const ll C = 1e6;
ll primecnt[C + 1] = {0, 0};
ll p[C + 1], ans[100];
ll N, K;

int main()
{
    for (ll i = 2; i <= C; i++)
    {
        if (primecnt[i] == 0)
            for (ll j = i; j <= C; j += i)
            {
                primecnt[j]++;
                if (j % (i * i) == 0)
                    primecnt[j] = -1e7;
            }
    }
    for (int i = 1; i <= C; i++)
    {
        if (primecnt[i] <= 0)
            primecnt[i] = 0;
        else
            primecnt[i] = (primecnt[i] % 2 == 0 ? -1 : 1);
    }
    for (int i = 1; i <= C; i++)
        p[i] = i;
    cin >> N >> K;
    ans[1] = N - 1;
    for (int i = 2; i <= 40; i++)
        for (int j = 1; j <= C; j++)
        {
            if (pow(j, i) >= 1e16)
                break;
            p[j] *= j;
            ans[i] += (N / p[j]) * primecnt[j];
        }
    for (int i = 1; i < 40; i++)
        ans[i] -= ans[i + 1];
    for (int i = 1; i <= K; i++)
        if (i >= 40)
            cout << 0 << " \n"[i == K];
        else
            cout << ans[i] << " \n"[i == K];
}

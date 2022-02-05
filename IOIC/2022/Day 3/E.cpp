#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int prime[1000005] = {1, 1};
const int C = 1e6;
int Q, N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 2; i <= sqrt(C); i++)
        if (!prime[i])
            for (int j = i * i; j <= C; j += i)
                prime[j] = 1;
    for (int i = 0; i <= C; i++)
        prime[i] ^= 1;
    for (int i = 1; i <= C; i++)
        prime[i] += prime[i - 1];
    cin >> Q;
    while (Q--)
    {
        cin >> N;
        cout << prime[N] - prime[N / 2] << '\n';
    }
}
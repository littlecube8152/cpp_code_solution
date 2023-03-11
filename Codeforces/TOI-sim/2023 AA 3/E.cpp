#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, a[400005], r[400005];
int ans1, ans2;
vector<int> sol1, sol2;

int par(int i)
{
    return (i % 2 == 0 ? i - 1 : i + 1);
}

void output(vector<int> sol)
{
    for (int i = 1; i <= 2 * N; i++)
        cout << sol[i] << " \n"[i == 2 * N];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= 2 * N; i++)
        cin >> a[i];
    a[0] = a[2 * N];

    sol1.resize(2 * N + 1);
    for (int i = 1; i <= 2 * N; i++)
        r[a[i]] = i;
    for (int i = 1; i <= N; i++)
        if (sol1[2 * i - 1] == 0)
        {
            if ((a[2 * i - 1] % 2 == 0 && a[2 * i] == a[2 * i - 1] - 1) ||
                (a[2 * i] % 2 == 0 && a[2 * i - 1] == a[2 * i] - 1))
            {
                ans1++;
                sol1[2 * i - 1] = a[2 * i - 1];
                sol1[2 * i] = a[2 * i];
            }
            else
            {
                sol1[2 * i - 1] = min(a[2 * i - 1], par(a[2 * i]));
                sol1[2 * i] = par(sol1[2 * i - 1]);
                int j;
                if (sol1[2 * i - 1] == a[2 * i - 1])
                    j = par(sol1[2 * i - 1]);
                else
                    j = par(sol1[2 * i]);
                while (sol1[r[j]] == 0)
                {
                    sol1[par(r[j])] = a[par(r[j])];
                    sol1[r[j]] = par(sol1[par(r[j])]);
                    j = par(sol1[par(r[j])]);
                }
            }
        }

    sol2.resize(2 * N + 1);
    for (int i = 0; i < 2 * N; i++)
        r[a[i]] = i;
    for (int i = 0; i < N; i++)
        if (sol2[2 * i] == 0)
        {
            if ((a[2 * i + 1] % 2 == 0 && a[2 * i] == a[2 * i + 1] - 1) ||
                (a[2 * i] % 2 == 0 && a[2 * i + 1] == a[2 * i] - 1))
            {
                ans2++;
                sol2[2 * i + 1] = a[2 * i + 1];
                sol2[2 * i] = a[2 * i];
            }
            else
            {
                if (i == 0)
                {
                    sol2[2 * i + 1] = min(a[2 * i + 1], par(a[2 * i]));
                    sol2[2 * i] = par(sol2[2 * i + 1]);
                }
                else
                {
                    sol2[2 * i] = min(a[2 * i], par(a[2 * i + 1]));
                    sol2[2 * i + 1] = par(sol2[2 * i]);
                }
                int j;
                if (sol2[2 * i + 1] == a[2 * i + 1])
                    j = par(sol2[2 * i + 1]);
                else
                    j = par(sol2[2 * i]);
                while (sol2[r[j]] == 0)
                {
                    sol2[par(r[j] + 1) - 1] = a[par(r[j] + 1) - 1];
                    sol2[r[j]] = par(sol2[par(r[j] + 1) - 1]);
                    j = par(sol2[par(r[j] + 1) - 1]);
                }
            }
        }
    swap(sol2[0], sol2[2 * N]);
    
    if(ans1 > ans2)
        output(sol1);
    if(ans1 < ans2)
        output(sol2);
    if(ans1 == ans2)
        output(min(sol1, sol2));
}
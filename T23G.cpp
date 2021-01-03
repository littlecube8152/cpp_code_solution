#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

struct node
{
    int n = 0;
    int c = 0;
    ll b = 0;
};

int n, m, a[20], p = 0;

bool comp(int a, int b)
{
    return a > b;
}
bool dfs(node state)
{
    //cout << "TRY " << state.n << " person  " << state.c << " current  state " << state.b << '\n';
    if (state.n == n && state.c == 0 && state.b == pow(2, m) - 1)
        return 1;
    else if (state.n == n || state.c > p)
        return 0;
    else
        for (int i = 0; i < m; i++)
            if ((state.b & (1 << i)) == 0)
            {

                node next_state;
                next_state.c = state.c + a[i];
                if (next_state.c == p)
                {
                    next_state.c = 0;
                    next_state.n = state.n + 1;
                }
                else if (next_state.c < p)
                    next_state.n = state.n;

                next_state.b = state.b | (1 << i);

                if (state.n == n && state.c == 0 && state.b == pow(2, m) - 1)
                    return 1;
                else if (state.n < n || state.c < p)
                    if (dfs(next_state))
                        return 1;
                if (state.c == 0)
                    break;
            }

    return 0;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        p += a[i];
    }

    if(n > m){
        cout << "no\n";
        return 0;
    }

    if (p % n)
    {
        cout << "no\n";
        return 0;
    }

    p /= n;

    sort(a, a + m, comp);
    if (a[0] > p)
    {
        cout << "no\n";
        return 0;
    }



    node init;
    if (dfs(init))
        cout << "yes\n";
    else
        cout << "no\n";
}
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n, a[5005], undo[5005], active[5005];
set<pii> st;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    active[0] = 1;
    cin >> n;
    if (n <= 5000)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            active[i] = 1;
            if (a[i] < 0)
            {
                int cur = i;
                for (int j = i - 1; j >= 1; j--)
                    if (active[j] && min(0, a[j]) > a[cur])
                    {
                        // cerr << cur << " undo " << j << '\n';
                        undo[cur] = j;
                        active[j] ^= 1;
                        cur = j;
                        if (!undo[cur])
                            break;
                        // cerr << cur << " redo " << undo[cur] << '\n';
                        active[undo[cur]] ^= 1;
                        cur = undo[cur];
                    }
            }
            for (int j = 1; j <= i; j++)
                cout << active[j] << " \n"[j == i];
            for (int j = 1; j <= i; j++)
                cout << undo[j] << " \n"[j == i];
            for (int j = i; j >= 0; j--)
                if (active[j] && a[j] >= 0)
                {
                    cout << a[j] << '\n';
                    break;
                }
        }
    }
    else
    {
        vector<int> v = {0};
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            if(a > 0)
                v.emplace_back(a);
            else
                v.pop_back();
            cout << v.back() << '\n';
        }
    }
}
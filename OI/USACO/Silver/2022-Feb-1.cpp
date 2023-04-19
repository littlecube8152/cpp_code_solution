#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, pre[505][505], val[505][505], ans[505];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> pre[i][j];
            val[i][pre[i][j]] = j;
        }
    vector<int> v = {0};
    for (int i = 1; i <= N; i++)
    {
        ans[i] = i;
        v.emplace_back(i);
    }
    do
    {
        bool valid = 1;
        for (int i = 1; i <= N; i++)
            if (val[i][v[i]] > val[i][i])
                valid = 0;
        if (valid)
        {
            for (int i = 1; i <= N; i++)
                if (val[i][v[i]] <= val[i][ans[i]])
                    ans[i] = v[i];
        }
    } while (next_permutation(v.begin() + 1, v.end()));
    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
}

/*
3
_   .
3 2 1
_ .
1 2 3
_ .
2 3 1

*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, pre[505][505], val[505][505], Tans[505], ans[505];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 100;
    cin >> N;
    while (T--)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
                pre[i][j] = j;
            random_shuffle(pre[i] + 1, pre[i] + 1 + N);
            for (int j = 1; j <= N; j++)
                val[i][pre[i][j]] = j;
        }
        vector<int> v = {0};
        for (int i = 1; i <= N; i++)
        {
            Tans[i] = i;
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
                    if (val[i][v[i]] <= val[i][Tans[i]])
                        Tans[i] = v[i];
            }
        } while (next_permutation(v.begin() + 1, v.end()));
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                int te = 0;
                for (int k = 1; k <= N; k++)
                    if (k != i)
                    {
                        if (val[k][k] - (val[k][pre[i][j]] <= val[k][k]) == 0)
                            te = -1e9;
                    }
                if (te >= 0)
                {
                    ans[i] = pre[i][j];
                    break;
                }
            }

        for (int i = 1; i <= N; i++)
            if (ans[i] != Tans[i])
            {
                cout << "counter test found\n";
                cout << N << '\n';
                for (int i = 1; i <= N; i++)
                    for (int j = 1; j <= N; j++)
                        cout << pre[i][j] << " \n"[j == N];
                cout << "Ans:\n";
                for (int i = 1; i <= N; i++)
                    cout << Tans[i] << " \n"[i == N];
                cout << "Output:\n";
                for (int i = 1; i <= N; i++)
                    cout << ans[i] << " \n"[i == N];
                return 0;
            }
    }
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
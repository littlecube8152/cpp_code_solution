// subtask 1, 2

#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define int long long
using namespace std;

ll N, arr[505], ans = 0;
tuple<int, int, int> best = tie(1, 2, 3);

signed main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (ll i = 1; i <= N; i++)
        for (ll j = i + 1; j <= N; j++)
            for (ll k = j + 1; k <= N; k++)
                if (abs(((arr[j] + arr[i]) * (j - i) + (arr[k] + arr[j]) * (k - j)) - (arr[k] + arr[i]) * (k - i)) > ans)
                    ans = abs(((arr[j] + arr[i]) * (j - i) + (arr[k] + arr[j]) * (k - j)) - (arr[k] + arr[i]) * (k - i)), best = tie(i, j, k);
                else if (abs(((arr[j] + arr[i]) * (j - i) + (arr[k] + arr[j]) * (k - j)) - ((arr[k] + arr[i]) * (k - i))) == ans && best > tie(i, j, k))
                    best = tie(i, j, k);
    assert(ans > 0);
    cout << ans << '\n';
    cout << get<0>(best) << ' ' << get<1>(best) << ' ' << get<2>(best) << '\n';
}

/*
10
-10000000000 -40000000000 00000000006 -10000000000 -30000000000 0 80000000000 -80000000000 -90000000000 -80000000000

*/
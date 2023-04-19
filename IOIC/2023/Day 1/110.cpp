#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, ans[1 << 16];

signed main()
{
    // given that
    // f(x) = (x - a_1)(x - a_2)...(x - a_n)
    // then
    //   f(x + k) - f(x)
    // = (x + k - a_1)(x + k - a_2)...(x + k - a_n) - (x - a_1)(x - a_2)...(x - a_n)
    // = (\sum_{S \subseteq {a_1, a_2, ..., a_n}}k^(n - |S|)\prod_{a \in S}(x - a)) - (x - a_1)(x - a_2)...(x - a_n)
    // = \sum_{S \subsetneq {a_1, a_2, ..., a_n}}k^(n - |S|)\prod_{a \in S}(x - a)
    // observe that using same k each time and differentiate N + 1 times yields 0
    
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    int i = 0;
    ans[i] = 1;
    for (; i <= N; i++)
        for (int j = (1 << i) - 1; j >= 0; j--)
            ans[j << 1 | 1] = ans[j] ^ 3, ans[j << 1] = ans[j];
    cout << "YES\n";
    for (int j = 0; j < (1 << i); j++)
        cout << ans[j] << " \n"[j == (1 << i) - 1];
}
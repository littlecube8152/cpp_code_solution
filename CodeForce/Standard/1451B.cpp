#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int l, q;
        cin >> l >> q >> s;
        while (q--)
        {
            int st, en, ls, e[100][100] = {{0}};
            cin >> st >> en;
            ls = en - st + 1;
            string ss = s.substr(st - 1, en - 1);

            for (int i = 0; i < l; i++)
                for (int j = 0; j < ls; j++)
                    if (s[i] == ss[j])
                        e[i][j] = 1;
            for (int i = 1; i < l; i++)
                for (int j = 1; j < ls; j++)
                    for (int k = 0; k < 2; k++)
                    
        }
    }
}

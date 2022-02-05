#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

string b, m;

signed main()
{
    int T, C, B, M;
    cin >> T;
    cin >> B >> M;
    if (T == 0)
    {
        int k = 0;
        while (cin >> C)
        {
            if (C == 0)
                break;
            cin >> b >> m;
            bool is1 = true;
            for (int i = 0; i < M; i++)
                if (m[i] != '1')
                    is1 = false;
            if(is1)
            {
                cout << 0 << endl;
                continue;
            }
            for (int i = 0; i < B / M; i++)
            {
                bool is_empty = true;
                for (int j = i * M; j < B; j++)
                    if (b[j] != '0')
                        is_empty = 0;
                if (is_empty)
                {
                    cout << 1 << '\n'
                         << string(i * M, '1') << m << string(B - M - i * M, '0') << endl;
                    goto next;
                }
                    }
            cout << 0 << endl;
        next:
            if (1)
            {
            };
        }
    }
    else if (T == 1)
    {
        while (cin >> C)
        {
            if (C == 0)
                break;
            cin >> b;
            for (int i = 0; i < B / M; i++)
            {
                bool empty = true;
                for (int j = i * M; j < (i + 1) * M; j++)
                    if (b[j] == '0')
                        empty = 0;
                if (!empty)
                {
                    for (int j = i * M; j < (i + 1) * M; j++)
                        cout << b[j];
                    break;
                }
            }
            cout << endl;
        }
    }
}
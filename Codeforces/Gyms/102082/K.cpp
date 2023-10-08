#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int n, p[5005], f[5005], beat[5005], sw[5005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> f[i];
    sort(f + 1, f + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        vector<pii> a, b;
        for (int j = 1; j <= n; j++)
            beat[j] = -1, sw[j] = 0;
        for (int j = i + 1; j <= n; j++)
            a.emplace_back(pii(p[j], j));
        for (int j = 1; j <= n; j++)
            if (f[j] > 0)
                b.emplace_back(pii(f[j], j));
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int k = 0;
        for (int j = 0; j < b.size(); j++)
        {
            beat[j] = -1;
            if (k < a.size() && b[j].F > a[k].F)
                beat[j] = k, k++;
        }
        if(beat[(int)b.size() - 1] == -1)
            sw[(int)b.size() - 1] = 1;
        for (int j = (int)b.size() - 2; j >= 0; j--)
        {
            if (beat[j + 1] == -1 || beat[j] == -1 || sw[j + 1])
                sw[j] = 1;
        }
        int id = -1, w = 0;
        for (int j = 0; j < b.size(); j++)
            if (sw[j] && b[j].F > p[i])
            {
                if (b[j].F > w)
                    w = b[j].F, id = b[j].S;
            }
        if (id == -1)
        {
            for (int j = 0; j < b.size(); j++)
                if ((b[j].F > p[i]) || sw[j])
                {
                    if (b[j].F > w)
                        w = b[j].F, id = b[j].S;
                }
        }

        if (id == -1)
        {
            for (int j = 0; j < b.size(); j++)
            {
                if (b[j].F > w)
                    w = b[j].F, id = b[j].S;
            }
        }
        f[id] = 0;
        cout << w << " \n"[i == n];
    }
}
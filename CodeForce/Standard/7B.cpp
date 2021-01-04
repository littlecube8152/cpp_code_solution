#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t, m, id = 0;
    vector<int> mem(100, 0);
    cin >> t >> m;
    while (t--)
    {
        string s;
        int p;
        bool r = false;
        cin >> s >> p;
        if (s == "alloc")
        {
            for (int i = 0; i <= m - p; i++)
            {
                bool b = true;
                for (int j = i; j < i + p; j++)
                    if (mem[j] != 0)
                        b = false;

                if (b)
                {
                    r = true;
                    id++;
                    cout << id << '\n';
                    for (int j = i; j < i + p; j++)
                        mem[j] = id;
                    break;
                }
            }
            if (!r)
                cout << "NULL\n";
        }
        else if (s == "erase")
        {
            for (int i = 0; i < m; i++)
                if (mem[i] == p)
                {
                    r = true;
                    mem[i] = 0;
                }
            if (!r)
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
        }
        else if (s == "defragment")
        {
            for (int i = 0; i < m; i++)
                mem[i] = 0;
        }
    }
    return 0;
}
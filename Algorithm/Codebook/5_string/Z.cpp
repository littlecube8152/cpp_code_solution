
#include <bits/stdc++.h>
using namespace std;
int Z[1000006];

void z(string s)
{
    for (int i = 1, mx = 0; i < s.size(); i++)
    {
        if (i < Z[mx] + mx)
            Z[i] = min(Z[mx] - i + mx, Z[i - mx]);
        while (Z[i] + i < s.size() && s[i + Z[i]] == s[Z[i]])
            Z[i]++;
        if (Z[i] + i > Z[mx] + mx)
            mx = i;
    }
}

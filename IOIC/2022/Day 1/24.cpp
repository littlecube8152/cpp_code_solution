#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")

#include "lib0024.h"

int main()
{
    for (int i = 1; i <= 8; i++)
        if (check_length(i))
        {
            char c[8];
            for (int j = 0; j < i; j++)
                for (int k = 'a'; k <= 'z'; k++)
                    if (check_position(j, (char)k))
                    {
                        c[j] = k;
                        break;
                    }
            string s;
            for (int j = 0; j < i; j++)
                s += c[j];
            report(s);
            return 0;
        }
}
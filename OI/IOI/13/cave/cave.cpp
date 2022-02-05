/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
//#pragma GCC optimize("O3,unroll-loops")
#include "cave.h"

int n, comb[5005], match[5005], attempt[5005], S[5005], D[5005];

int bs(int l, int r, int i, int state)
{
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    for (int j = 0; j < l; j++)
        if (comb[j] != -1)
            attempt[j] = comb[j];
    for (int j = l; j <= mid; j++)
        if (comb[j] == -1)
            attempt[j] = state;
        else
            attempt[j] = comb[j];
    for (int j = mid + 1; j <= r; j++)
        if (comb[j] == -1)
            attempt[j] = state ^ 1;
        else
            attempt[j] = comb[j];
    for (int j = r + 1; j < n; j++)
        if (comb[j] != -1)
            attempt[j] = comb[j];
    int verdict = tryCombination(attempt);
    if (verdict == i)
        return bs(mid + 1, r, i, state);
    else
        return bs(l, mid, i, state);
}

void exploreCave(int N)
{
    n = N;
    for (int i = 0; i < n; i++)
        match[i] = comb[i] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (comb[j] == -1)
                attempt[j] = 0;
            else
                attempt[j] = comb[j];
                
        int verdict = tryCombination(attempt), state, pos;
        if (verdict == i)
            state = 1;
        else
            state = 0;
        pos = bs(0, n - 1, i, state);
        //cerr << i << "->" << pos << ":" << state << '\n';
        comb[pos] = state;
        match[pos] = i;
    }
    for (int i = 0; i < n; i++)
        S[i] = comb[i], D[i] = match[i];
    answer(S, D);
}

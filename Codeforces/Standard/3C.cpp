#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    char p[9];
    int pi[9] = {0}, rc[8] = {0}, round = 0, Owin = 0, Xwin = 0, play = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> p[i];
        if (p[i] == 'X')
        {
            pi[i] = 1;
            round++;
            play++;
        }
        if (p[i] == '0')
        {
            pi[i] = -1;
            round--;
            play++;
        }
    }
    rc[0] = pi[0] + pi[1] + pi[2];
    rc[1] = pi[3] + pi[4] + pi[5];
    rc[2] = pi[6] + pi[7] + pi[8];
    rc[3] = pi[0] + pi[3] + pi[6];
    rc[4] = pi[1] + pi[4] + pi[7];
    rc[5] = pi[2] + pi[5] + pi[8];
    rc[6] = pi[0] + pi[4] + pi[8];
    rc[7] = pi[2] + pi[4] + pi[6];
    for (int i = 0; i < 8; i++)
    {
        if (rc[i] == -3)
            Owin++;
        if (rc[i] == 3)
            Xwin++;
    }
    if ((round != 1 && round != 0) || (Owin != 0 && Xwin != 0))
        cout <<"illegal\n";
    else if (Owin)
        cout << "the second player won\n";
    else if (Xwin)
        cout << "the first player won\n";
    else if (play == 9)
        cout << "draw\n";
    else if (round)
        cout << "second\n";
    else
        cout << "first\n";
}
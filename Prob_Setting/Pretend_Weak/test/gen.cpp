#include <bits/stdc++.h>
using namespace std;


int nmax, nmin, amax, amin, id;

/*
Test Data Generator

0 3 7 30 70
1 10 25 10 30
2 1 1 0 0
3 100000 150000 0 100
4 200000 200000 0 100
5 200000 200000 80 100
*/

int r(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

signed main()
{
    srand(time(NULL));

    cout << "ID, Nmin, Nmax, Amin, Amax\n";
    while (cin >> id >> nmin >> nmax >> amin >> amax)
    {
        int n = 0, sum = 0;
        ofstream in, out;
        in.open(to_string(id) + ".in");
        out.open(to_string(id) + ".out");
        //ofstream cout("D:\\Programming\\C++\\CodeForce\\Standard\\test.txt");
        n = r(nmin, nmax);
        in << n << '\n';

        if (n == 1)
        {
            out << 0 << '\n';
            continue;
        }

        for (int i = 1; i <= n - 1; i++)
        {
            int x = r(amin, amax);
            in << x << " \n"[i == n - 1];
            sum += x;
        }
        out << (sum + n - 2) / (n - 1) << '\n'; //取頂;}
    }
}
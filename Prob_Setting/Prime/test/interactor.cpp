#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    setName("Interactor Prime");
    registerInteraction(argc, argv);

    // reads number of queries from test input file
    int n = inf.readInt(), a, i = 0;
    string s;
    for (; i <= 101; i++)
    {
        // reads query from contestant input
        s = ouf.readString();
        a = ouf.readInt();

        if (s == "!")
            break;
        else if (s == "?" && i != 101)
        {
            // writes the ans of the query
            if (n % a)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }

        // writes interactor output file to be verified by checker later
        tout << n << " " << a << endl;
    }
    if (s == "!")
    {
        if (a == n)
        {
            if (i <= 30)
                quitf(_ok, "%d query proccessed", i);
            else if (i <= 50)
                quitf(_pc(40 + (50 - i) * 2), "%d query proccessed", i);
            else
                quitf(_pc((100 - i + 1) / 2), "%d query proccessed", i);
        }
        else
            quitf(_wa, "%d query proccessed", i);
    }
    else quitf(_wa, "too much query or didn't answer");
}
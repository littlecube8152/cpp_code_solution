#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    int n = inf.readInt(1, 200000, "n");
    inf.readEoln();

    for (int i = 1; i <= n - 1; i++)
    {

        inf.readInt(0, 100, "ai");
        if (i != n - 1)
            inf.readSpace();
        else
        {
            inf.readEoln();
    		inf.readEof();	
		}
    }

}

#include <bits/stdc++.h>
using namespace std;

const int linemx = 103;
int cnt = 0, n;
char c;
int main()
{
    ifstream cin("encode.txt");
    //ofstream cout("out.txt");
    
    while(scanf("%d", &n))
    {
        cout << n << '\n';
        c = getchar();
        cout << n << c << '\n';
        for (int i = 1; i <= n; i++, cnt++)
        {
            if(linemx == cnt)
            {
                cout << endl;
                cnt = 0;
            }
            cout << c;
            
        }
        c = getchar();
    }

}
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    string a, b;
    long int n, k;
    cin >> a >> b >> n >> k;
    vector<string> article = {"", a, b};

    for (long int i = 3; i <= n && article[2].length() <= k; i++)
    {
        article[0] = article[1];
        article[1] = article[2];
        article[2] = (article[0] + article[1]);
    }

    if(n == 1){
        article[2] = a;
    }

    if (article[2].length() < k)
    {
        cout << "X\n";
    }
    else
    {
        cout << article[2][k-1] << '\n' ;
    }
}
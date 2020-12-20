#include <cstring>
#include <iostream>
using namespace std;
int v[101], w[101], k[1001];
int ks, n;
int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> w[i] >> v[i];
        }
        cin >> ks;
        memset(k, 0, sizeof(k));
        cout << "STAT  k  j  i  v\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = ks; j >= w[i]; j--)
            {
                if (k[j - w[i]] + v[i] > k[j])
                {

                    k[j] = k[j - w[i]] + v[i];
                    cout << "EDIT " << k[j] << ", " << j << ", " << i << ", " << w[i] <<"\n";
                }
            }
        }
        cout << "MAX  " << k[ks] << endl;
    }
}
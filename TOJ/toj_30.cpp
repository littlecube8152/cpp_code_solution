#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int prime[1000005], n;

int main()
{
    fast;

    for (int i = 3; i < 1000005; i += 2)
        prime[i] = 1;
    prime[2] = 1;
    //Main Program
    for (int i = 3; i < sqrt(1000005); i += 2)
        if (prime[i])
            for (int j = i * 3; j < 1000005; j += i * 2)
                prime[j] = 0;
    for (int i = 1; i < 1000005; i++)
        prime[i] += prime[i-1];
    while(cin >> n)
        cout << prime[n] << '\n';
}
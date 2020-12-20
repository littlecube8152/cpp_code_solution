#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, m[105], odd = 0, even = 0;
    cin >> n;
    for (int i = 0; i < n ;i++){
        cin >> m[i];
        m[i] %= 2;
    }
    for (int i = 0; i < n ;i++){
        if(m[i] == 1)
            odd = i;
        if(m[i] == 0)
            even = i;    
    }
    cout << min(odd, even) + 1 << '\n';
    
}
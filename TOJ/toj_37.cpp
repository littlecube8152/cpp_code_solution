#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{

string s;
    while (getline(cin, s))
    {
        stringstream ss;
        ss << s;
        int result = 0, tmp;
        while(ss >> tmp)
            result++;
        cout << result << '\n';
    }
}
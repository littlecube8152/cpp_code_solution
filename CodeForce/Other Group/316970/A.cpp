#include <bits/stdc++.h>
using namespace std;

long long fastpow(int n)
{
    if (n == 0)
        return 1;
    if (n % 2)
        return (2 * fastpow(n - 1)) % 1000000007;
    long long half = fastpow(n / 2);
    return (half * half) % 1000000007;
}

signed main()
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        long long i = 0, inv = 0;
        long long val = 0;
        for (; i < s.length(); i++)
            if (s[i] == '1')
                break;

        for (int j = i; j < s.length(); j++)
        {

            if (inv % 2 == 0 && s[j] == '1')
                val = (val + fastpow(s.length() - 1 - j)) % 1000000007;
            else if (inv % 2 && s[j] == '0')
                val = (val + fastpow(s.length() - 1 - j)) % 1000000007;
        
            if (s[j] == '1')
                inv++;
        }
        cout << val << '\n';
    }
}
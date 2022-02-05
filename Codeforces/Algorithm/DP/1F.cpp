#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string least(map<char, int> A)
{
    string a;
    for (auto i : A)
        for (int j = 1; j <= i.second; j++)
            a += i.first;
    return a;
}

int main()
{
    string a, b;
    map<char, int> A, B;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        A[a[i]]++;

    if (a.length() < b.length())
    {
        for (char i = '9'; i >= '0'; i--)
            cout << string(A[i], i);
        return 0;
    }

    a = "";

    int i = 0;
    for (; i < b.length(); i++)
    {
        bool sw = (A[b[i]] > 0);
        if (sw)
        {
            A[b[i]]--;
            if (a + b[i] + least(A) <= b)
                a += b[i];
            else
            {
                A[b[i]]++;
                sw = 0;
            }
        }

        if (!sw)
        {
            for (char j = b[i] - 1; j >= '0'; j--)
                if (A[j])
                {
                    a += j;
                    A[j]--;
                    break;
                }
            break;
        }
    }
    for (char i = '9'; i >= '0'; i--)
        a += string(A[i], i);
    cout << a;
}
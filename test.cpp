#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct bigInt
{
    int_fast8_t value[100000] = {0};
};

bigInt add(bigInt a, bigInt b)
{
    bigInt r;
    for (int i = 0; i < 100000; i++)
        r.value[i] = a.value[i] + b.value[i];
    for (int i = 0; i < 100000; i++)
        if (r.value[i] >= 10)
        {
            r.value[i + 1] += (r.value[i] / 10);
            r.value[i] %= 10;
        }
    return r;
}

const bigInt enptyBigInt;

int main()
{

    vector<bigInt> v = {enptyBigInt};
    fstream file;
    file.open("Triangle.txt", ios::out | ios::trunc);
    int n;
    cin >> n;
    file << "1\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v.size() - 1; j++)
            v[j] = add(v[j], v[j + 1]);
        v[v.size() - 1] = enptyBigInt;
        v[v.size() - 1].value[0] = 1;
        v.insert(v.begin(), enptyBigInt);
        v[0].value[0] = 1;

        for (auto j : v)
        {
            int k = 99999;
            for (; k >= 0; k--)
                if (j.value[k] != 0)
                    break;
            for (; k >= 0; k--)
                file << (int)j.value[k];
            file << " ";
        }
        file << '\n';
    }
}
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct Matrix
{
    ll val[2][2] = {{0}};
    Matrix operator*(Matrix m)
    {
        return Matrix{{{(this->val[0][0] * m.val[0][0] + this->val[0][1] * m.val[1][0]) % MOD,
                        (this->val[0][0] * m.val[0][1] + this->val[0][1] * m.val[1][1]) % MOD},
                       {(this->val[1][0] * m.val[0][0] + this->val[1][1] * m.val[1][0]) % MOD,
                        (this->val[1][0] * m.val[0][1] + this->val[1][1] * m.val[1][1]) % MOD}}};
    }
};

Matrix A;
ll x1, x2, a, b, n;
Matrix fastpow(ll n)
{
    if (n == 1)
        return A;
    if (n % 2)
        return A * fastpow(n - 1);
    Matrix half = fastpow(n / 2);
    return half * half;
}
signed main()
{
    cin >> x1 >> x2 >> a >> b >> n;
    A = Matrix{{{b, a}, {1, 0}}};
    Matrix R = fastpow(n - 2);
    cout << ((R.val[0][0] * x2) % MOD + (R.val[0][1] * x1) % MOD) % MOD << '\n';
}
#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct Matrix
{
    vector<vector<ll>> val = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    Matrix operator*(Matrix m)
    {
        Matrix r;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                for (int k = 0; k < 6; k++)
                    r.val[i][j] =  (r.val[i][j] + this->val[i][k] * m.val[k][j]) % MOD;
        return r;
    }
};

Matrix A;

void Init()
{
    A.val = {{1, 1, 1, 0, 0, 0},
             {1, 0, 0, 0, 0, 0},
             {0, 1, 0, 0, 0, 0},
             {1, 1, 1, 1, 1, 1},
             {0, 0, 0, 1, 0, 0},
             {0, 0, 0, 0, 1, 0}};
}

Matrix fast_pow(ll n)
{
    if (n == 1)
        return A;
    if (n % 2)
        return A * fast_pow(n - 1);
    else
    {
        Matrix r = fast_pow(n >> 1);
        return r * r;
    }
}

int main()
{
    Init();
    fast;
    ll n;
    while (cin >> n)
    {
        if (n == 1)
        {
            cout << "3\n";
            continue;
        }

        Matrix B = fast_pow(n - 1);
        ll b = 0;
        for (auto i : {0, 1, 3})
            for (auto j : {0, 1, 2, 3, 4, 5})
                b = (b + B.val[j][i]) % MOD;
        cout << b << '\n';
    }
}
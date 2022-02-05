#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

template <size_t _Size, long long _Modular = 1000000007>
class matrix
{
private:
    vector<vector<long long>> val;

public:
    matrix<_Size, _Modular>() : val(vector<vector<long long>>(_Size, vector<long long>(_Size, 0))){};
    matrix<_Size, _Modular>(vector<vector<long long>> val) : val(val){};
    vector<long long> operator[](const long long &_pos)
    {
        return val[_pos];
    }

    matrix<_Size, _Modular> operator+(const matrix<_Size, _Modular> &mtx)
    {
        matrix<_Size, _Modular> result;
        for (int i = 0; i < _Size; i++)
            for (int j = 0; j < _Size; j++)
                result.val[i][j] = (val[i][j] + mtx.val[i][j]) % _Modular;
        return result;
    }
    matrix<_Size, _Modular> operator-(const matrix<_Size, _Modular> &mtx)
    {
        matrix<_Size, _Modular> result;
        for (int i = 0; i < _Size; i++)
            for (int j = 0; j < _Size; j++)
                result.val[i][j] = (val[i][j] - mtx.val[i][j]) % _Modular;
        return result;
    }
    matrix<_Size, _Modular> operator*(const matrix<_Size, _Modular> &mtx)
    {
        matrix<_Size, _Modular> result;
        for (int i = 0; i < _Size; i++)
            for (int j = 0; j < _Size; j++)
                for (int k = 0; k < _Size; k++)
                    result.val[i][j] = (result.val[i][j] + val[i][k] * mtx.val[k][j]) % _Modular;
        return result;
    }
    matrix<_Size, _Modular> operator*(const long long &mul)
    {
        long long tmul = mul % _Modular;
        matrix<_Size, _Modular> result;
        for (int i = 0; i < _Size; i++)
            for (int j = 0; j < _Size; j++)
                result.val[i][j] = (val[i][j] * tmul) % _Modular;
        return result;
    }
    matrix<_Size, _Modular> operator=(vector<vector<long long>> &vec)
    {
        for (int i = 0; i < _Size; i++)
            for (int j = 0; j < _Size; j++)
                val[i][j] = vec[i][j] % _Modular;
        return this;
    }
};

matrix<2> fast_pow(matrix<2> mtx, long long pow)
{
    matrix<2> ans = vector<vector<long long>>{{1, 0}, {0, 1}}, m = mtx;
    while (pow)
    {
        if (pow & 1)
            ans = ans * m;
        m = m * m;
        pow >>= 1;
    }
    return ans;
}

int n;

signed main()
{
    fast;
    cin >> n;
    matrix<2> m = vector<vector<long long>>{{1, 1}, {1, 0}};
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    m = fast_pow(m, n - 1);
    cout << (m[0][1] + m[1][1]) % MOD << '\n';
}
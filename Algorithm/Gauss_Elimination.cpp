#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct fraction
{
    ll n, d;
    fraction(const ll &_n = 0, const ll &_d = 1) : n(_n), d(_d)
    {
        ll t = __gcd(n, d);
        n /= t, d /= t;
        if (d < 0)
            n = -n, d = -d;
    }
    fraction operator-() const
    {
        return fraction(-n, d);
    }
    fraction operator+(const fraction &b) const
    {
        return fraction(n * b.d + b.n * d, d * b.d);
    }
    fraction operator-(const fraction &b) const
    {
        return fraction(n * b.d - b.n * d, d * b.d);
    }
    fraction operator*(const fraction &b) const
    {
        return fraction(n * b.n, d * b.d);
    }
    fraction operator/(const fraction &b) const
    {
        return fraction(n * b.d, d * b.n);
    }
    void print()
    {
        cout << n;
        if (d != 1)
            cout << "/" << d;
    }
};

#define MAXN 2000
struct matrix
{ //m variables, n equations
    int n, m;
    fraction M[MAXN][MAXN + 1], sol[MAXN];
    int solve()
    { //-1: inconsistent, >= 0: rank
        for (int i = 0; i < n; ++i)
        {
            int piv = 0;
            while (piv < m && !M[i][piv].n)
                ++piv;
            if (piv == m)
                continue;
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                fraction tmp = -M[j][piv] / M[i][piv];
                for (int k = 0; k <= m; ++k)
                    M[j][k] = tmp * M[i][k] + M[j][k];
                sol[j] = tmp * sol[i] + sol[j];
            }
        }
        int rank = 0;
        //for (int i = 0; i < n; ++i)
        //{
        //    int piv = 0;
        //    while (piv < m && !M[i][piv].n)
        //        ++piv;
        //    if (piv == m && M[i][m].n)
        //        return -1;
        //    else if (piv < m)
        //        ++rank, sol[piv] = M[i][m] / M[i][piv];
        //}
        return rank;
    }
};

int main()
{
    cout << "Line 1: N\n";
    cout << "Line 2 to N + 1: The coeffcient of each variable and the constant in \"a/b\" form\n";
    cout << "Example: \n";
    cout << "   Equation: x + y = 2\n";
    cout << "             x - y = 1/2\n";
    cout << "   Input:    2\n";
    cout << "             1/1 1/1 2/1\n";
    cout << "             1/1 -1/1 1/2\n";
    cout << "   Output:   a_0 = 5/4\n";
    cout << "             a_1 = 3/4\n";
    cout << "Please ensure there is exactly ONE solution to the equation or this program will not function properly.\n";
    int N;
    cin >> N;
    matrix mtx;
    mtx.n = mtx.m = N;
    for (int i = 0; i < N; i++)
    {
        ll n, d;
        for (int j = 0; j < N; j++)
        {
            scanf("%lld/%lld", &n, &d);
            mtx.M[i][j] = fraction(n, d);
        }
        scanf("%lld/%lld", &n, &d);
        mtx.sol[i] = fraction(n, d);
    }
    mtx.solve();
    for (int i = 0; i < N; i++)
    {
        fraction ans = mtx.sol[i] / mtx.M[i][i];
        printf("a_%d = %lld/%lld\n", i, ans.n, ans.d);
    }
}
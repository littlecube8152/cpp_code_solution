#include <bits/stdc++.h>
using namespace std;

struct simplex
{
    const double inf = 1 / .0;
    int n, m = 0;
    double A[205][205], B[205];
    void init(int _n)
    {
        n = _n;
    }
    // ax <= b
    void equation(vector<double> a, double b)
    {
        ++m;
        for (int i = 0; i < n; i++)
            A[m][i] = a[i];
        A[m][n + m] = 1, B[m] = b;
    }
    void print_table()
    {
        for (int j = 0; j <= m; j++)
        {
            for (int i = 0; i <= n + m; i++)
                cout << fixed << setprecision(2) << A[j][i] << ' ';
            cout << "| " << B[j] << '\n';
        }
        cout << '\n';
        char c;
        cin >> c;
    }
    double solve(vector<double> c)
    {
        for (int i = 0; i < n; i++)
            A[0][i] = -c[i];
        A[0][n] = 1;
        print_table();
        bool flag = 1;
        while (flag)
        {
            flag = 0;
            for (int i = 0; i <= n + m; i++)
                if (A[0][i] < 0)
                {
                    flag = 1;
                    double bx = inf;
                    int piv = -1;
                    
                    for (int j = 1; j <= m; j++)
                        if (A[j][i] >= 0 && B[j] / A[j][i] <= bx)
                            piv = j, bx = B[j] / A[j][i];
                    cerr << piv << ' ' << bx << '\n';
                    if (piv == -1) continue;
                    for (int j = 0; j <= m; j++)
                        if (j != piv)
                        {
                            for (int k = 0; k <= n + m; k++)
                                if (k != i)
                                    A[j][k] -= A[piv][k] * A[j][i] / A[piv][i];
                            B[j] -= B[piv] * A[j][i] / A[piv][i];
                            A[j][i] = 0;
                        }
                    print_table();
                }
        }
        return B[0] == inf ? inf : B[0] / A[0][n];
    }
} lp;

int n, m;
double w[55], p[55][55], c[55];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> p[i][j], p[i][j] /= 100.0;
        cin >> c[i];
    }
    lp.init(m);
    for (int j = 1; j <= n; j++)
    {
        vector<double> eq;
        for (int i = 1; i <= m; i++)
            eq.emplace_back(p[i][j]);
        lp.equation(eq, w[j]);
    }
    vector<double> obj;
    for (int i = 1; i <= m; i++)
        obj.emplace_back(c[i]);

    cout << fixed << setprecision(2) << lp.solve(obj) << '\n';
}
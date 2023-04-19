#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N, Q;
const ll base[2] = {7, 11}, mod[2] = {1234567891, 1611495397};
ll p[2000005][2];

int JOI(char c)
{
    return (c == 'J' ? 1 : (c == 'O' ? 2 : 3));
}

pll operator+(pll p1, pll p2)
{
    return pll((p1.F + p2.F) % mod[0], (p1.S + p2.S) % mod[1]);
}

signed main()
{
    
    cin >> N;
    p[0][0] = p[0][1] = 1;
    for (int i = 1; i <= N; i++)
        p[i][0] = p[i - 1][0] * base[0] % mod[0],
        p[i][1] = p[i - 1][1] * base[1] % mod[1];

    string s;
    while (cin >> s)
    {
        pll h = pll(0, 0);
        for (int i = 0; i < N; i++)
            h = h + pll(JOI(s[i]) * p[i + 1][0], JOI(s[i]) * p[i + 1][1]);
        cout << h.F << ' ' << h.S << '\n';
    }
}

/*
JJJOJJIOOOIOOJIIIJIIOJJOOII
JJOJJIJOOIOOJOIIJIIOIOIJIOJ
JOJJIJJOIOOJOOIJIIOIIIOIJJO
*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

vector<string> v(3);

void prod()
{
    int old;
    for (int t = 1; t <= 4; t++)
    {
        old = v.size();
        for (int i = 0; i < old; i++)
            for (int j = 0; j < old; j++)
            {
                string t;
                for (int k = 0; k < v[i].size(); k++)
                {
                    if (v[i][k] == v[j][k])
                        t.push_back(v[i][k]);
                    else
                    {
                        if (v[i][k] != 'J' && v[j][k] != 'J')
                            t.push_back('J');
                        if (v[i][k] != 'O' && v[j][k] != 'O')
                            t.push_back('O');
                        if (v[i][k] != 'I' && v[j][k] != 'I')
                            t.push_back('I');
                    }
                }
                v.emplace_back(t);
            }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
    }
}

int N, Q;
const ll base[2] = {7, 11}, mod[2] = {1234567891, 1611495397};
ll p[2000005][2];

pll operator+(pll p1, pll p2)
{
    return pll((p1.F + p2.F) % mod[0], (p1.S + p2.S) % mod[1]);
}

struct sumSeg
{
    pll seg[800005];
    int lazy[800005];

    pll getval(int i, int L, int R)
    {
        if (lazy[i])
            return pll((p[R][0] - p[L - 1][0] + mod[0]) * lazy[i] % mod[0],
                       (p[R][1] - p[L - 1][1] + mod[1]) * lazy[i] % mod[1]);
        else
            return seg[i];
    }

    void modify(int mL, int mR, int val, int i = 1, int L = 1, int R = N)
    {

        if (R < mL || mR < L)
            return;
        else if (mL <= L && R <= mR)
        {
            lazy[i] = val;
        }
        else
        {
            int mid = (L + R) / 2;
            if (lazy[i])
                lazy[i << 1] = lazy[i << 1 | 1] = lazy[i];
            lazy[i] = 0;
            modify(mL, mR, val, i << 1, L, mid);
            modify(mL, mR, val, i << 1 | 1, mid + 1, R);
            seg[i] = getval(i << 1, L, mid) + getval(i << 1 | 1, mid + 1, R);
        }
    }
} seg;

int JOI(char c)
{
    return (c == 'J' ? 1 : (c == 'O' ? 2 : 3));
}

map<pll, bool> mp;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    p[0][0] = p[0][1] = 1;
    for (int i = 1; i <= N; i++)
        p[i][0] = p[i - 1][0] * base[0] % mod[0],
        p[i][1] = p[i - 1][1] * base[1] % mod[1];

    cin >> v[0] >> v[1] >> v[2];
    prod();
    for (string s : v)
    {
        pll h = pll(0, 0);
        for (int i = 0; i < N; i++)
            h = h + pll(JOI(s[i]) * p[i + 1][0], JOI(s[i]) * p[i + 1][1]);
        mp[h] = 1;
    }

    for (int i = 1; i <= N; i++)
        p[i][0] = (p[i - 1][0] + p[i][0]) % mod[0],
        p[i][1] = (p[i - 1][1] + p[i][1]) % mod[1];

    cin >> Q;

    string s;
    cin >> s;
    for (int i = 0; i < N; i++)
        seg.modify(i + 1, i + 1, JOI(s[i]));

    cout << ((mp.count(seg.getval(1, 1, N))) ? "Yes\n" : "No\n");

    for (int i = 1; i <= Q; i++)
    {
        int L, R;
        char c;
        cin >> L >> R >> c;
        seg.modify(L, R, JOI(c));
        cout << ((mp.count(seg.getval(1, 1, N))) ? "Yes\n" : "No\n");
    }
}

/*
JJJOJJIOOOIOOJIIIJIIOJJOOII
JJOJJIJOOIOOJOIIJIIOIOIJIOJ
JOJJIJJOIOOJOOIJIIOIIIOIJJO
*/
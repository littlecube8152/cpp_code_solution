#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int C = 60;
int v, q;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
vector<int> p;
// #define testing

void shuf(int l, int r)
{
    q++;
    assert(q <= 50000);
#ifndef testing
    cout << "# " << l << " " << r << endl;
    cin >> v;
#else
    shuffle(p.begin() + l, p.begin() + r + 1, rd);
#endif
}

int ask(int i)
{

    q++;
    assert(q <= 50000);
#ifndef testing
    cout << "? " << i << endl;
    cin >> v;
    return v;
#else
    vector<int> r;
    for (int j = 1; j <= 100; j++)
        r.emplace_back(abs(p[j] - j));
    sort(r.begin(), r.end());
    return r[i - 1];
#endif
}

void check()
{
    q++;
    assert(q <= 50000);
#ifndef testing
    cout << "!" << endl;
#else
    if (is_sorted(p.begin(), p.end()))
        cout << "Accepted: " << q << '\n';
    else
        cout << "Wrong Answer\n";
#endif
}

void test(int i)
{
#ifdef testing
    cout << i << ' ' << p[i] << " @ q =" << q << '\n';
#endif
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef testing
    p.resize(101);
    for (int i = 0; i <= 100; i++)
        p[i] = i;
#endif

    for (int i = 1; i <= 95; i++)
    {
        bool done = 0;
        while (!done)
        {
            done = 1;
            shuf(i, 100);
            for (int j = 0; j < C; j++)
            {
                shuf(i + 1, 100);
                if (ask(i))
                {
                    done = 0;
                    break;
                }
            }
        }
        test(i);
    }
    bool done = 0;
    while (!done)
    {
        shuf(96, 100);
        if (ask(100) == 0)
            done = 1;
    }
    check();
}
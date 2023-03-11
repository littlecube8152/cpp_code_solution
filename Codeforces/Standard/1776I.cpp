#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int n;
pll p[105];
set<pair<int, pll>> st;

pll operator-(pll p1, pll p2)
{
    return pll(p1.F - p2.F, p1.S - p2.S);
}
ll cross(pll p1, pll p2)
{
    return p1.F * p2.S - p1.S * p2.F;
}

void read()
{
    int k;
    cin >> k;
    st.erase(make_pair(k, p[k]));
}

void operate()
{
    int i = 0;
    ll area = 1e18;
    for (auto iter = st.begin(); iter != st.end(); ++iter)
    {
        auto jter = iter;
        int j;
        pll p1 = jter->S;
        ++jter;
        if (jter == st.end())
            jter = st.begin();
        pll p2 = jter->S;
        j = jter->F;
        ++jter;
        if (jter == st.end())
            jter = st.begin();
        pll p3 = jter->S;
        ll A = abs(cross(p1, p2) + cross(p2, p3) + cross(p3, p1));
        if (A <= area)
            area = A, i = j;
    }
    st.erase(make_pair(i, p[i]));
    cout << i << endl;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].F >> p[i].S;
        st.insert(make_pair(i, p[i]));
    }

    cout << (n % 2 == 0 ? "Alberto\n" : "Beatrice\n") << flush;
    while (n >= 3)
    {
        if (n % 2 == 1)
            read();
        else
            operate();
        n--;
    }
}
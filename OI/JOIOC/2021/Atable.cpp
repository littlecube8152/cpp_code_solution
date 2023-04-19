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
    for (int t = 1; t <= 3; t++)
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
    for (auto s : v)
        cout << s << '\n';
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> v[0] >> v[1] >> v[2];
    prod();
}

/*
JJJOJJIOOOIOOJIIIJIIOJJOOII
JJOJJIJOOIOOJOIIJIIOIOIJIOJ
JOJJIJJOIOOJOOIJIIOIIIOIJJO
*/
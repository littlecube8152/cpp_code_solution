#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

int N;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cout << i - 1 << " \n"[i == N];
}

/*
JJJOJJIOOOIOOJIIIJIIOJJOOII
JJOJJIJOOIOOJOIIJIIOIOIJIOJ
JOJJIJJOIOOJOOIJIIOIIIOIJJO
*/